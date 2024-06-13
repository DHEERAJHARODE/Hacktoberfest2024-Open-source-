import { Collapse } from "reactstrap";
import { useCallback, useEffect, useState } from "react";
import { RiArrowRightSFill, RiArrowDownSFill } from "react-icons/ri";
import Button from "../Button";
import Days from "../Days";

export default function ToDoList({ days, week, taskType }) {
  // const [dropDown, setDropDown] = useState(false);
  // const [week, setWeek] = useState(false);
  // const [day, setDay] = useState(false);
  const [tasks, setTasks] = useState(false);
  // const hanldleOpenTask = useCallback(()=>{
  //     setTasks(false)
  // }, [taskType])

  useEffect(() => {
    setTasks(false);
  }, [taskType]);
  // console.log(week);
  return (
    <>
      <div className="row week">
        <div className=" justify-content-between d-flex align-items-center ">
          <div className="d-flex align-items-center">
            <div className="collapse-btn">
              <Button onClick={() => setTasks(!tasks)}>
                {tasks ? (
                  <RiArrowDownSFill
                    className="me-1"
                    color="#b4c1f6"
                    size="24px"
                  />
                ) : (
                  <RiArrowRightSFill
                    className="me-1"
                    color="#b4c1f6"
                    size="24px"
                  />
                )}
              </Button>
            </div>
            <div className="m-0 g-0 p-0">
              <h5 className="m-0 p-0" style={{ color: "#b4c1f6" }}>
                Week
                <span>
                  {week}({Object.keys(days).length})
                </span>
              </h5>
            </div>
          </div>
        </div>
      </div>

      <Collapse isOpen={tasks} delay={{ show: 500, hide: 0 }}>
        {/* <Days/> */}
        {days
          ? Object.entries(days).map((item, key) => (
              <Days
                taskType={taskType}
                key={key}
                week={week}
                day={item[0]}
                tasks={item[1]}
              />
            ))
          : ""}
      </Collapse>
    </>
  );
}
