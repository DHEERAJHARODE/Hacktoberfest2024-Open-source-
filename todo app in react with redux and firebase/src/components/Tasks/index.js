import { useEffect, useState } from "react";
import {
  Modal,
  ModalHeader,
  ModalBody,
  ModalFooter,
  Dropdown,
  DropdownToggle,
  DropdownMenu,
  DropdownItem,
} from "reactstrap";

import { useDispatch, useSelector } from "react-redux";
import { useParams } from "react-router-dom";
import { useForm } from "react-hook-form";

import { FiMoreHorizontal, FiEdit2 } from "react-icons/fi";
import { BiTask, BiCategoryAlt } from "react-icons/bi";
import { TiTickOutline } from "react-icons/ti";
import { CgSandClock } from "react-icons/cg";
import { BsXCircle, BsPlayFill } from "react-icons/bs";
import { FiDelete } from "react-icons/fi";
import Avatar from "react-avatar";

import { getToDos } from "../../store/Actions";
import { set, ref, db, remove } from "../../config";
import Spinner from "../Spinner";
import Button from "../Button";
import "./style.css";

export default function Tasks({ taskType, id, task, week, day }) {
  const [dropDown, setDropDown] = useState();
  const colors = [
    "linear-gradient(115deg, rgba(116,136,248,1) 47%, rgba(222,222,222,0.9308765742625175) 100%)",
    "linear-gradient(129deg, rgba(34,193,195,1) 0%, rgba(253,187,45,1) 100%)",
    "linear-gradient(176deg, rgba(131,58,180,1) 0%, rgba(253,29,29,1) 50%, rgba(252,176,69,1) 100%)",
  ];
  const { register, handleSubmit, reset, formState } = useForm();
  const user = useSelector((state) => state.user);
  const [progress, setProgress] = useState(false);
  const [loading, setLoading] = useState(false);
  const [timeOn, setTimeOn] = useState(false);
  const [edit, setEdit] = useState(false);
  const [done, setDone] = useState(false);
  const [del, setDel] = useState(false);
  const [time, setTime] = useState(0);

  const dispatch = useDispatch();
  const params = useParams();

  const openDel = () => setDel(!del);
  const openProgress = () => setProgress(!progress);
  const openEdit = () => {
    setEdit(!edit);
    reset();
  };

  const openDone = () => setDone(!done);

  const saveToDo = async (assignmentType, title, category, time) => {
    const value = {
      title,
      category,
      date: task.date,
      time: task?.time ? task.time : 0,
    };
    await set(
      ref(db, `todos/${params.uid}/${assignmentType}/${week}/${day}/${id}`),
      value
    )
      .then(() => {
        console.log("data updated");
        dispatch(getToDos(params.uid));
      })
      .catch((err) => console.log(err));
  };

  const removeToDo = async (assignmentType) => {
    await remove(
      ref(db, `todos/${params.uid}/${assignmentType}/${week}/${day}/${id}`)
    )
      .then(() => {
        dispatch(getToDos(params.uid));
        setLoading(false);
        setDel(false);
      })
      .catch((err) => console.log(err));
  };

  const addToDo = (assignmentType, title, category, setModal) => {
    setLoading(true);
    saveToDo(assignmentType, title, category);
    setLoading(false);
    reset();
    setModal(false);
  };

  const deleteToDo = async (assignmentType) => {
    setLoading(true);
    removeToDo(assignmentType);
    setLoading(false);
    openDel();
  };

  const shiftFromBacklog = (
    oldAssignment,
    assignmentType,
    title,
    category,
    time
  ) => {
    setLoading(true);
    saveToDo(assignmentType, title, category, time);
    removeToDo(oldAssignment);
    setLoading(false);
    if (assignmentType == "progress") {
      openProgress();
    } else if (assignmentType == "done") {
      openDone();
    }
  };

  const timerOptions = () => {
    switch (taskType) {
      case "progress":
        return (
          <>
            <Button onClick={openProgress} style="progress-btn">
              <BsPlayFill fontSize={32} color="#57df7d" />
            </Button>
            <span>
              {("0" + Math.floor((time / (1000 * 60 * 60)) % 24)).slice(-2)}:
            </span>
            <span>
              {("0" + Math.floor((time / (1000 * 60)) % 60)).slice(-2)}:
            </span>
            <span>{("0" + Math.floor((time / 1000) % 60)).slice(-2)}</span>
          </>
        );
      default:
        return;
    }
  };

  useEffect(() => {
    setTime(task.time);
  }, []);

  useEffect(() => {
    let interval = null;
    if (timeOn) {
      interval = setInterval(() => {
        setTime((prevTime) => prevTime + 1000);
      }, 1000);
    } else {
      clearInterval(interval);
    }
    return () => clearInterval(interval);
  }, [timeOn]);

  console.log(task);

  return (
    <>
      <div className="row mx-2 task">
        <div className="col task-border py-3 px-2 d-flex justify-content-between">
          <div className="d-flex align-items-center m-0 p-0">
            <span className="custom-badge">{task.category}</span>
            <p className="m-0 text-secondary text-start">
              {`${task.title}`}
              <br />
              {`${task.date}`}
            </p>
          </div>
          <div className="d-flex align-items-center">{timerOptions()}</div>
          <div className="d-flex align-items-center">
            <div className="dropdown-btn">
              <Dropdown isOpen={dropDown} toggle={() => setDropDown(!dropDown)}>
                <DropdownToggle
                  caret={false}
                  cssModule={{ backgroundColor: "none" }}
                >
                  <div className="dropdown-icon">
                    <FiMoreHorizontal />
                  </div>
                </DropdownToggle>
                <DropdownMenu end>
                  {taskType != "done" && (
                    <DropdownItem className="" onClick={openEdit}>
                      <div className="d-flex justify-content-between">
                        Edit
                        <FiEdit2 />
                      </div>
                    </DropdownItem>
                  )}

                  {taskType != "progress" && (
                    <DropdownItem onClick={openProgress}>
                      <div className="d-flex justify-content-between">
                        InProgress
                        <CgSandClock style={{ flex: 0.5 }} />
                      </div>
                    </DropdownItem>
                  )}
                  {taskType != "done" && (
                    <>
                      <DropdownItem className="" onClick={openDone}>
                        <div className="d-flex justify-content-between align-items-center">
                          Mark as <br /> Done
                          <TiTickOutline fontSize={18} />
                        </div>
                      </DropdownItem>
                      <DropdownItem className="" onClick={openDel}>
                        <div className="d-flex justify-content-between">
                          Delete
                          <FiDelete />
                        </div>
                      </DropdownItem>
                    </>
                  )}
                </DropdownMenu>
              </Dropdown>
            </div>
            <div className="d-flex align-items-center">
              <Avatar
                size="36px"
                round={true}
                color={colors[Math.floor(Math.random() * 3)]}
                name={user.name}
              />
            </div>
          </div>
        </div>
      </div>
      <Modal centered isOpen={edit} toggle={openEdit}>
        <ModalHeader>Edit</ModalHeader>
        <form
          onSubmit={handleSubmit((data) => {
            addToDo(taskType, data.title, data.category, openEdit);
          })}
        >
          <ModalBody>
            <div style={{ margin: "10px auto" }}>
              <div
                className="field"
                style={{
                  border: formState.errors?.title?.message
                    ? "1px solid red"
                    : "1px solid #adadad",
                }}
              >
                <label style={{ paddingBottom: "10px" }}>
                  <BiTask size="24px" color="#adadad" />
                </label>
                <input
                  type="text"
                  placeholder={task.title}
                  defaultValue={task.title}
                  {...register("title", {
                    required: {
                      value: true,
                      message: "Please Enter Title",
                    },
                    minLength: {
                      value: 10,
                      message: "Atleast ten characters are required",
                    },
                    maxLength: {
                      value: 20,
                      message: "Total Limit Exceeded",
                    },
                  })}
                />
              </div>
              {formState.errors.title ? (
                <div style={{ margin: "auto 9%", color: "red", fontSize: 14 }}>
                  <p>
                    <small>{formState.errors.title.message}</small>
                  </p>
                </div>
              ) : (
                ""
              )}
            </div>
            <div style={{ margin: "10px auto" }}>
              <div
                className="field"
                style={{
                  border: formState.errors?.category?.message
                    ? "1px solid red"
                    : "1px solid #adadad",
                }}
              >
                <label style={{ paddingBottom: "10px" }}>
                  <BiCategoryAlt size="24px" color="#adadad" />
                </label>
                <input
                  type="text"
                  placeholder={task.category}
                  defaultValue={task.category}
                  {...register("category", {
                    required: {
                      value: true,
                      message: "Please Enter Category",
                    },
                    minLength: {
                      value: 3,
                      message: "must enter three characters",
                    },
                    maxLength: {
                      value: 5,
                      message: "Total Limit Exceeded",
                    },
                  })}
                />
              </div>
              {formState.errors.category ? (
                <div style={{ margin: "auto 9%", color: "red", fontSize: 14 }}>
                  <p>
                    <small>{formState.errors.category.message}</small>
                  </p>
                </div>
              ) : (
                ""
              )}
            </div>
          </ModalBody>
          <ModalFooter>
            <Button
              style="modal-submit-btn"
              text={loading ? <Spinner /> : "Submit"}
              type="submit"
            />
            <Button
              style="modal-close-btn"
              text="Close"
              onClick={openEdit}
              type="reset"
            />
          </ModalFooter>
        </form>
      </Modal>
      <Modal centered isOpen={del} toggle={openDel}>
        <ModalBody>
          <div>
            <h2
              style={{ color: "#7488f8" }}
              className="text-center fw-light my-4"
            >
              <BsXCircle className="my-2" fontSize={45} />
              <br />
              Are you sure?
            </h2>
            <p className="text-center" style={{ color: "#adadad" }}>
              Do you really want to delete this record? This process cannot be
              undone.
            </p>
          </div>
        </ModalBody>
        <ModalFooter>
          <div className="d-flex justify-content-end">
            <div className="mx-2">
              <Button
                onClick={() => {
                  deleteToDo(taskType);
                }}
                style="modal-close-btn"
              >
                {loading ? <Spinner /> : "Delete"}
              </Button>
            </div>
            <div className="mx-2">
              <Button onClick={() => setDel(!del)} style="modal-close-btn">
                Close
              </Button>
            </div>
          </div>
        </ModalFooter>
      </Modal>
      <Modal centered isOpen={progress} toggle={openProgress}>
        <ModalBody>
          <div>
            <h2
              style={{ color: "#7488f8" }}
              className="text-center fw-light my-4"
            >
              <CgSandClock className="my-2" fontSize={45} />
              <br />
              Mark as In Progress?
            </h2>
            <p className="text-center" style={{ color: "#adadad" }}>
              By clicking ok, this task will be moved to progress section.
            </p>
          </div>
        </ModalBody>
        <ModalFooter>
          <div className="d-flex justify-content-end">
            <div className="mx-2">
              <Button
                onClick={() => {
                  shiftFromBacklog(
                    taskType,
                    "progress",
                    task.title,
                    task.category,
                    0
                  );
                }}
                style="modal-close-btn"
              >
                {loading ? <Spinner /> : "Move to Progress"}
              </Button>
            </div>
            <div className="mx-2">
              <Button onClick={openProgress} style="modal-close-btn">
                Close
              </Button>
            </div>
          </div>
        </ModalFooter>
      </Modal>
      <Modal centered isOpen={done} toggle={openDone}>
        <ModalBody>
          <div>
            <h2
              style={{ color: "#7488f8" }}
              className="text-center fw-light my-4"
            >
              <TiTickOutline className="my-2" fontSize={45} />
              <br />
              Mark as Done?
            </h2>
            <p className="text-center" style={{ color: "#adadad" }}>
              By clicking ok, this task will be moved to completed section.
            </p>
          </div>
        </ModalBody>
        <ModalFooter>
          <div className="d-flex justify-content-end">
            <div className="mx-2">
              <Button
                onClick={() => {
                  shiftFromBacklog(
                    taskType,
                    "done",
                    task.title,
                    task.category,
                    undefined
                  );
                }}
                style="modal-close-btn"
              >
                {loading ? <Spinner /> : "Mark as Done"}
              </Button>
            </div>
            <div className="mx-2">
              <Button onClick={openDone} style="modal-close-btn">
                Close
              </Button>
            </div>
          </div>
        </ModalFooter>
      </Modal>
    </>
  );
}
