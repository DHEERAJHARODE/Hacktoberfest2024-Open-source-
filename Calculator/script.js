let input = document.getElementById("input");
let numButtons = document.querySelectorAll(".numButton");
let add = document.getElementById("add");
let sub = document.getElementById("sub");
let mul = document.getElementById("mul");
let div = document.getElementById("div");
let equal = document.getElementById("equal");
let clear = document.getElementById("clear");

let operation1 = null;
let operation2 = null;
let operator = null;

numButtons.forEach((digit) => {
    digit.addEventListener("click", digitButton);
});
add.addEventListener("click", () => setOperator("add"));
sub.addEventListener("click", () => setOperator("sub"));
mul.addEventListener("click", () => setOperator("mul"));
div.addEventListener("click", () => setOperator("div"));
equal.addEventListener("click", solution);
clear.addEventListener("click", clearInput);

function digitButton(event) {
    let value = event.target.value;
    input.value += value;

    if (!operator) {
        operation1 = parseInt(input.value);
    } else {
        operation2 = parseInt(input.value);
    }
}

function setOperator(op) {
    operator = op;
    input.value = "";
}

function solution() {
    let result;
    switch (operator) {
        case "add":
            result = operation1 + operation2;
            break;
        case "sub":
            result = operation1 - operation2;
            break;
        case "mul":
            result = operation1 * operation2;
            break;
        case "div":
            result = operation1 / operation2;
            break;
        default:
            result = "Error";
            break;
    }
    input.value = result;
    operation1 = result;
    operation2 = null;
    operator = null;
}

function clearInput() {
    input.value = "";
    operation1 = null;
    operation2 = null;
    operator = null;
}