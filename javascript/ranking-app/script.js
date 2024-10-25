document.getElementById('addStudentBtn').addEventListener('click', function () {
    const studentInputs = document.getElementById('studentInputs');
    
    const studentInputDiv = document.createElement('div');
    studentInputDiv.classList.add('student-input');
    
    studentInputDiv.innerHTML = `
        <input type="text" class="name" placeholder="Student Name" required>
        <input type="number" class="score" placeholder="Score" required>
        <button type="button" class="remove-student" onclick="removeStudent(this)">Remove</button>
    `;
    
    studentInputs.appendChild(studentInputDiv);
});

function removeStudent(element) {
    element.parentElement.remove();
}

document.getElementById('scoreForm').addEventListener('submit', function (e) {
    e.preventDefault();

    const nameInputs = document.querySelectorAll('.name');
    const scoreInputs = document.querySelectorAll('.score');
    
    let students = [];
    nameInputs.forEach((nameInput, index) => {
        const score = scoreInputs[index].value;
        students.push({ name: nameInput.value, score: Number(score) });
    });
    
    students.sort((a, b) => b.score - a.score);
    
    const ranking = document.getElementById('ranking');
    
     ranking.innerHTML = '';
    
     students.forEach((student, rank) => {
        let rankDiv = document.createElement('div');
        rankDiv.classList.add('rank-item');
        rankDiv.textContent = `Rank ${rank + 1}: ${student.name} - Score: ${student.score}`;
        ranking.appendChild(rankDiv);
    });
});
