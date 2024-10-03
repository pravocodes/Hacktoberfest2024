let button=document.querySelectorAll(".container button");
for(var i=0;i<button.length;i++){
    let text=button[i].innerText;
    button[i].addEventListener("click",function(){
    console.log(text);
    makeSound(text);
    animation(text);
    });
}
document.addEventListener("keypress",function(event){
    let key=event.key.toUpperCase()
    console.log(key);
   makeSound(key);
   animation(key);
});
function makeSound(text){
switch(text){
       case 'A':
        var audio=new Audio("sounds/crash.mp3");
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
function animation(currentkey){
    let activeButton = document.querySelector("." + currentkey+"drum");
            if (activeButton) {
                activeButton.classList.add("pressed");
                console.log(activeButton);
                setTimeout(() => {
                    activeButton.classList.remove("pressed");
                }, 100);
            } else {
                console.log("No element found with class: " + currentkey + "drum");
            }
        }