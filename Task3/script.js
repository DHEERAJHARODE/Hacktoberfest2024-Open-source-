function addTask() {
    const taskInput = document.getElementById("task");
    const taskText = taskInput.value.trim();
    if (taskText !== "") {
      const pendingTasksList = document.getElementById("pending-tasks");
      const newTask = document.createElement("li");
      newTask.textContent = taskText;
      newTask.addEventListener("click", markAsComplete);
      pendingTasksList.appendChild(newTask);
      taskInput.value = "";
    }
  }
  
  
  function markAsComplete() {
    const completedTasksList = document.getElementById("completed-tasks");
    completedTasksList.appendChild(this);
    this.removeEventListener("click", markAsComplete);
    this.addEventListener("click", markAsPending);
  }
  
 
  function markAsPending() {
    const pendingTasksList = document.getElementById("pending-tasks");
    pendingTasksList.appendChild(this);
    this.removeEventListener("click", markAsPending);
    this.addEventListener("click", markAsComplete);
  }
  
  
  function deleteTask() {
    this.remove();
  }
  