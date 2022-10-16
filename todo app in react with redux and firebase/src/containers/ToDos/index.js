import { useEffect, useState } from "react";
import { Modal, ModalHeader, ModalBody, ModalFooter } from "reactstrap";
import { useParams, useNavigate } from "react-router-dom";
import { useDispatch, useSelector } from "react-redux";
import { useForm } from "react-hook-form";

import { RiArrowDownSFill } from "react-icons/ri";
import { AiOutlineSearch } from "react-icons/ai";
import { IoMailOutline } from "react-icons/io5";
import { BiCategoryAlt } from "react-icons/bi";
import { BiTask } from "react-icons/bi";
import { BsPlus } from "react-icons/bs";

import {
  ResponsiveContainer,
  CartesianGrid,
  AreaChart,
  Tooltip,
  XAxis,
  YAxis,
  Area,
} from "recharts";


import { Button, Menu, Spinner, ToDoList } from "../../components";
import { db, ref, set, push, auth, signOut } from "../../config";
import { getToDos } from "../../store/Actions";
import { totalTasks } from "../../helpers";
import "./style.css";

export default function ToDos() {

  const moment = require("moment");
  const navigate = useNavigate();
  const dispatch = useDispatch();
  const {uid} = useParams();

  const { register, handleSubmit, formState, reset } = useForm();
  const [loading, setLoading] = useState(false);
  const [tab, setTab] = useState("progress");
  const [modal, setModal] = useState(false);

  useEffect(() => {
    dispatch(getToDos(uid));
  }, []);

  const openModal = () => {
    reset();
    setModal(!modal);
  };

  const addToDo = async (title, category, uid) => {
    let date = new Date();
    let week = moment(
      `${date.getMonth() + 1}-${date.getDate()}-${date.getFullYear()}`,
      "MM-DD-YYYY"
    ).week();

    const value = {
      title,
      category,
      date: `${date.getMonth() + 1}-${date.getDate()}-${date.getFullYear()}`,
    };

    setLoading(true);
    
    const postListRef = ref(
      db,
      `todos/${uid}/backlog/${week}/${date.getDay()}`
    );
    
    const newPostRef = push(postListRef);

    await set(newPostRef, value)
      .then(() => dispatch(getToDos(uid)))
      .catch((err) => console.log("data transmission failed"));

    setLoading(false);
    setModal(false);
  };

  const logout = () => {
    signOut(auth).then(() => {
      dispatch({ type: "NO_USER" });
      navigate("/login");
    });
  };
  
  const obj = useSelector((state) => state.tasks);
  return (
    <>
      <div className="container-fluid g-0">
        <div className="row g-0">
          <div className="col-1 ">
            <Menu>
              <div className="icons my-2">
                <Button style="btn-menu" text="Tasks" />
              </div>
            </Menu>
          </div>
          <div className="col-11 ">
            <div className="col-12">
              <div className="row m-0 py-3 bg-title-todos w-100 justify-content-between">
                <div className="d-flex col-6">
                  <div className="title-icons">
                    <IoMailOutline color="#adadad" fontSize="24px" />
                  </div>
                  <div className="title-icons">
                    <AiOutlineSearch color="#adadad" fontSize="24px" />
                  </div>
                </div>
                <div className="d-flex justify-content-end col-6">
                  <Button style={"logout-btn"} onClick={logout}>
                    Logout
                  </Button>
                </div>
              </div>
              <div className="d-flex justify-content-between mx-5 mt-4 header">
                <div>
                  <span
                    className={tab == "backlog" ? "active-tab" : ""}
                    onClick={() => {
                      setTab("backlog");
                    }}
                  >
                    Backlog(
                    {obj && obj?.backlog ? totalTasks(obj.backlog).length : "0"}
                    )
                  </span>
                  <span
                    className={tab == "progress" ? "active-tab" : ""}
                    onClick={() => {
                      setTab("progress");
                    }}
                  >
                    Progress(
                    {obj && obj?.progress
                      ? totalTasks(obj.progress).length
                      : "0"}
                    )
                  </span>
                  <span
                    className={tab == "done" ? "active-tab" : ""}
                    onClick={() => {
                      setTab("done");
                    }}
                  >
                    Done({obj && obj?.done ? totalTasks(obj.done).length : "0"})
                  </span>
                </div>
                <div>
                  <Button>
                    <BsPlus />
                  </Button>
                  <label className="px-3">add column</label>
                </div>
              </div>
              <div className="row m-0 mt-4">
                <div className="col-1 small-border">
                  <div className="text-center py-2 px-1">
                    <RiArrowDownSFill color="#adadad" size="24px" />
                  </div>
                  <div>
                    <p className="vertical-text">Backlog</p>
                  </div>
                </div>
                <div
                  className="col-5 border"
                  style={{ maxHeight: "366px", overflowY: "auto" }}
                >
                  <div className="row">
                    <div className=" justify-content-between d-flex align-items-center py-2">
                      <div className="d-flex">
                        <div className="m-0 g-0 p-0">
                          {obj && obj !== "No tasks found"
                            ? tab == "backlog" && obj.hasOwnProperty("backlog")
                              ? Object.entries(obj.backlog).map((item, key) => (
                                  <ToDoList
                                    taskType={tab}
                                    key={key}
                                    week={item[0]}
                                    days={item[1]}
                                  />
                                ))
                              : tab == "progress" &&
                                obj.hasOwnProperty("progress")
                              ? Object.entries(obj.progress).map(
                                  (item, key) => (
                                    <ToDoList
                                      taskType={tab}
                                      key={key}
                                      week={item[0]}
                                      days={item[1]}
                                    />
                                  )
                                )
                              : tab == "done" && obj?.done
                              ? Object.entries(obj.done).map((item, key) => (
                                  <ToDoList
                                    taskType={tab}
                                    key={key}
                                    week={item[0]}
                                    days={item[1]}
                                  />
                                ))
                              : ""
                            : ""}
                        </div>
                      </div>
                      <div className="add-task-btn">
                        <Button onClick={openModal}>
                          <BsPlus color="#adadad" />
                        </Button>
                      </div>
                    </div>
                  </div>
                </div>
                <div className="col-6">
                  <ResponsiveContainer width="100%" height="100%">
                    <AreaChart
                      width={500}
                      height={400}
                      data={obj && obj?.tab && totalTasks(obj.progress)}
                      margin={{
                        top: 10,
                        right: 30,
                        left: 0,
                        bottom: 0,
                      }}
                    >
                      <CartesianGrid strokeDasharray="3 3" />
                      <XAxis dataKey="title" />
                      <YAxis />
                      <Tooltip />
                      <Area
                        type="monotone"
                        dataKey="date"
                        stroke="#8884d8"
                        fill="#8884d8"
                      />
                    </AreaChart>
                  </ResponsiveContainer>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
      <Modal centered isOpen={modal} toggle={openModal}>
        <ModalHeader style={{ color: "#7488f8" }}>Add To Do</ModalHeader>
        <form
          onSubmit={handleSubmit((data) => {
            addToDo(data.title, data.category, uid);
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
                  placeholder="Enter Task Name"
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
                  placeholder="Enter Category"
                  {...register("category", {
                    required: {
                      value: true,
                      message: "Please Enter Category",
                    },
                    minLength: {
                      value: 3,
                      message: "Must enter three characters",
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
              onClick={openModal}
              type="reset"
            />
          </ModalFooter>
        </form>
      </Modal>
    </>
  );
}
