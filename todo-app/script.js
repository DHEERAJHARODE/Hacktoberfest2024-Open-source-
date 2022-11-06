const addBtn = document.querySelector("#add-task-btn");
const deleteBtn = document.querySelector("#delete-all-user-task-btn");
const input = document.querySelector("#input-todo");
const main = document.querySelector("main");

const markTaskAsComplete = (e) => {
  const taskId = e.target.dataset.taskid;
  const userTaskInput = document.querySelector(`input[data-taskid=${taskId}]`);
  if (userTaskInput) {
    userTaskInput.classList.toggle("strike");
  }
};

const editTask = (e) => {
  const taskId = e.target.dataset.taskid;
  const userTaskInput = document.querySelector(`input[data-taskid=${taskId}]`);
  if (userTaskInput) {
    userTaskInput.disabled = !userTaskInput.disabled;
    userTaskInput.focus();
    userTaskInput.select();
  }
};

const deleteSpecificTask = (e) => {
  const taskId = e.target.dataset.taskid;
  const userTaskSection = document.querySelector(
    `section[data-taskid=${taskId}]`
  );
  if (userTaskSection) {
    userTaskSection.remove();
  }
};

const generateTodoInput = (taskId, text) => {
  const inputBox = document.createElement("input");
  inputBox.setAttribute("type", "text");
  inputBox.setAttribute("disabled", true);
  inputBox.setAttribute("data-taskid", taskId);
  inputBox.value = text;

  return inputBox;
};

const getIconHTML = (iconClass) => `<i class="fa-solid ${iconClass}"></i>`;

const generateTodoHelperBtn = (
  iconclass,
  btnClass,
  taskId,
  toolTipText,
  eventHandler
) => {
  const btn = document.createElement("button");
  btn.innerHTML = getIconHTML(iconclass);
  btn.classList.add("btn", btnClass);
  btn.setAttribute("data-taskid", taskId);
  btn.setAttribute("title", toolTipText);
  btn.addEventListener("click", eventHandler);

  return btn;
};

const addTodo = (text) => {
  if (text !== "") {
    const taskId = `todo-${Date.now()}`;
    const section = document.createElement("section");
    section.classList.add("user-todo-section", "todo");
    section.setAttribute("data-taskid", taskId);

    const inputBox = generateTodoInput(taskId, text);

    const finishTaskBtn = generateTodoHelperBtn(
      `fa-circle-check`,
      `complete-task-btn`,
      taskId,
      `Mark Task as Completed`,
      markTaskAsComplete
    );
    const editTaskBtn = generateTodoHelperBtn(
      `fa-pen-to-square`,
      `edit-task-btn`,
      taskId,
      `Edit Task`,
      editTask
    );
    const deleteTaskBtn = generateTodoHelperBtn(
      `fa-trash-can`,
      `delete-task-btn`,
      taskId,
      `Delete Task`,
      deleteSpecificTask
    );

    section.append(inputBox);
    section.append(finishTaskBtn);
    section.append(editTaskBtn);
    section.append(deleteTaskBtn);
    main.append(section);
  }
};

const addTask = () => {
  addTodo(input.value);
  input.value = "";
};

const deleteAllUserTasks = () => {
  const userTodos = document.querySelectorAll(".user-todo-section");
  userTodos.forEach((todo) => todo.remove());
};

const init = () => {
  addBtn.addEventListener("click", addTask);
  deleteBtn.addEventListener("click", deleteAllUserTasks);
};

window.addEventListener("load", init);
