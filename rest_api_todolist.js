// pages/api/todos.js
import todos from "../../data";

export default function handler(req, res) {
  if (req.method === "GET") {
    // Return all Todos
    res.status(200).json(todos);
  } else if (req.method === "POST") {
    // Create a new Todo
    const newTodo = {
      id: Date.now(),
      text: req.body.text,
      completed: false,
    };
    todos.push(newTodo);
    res.status(201).json(newTodo);
  } else if (req.method === "PUT") {
    // Update a Todo
    const { id, text, completed } = req.body;
    const todoIndex = todos.findIndex((todo) => todo.id === id);
    if (todoIndex !== -1) {
      todos[todoIndex] = { id, text, completed };
      res.status(200).json(todos[todoIndex]);
    } else {
      res.status(404).json({ message: "Todo not found" });
    }
  } else if (req.method === "DELETE") {
    // Delete a Todo
    const id = parseInt(req.query.id, 10);
    const todoIndex = todos.findIndex((todo) => todo.id === id);
    if (todoIndex !== -1) {
      const deletedTodo = todos.splice(todoIndex, 1);
      res.status(200).json(deletedTodo[0]);
    } else {
      res.status(404).json({ message: "Todo not found" });
    }
  }
}
