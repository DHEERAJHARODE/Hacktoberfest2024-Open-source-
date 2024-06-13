import { RiArrowDownSFill, RiArrowRightSFill } from "react-icons/ri";
import Button from "../Button";
import { useEffect, useState } from "react";
import { Collapse } from "reactstrap";
import Tasks from "../Tasks";
export default function Days({ taskType, day, tasks, week }) {
  const [days, showDays] = useState(false);
  const weekDays = [
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
  ];
  useEffect(() => {
    showDays(false);
  }, [taskType]);
  return (
    <div className="row day">
      <div className=" justify-content-between d-flex align-items-center ">
        <div className="d-flex align-items-center">
          <div className="collapse-btn">
            <Button style="ps-2" onClick={() => showDays(!days)}>
              {days ? (
                <RiArrowDownSFill
                  className="me-1"
                  color="#adadad"
                  size="24px"
                />
              ) : (
                <RiArrowRightSFill
                  className="me-1"
                  color="#adadad"
                  size="24px"
                />
              )}
            </Button>
          </div>
          <div className="m-0 g-0 p-0">
            <h6 className="m-0 p-0" style={{ color: "#adadad" }}>
              {weekDays[day]} <span>({Object.keys(tasks).length})</span>
            </h6>
          </div>
        </div>
      </div>
      <Collapse isOpen={days}>
        {tasks
          ? Object.entries(tasks).map((item, key) => (
              <Tasks
                taskType={taskType}
                key={key}
                week={week}
                day={day}
                id={item[0]}
                task={item[1]}
              />
            ))
          : ""}
      </Collapse>
    </div>
  );
}
