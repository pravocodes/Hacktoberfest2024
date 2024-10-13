let todos = [];
const inputField = document.getElementById("input");
const messageDiv = document.getElementById("message");
const mainList = document.querySelector(".mainList");
const toggleDarkModeBtn = document.getElementById("toggleDarkMode");

function addTodo() {
    const todoText = inputField.value.trim();
    
    if (!todoText) {
        return showMessage("Please enter a task!", "red");
    }

    todos.push({ title: todoText, completed: false });
    inputField.value = "";
    showMessage(`Todo #${todos.length} Added!`, "green");
    render();
}

function showMessage(message, color) {
    messageDiv.textContent = message;
    messageDiv.style.color = color;
    
    setTimeout(() => messageDiv.textContent = "", 500);
}

inputField.addEventListener("keypress", (event) => {
    if (event.key === "Enter") addTodo();
});

function deleteTodo(index) {
    todos.splice(index, 1);
    render();
}

function clearTodo() {
    todos = [];
    render();
    showMessage("Todo List Cleared!", "red");
}

function toggleComplete(index) {
    todos[index].completed = !todos[index].completed;
    render();
}

function render() {
    mainList.innerHTML = "";

    todos.forEach((todo, index) => {
        const todoItem = document.createElement("div");
        todoItem.className = "todo-item";

        const checkbox = document.createElement("input");
        checkbox.type = "checkbox";
        checkbox.className = "checkbox";
        checkbox.checked = todo.completed;
        checkbox.addEventListener("change", () => toggleComplete(index));

        const todoSpan = document.createElement("span");
        todoSpan.className = `todo-span ${todo.completed ? "completed" : ""}`;
        todoSpan.textContent = todo.title;

        const deleteBtn = document.createElement("button");
        deleteBtn.className = "delete-btn";
        deleteBtn.textContent = "❌";
        deleteBtn.onclick = () => deleteTodo(index);

        todoItem.appendChild(checkbox);
        todoItem.appendChild(todoSpan);
        todoItem.appendChild(deleteBtn);
        mainList.appendChild(todoItem);
    });
}

toggleDarkModeBtn.addEventListener("click", () => {
    document.body.classList.toggle("dark-mode");
    const isDarkMode = document.body.classList.contains("dark-mode");
    toggleDarkModeBtn.textContent = isDarkMode ? "🌞" : "🌙";
});

render();
