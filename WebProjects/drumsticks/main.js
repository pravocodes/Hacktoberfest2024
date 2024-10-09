let buttons = document.querySelectorAll(".drum-button");

for (let i = 0; i < buttons.length; i++) {
    let text = buttons[i].innerText;
    buttons[i].addEventListener("click", function () {
        makeSound(text);
        applyAnimation(text);
    });
}

document.addEventListener("keypress", function (event) {
    let key = event.key.toUpperCase();
    makeSound(key);
    applyAnimation(key);
});

function makeSound(text) {
    switch (text) {
        case 'A':
            var audio = new Audio("sounds/crash.mp3");
            audio.play();
            break;
        case 'W':
            var audio = new Audio("sounds/snare.mp3");
            audio.play();
            break;
        case 'S':
            var audio = new Audio("sounds/tom-1.mp3");
            audio.play();
            break;
        case 'D':
            var audio = new Audio("sounds/tom-2.mp3");
            audio.play();
            break;
        case 'J':
            var audio = new Audio("sounds/tom-3.mp3");
            audio.play();
            break;
        case 'K':
            var audio = new Audio("sounds/tom-4.mp3");
            audio.play();
            break;
        case 'L':
            var audio = new Audio("sounds/kick-bass.mp3");
            audio.play();
            break;
        default:
            console.log("No audio file for this button");
    }
}

function applyAnimation(currentKey) {
    let activeButton = document.querySelector("." + currentKey);
    if (activeButton) {
        activeButton.classList.add("pressed");
        setTimeout(() => {
            activeButton.classList.remove("pressed");
        }, 100); // Removes the class after 100ms to simulate hover effect
    } else {
        console.log("No element found with class: " + currentKey);
    }
}
