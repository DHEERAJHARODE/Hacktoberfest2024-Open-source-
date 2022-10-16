export const totalTasks = (obj) => {
  let task = [];
  let temp = Object.values(obj);
  temp.forEach((item) => {
    Object.values(item).forEach((item2) => {
      Object.values(item2).forEach((item3) => {
          task.push(item3);
      });
    });
  });
  return task;
};
