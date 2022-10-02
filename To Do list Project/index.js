const port = 3000;
require('dotenv').config();
const myURI = process.env.MONGO_URI;

const express = require("express");
const bodyParser = require("body-parser");
const ejs = require("ejs");
const mongoose = require("mongoose");

const app = express();
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static("public"));

mongoose.connect(myURI);
const taskSchema = {
name: {
	type: String,
	required: true
}
};

const Task = mongoose.model("Task", taskSchema);

app.set("view engine", "ejs");

app.get("/", function (req, res) {

let today = new Date();
let options = { weekday: "long", day: "numeric", month: "long" };
let day = today.toLocaleDateString("en-US", options);

Task.find({}, function(err, foundTasks){
	if (err){
	console.log(err)
	}
	else {
	res.render("index", { today: day, tasks: foundTasks });
	}
})

});

app.post("/", function (req, res) {
const taskName = req.body.newTask;
if(taskName){
	const task = new Task({
	name: taskName,
	});
	task.save().then(()=>{
	res.redirect("/");
	});
} else{
	res.redirect("/");
	
}
});

app.post("/delete", function (req, res) {
const checkedItemId = req.body.checkbox;
Task.findByIdAndRemove(checkedItemId, function (err) {
	if (!err) {
	console.log("Successfully deleted checked item.");
	res.redirect("/");
	}
});
});

app.listen(process.env.PORT || 3000, function () {
console.log("Server running at port 3000");
});
