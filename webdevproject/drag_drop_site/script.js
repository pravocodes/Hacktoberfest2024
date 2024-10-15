function allowDrop(ev) {
  ev.preventDefault();
}





let x,y;
let dragimage;
let swipable = false;
var text = document.getElementById("text");
var dropTargetRect = text.getBoundingClientRect();





function dragOver(ev) {
  // for(let ii = 0; ii<text.offsetHeight-1; ii=ii+dragimage.offsetHeight){
  //   if(ev.clientY-dropTargetRect.y>ii && ev.clientY - dropTargetRect.y<ii+dragimage.offsetHeight){
  //     tag_line.style.height = dragimage.offsetHeight + "px";
  //     if(((ii+dropTargetRect.y)+dragimage.offsetHeight) > text.offsetHeight + dropTargetRect.y){
  //       tag_line.style.top = text.offsetHeight + dropTargetRect.y - dragimage.offsetHeight + "px";
  //     }else{
  //       tag_line.style.top = ii+dropTargetRect.y+"px";
  //     }
  //     tag_line.style.width = text.offsetWidth + "px";
  //     tag_line.style.left = dropTargetRect.x+"px";
  //   }
  // }
  // const textdivs = text.getElementsByTagName('div');
  // for (let i = 0; i < textdivs.length; i++) {
  //   const div = textdivs[i];
  //   if (div !== dragimage) {
  //     const rect = div.getBoundingClientRect();
  //     const dragRect = dragimage.getBoundingClientRect();
      
  //     const overlapX = (ev.clientX > rect.left && ev.clientX < rect.right) || (ev.clientX + dragRect.width > rect.left && ev.clientX + dragRect.width < rect.right);
  //     const overlapY = (ev.clientY > rect.top && ev.clientY < rect.bottom) || (ev.clientY + dragRect.height > rect.top && ev.clientY + dragRect.height < rect.bottom);
  //     // const overlapX = adjustedX + dragimage.offsetWidth + dropTargetRect.x > rect.left && adjustedX + dropTargetRect.x < rect.left + div.offsetWidth;
  //     // const overlapY = adjustedY + dragimage.offsetHeight + dropTargetRect.y > rect.top && adjustedY + dropTargetRect.y < rect.top + div.offsetHeight;

  //     if (overlapX && overlapY) {
  //       console.log("collide");
  //       const direction = ev.clientX < rect.left + rect.width / 2 ? -1 : 1;
  //       div.style.transition = "left 0.3s";
  //       let newLeft = parseInt(div.style.left, 10) + direction * dragimage.offsetWidth;

  //       // Check for collision with text div boundaries
  //       newLeft = Math.max(0, Math.min(newLeft, text.offsetWidth - dragimage.offsetWidth));

  //       // Move the div without exceeding boundaries
  //       div.style.left = `${newLeft}px`;
  //     }
  //   }
  // }
}
document.addEventListener('dragover', dragOver);





function drag(ev) {
  ev.dataTransfer.setDragImage(ev.target, ev.target.offsetWidth / 2, ev.target.offsetHeight / 2);
  const textdivs = text.getElementsByTagName('div');
  dragimage = ev.target;
  if(textdivs.length !=0 ){
    for(let l = 0; l< textdivs.length; l++){
      if(textdivs[l].id != ev.target.id){
        textdivs[l].style.zIndex = -100;
      }else{
        textdivs[l].style.zIndex = 100;
      }
    }
  }
  ev.dataTransfer.setData("text", ev.target.id);
  const image = ev.target;
  const imageRect = image.getBoundingClientRect();
}



function removepx(value){
  return parseInt(value.slice(0, -2), 10);
}



function drop(ev) {
  ev.preventDefault();

  // Calculate the adjusted position
  var adjustedX = ev.clientX - (dragimage.offsetWidth/2) - dropTargetRect.x;
  const textdivs = text.getElementsByTagName('div');
  var adjustedY = ev.clientY - (dragimage.offsetHeight/2) - dropTargetRect.y;

  // Check if the image is within the text div
  if(adjustedX < 0 || adjustedY < 0 || adjustedX + dragimage.offsetWidth > dropTargetRect.width || adjustedY + dragimage.offsetHeight > dropTargetRect.height){
    if(adjustedX < 0){
      adjustedX = 0;
    }
    if(adjustedX + dragimage.offsetWidth > dropTargetRect.width){
      adjustedX = dropTargetRect.width - dragimage.offsetWidth;
    }
    if(adjustedY < 0){
      adjustedY = 0;
    }
    if(adjustedY + dragimage.offsetHeight > dropTargetRect.height){
      adjustedY = dropTargetRect.height - dragimage.offsetHeight;
    }
  }

  let count = 0;
  for(let ii =0; ii<textdivs.length ; ii++){
    if(textdivs[ii].className != dragimage.id){
      count++;
    }
  }

  // Create a copy of the dragged element
  if (dragimage.parentElement.id === "text") {
    dragimage.style.left = adjustedX + "px";
    dragimage.style.top = adjustedY + "px";
  }else{
    const clonedElement = dragimage.cloneNode(true);
    text.appendChild(clonedElement);
    clonedElement.style.position = "absolute";
    clonedElement.className = dragimage.id + "_"+count;
    clonedElement.style.width = dragimage.offsetWidth + "px";
    clonedElement.style.height = dragimage.offsetHeight + "px";
    clonedElement.style.left = adjustedX + "px";
    clonedElement.style.top = adjustedY + "px";
  }


  if(textdivs.length !=0 ){
    for(let l = 0; l< textdivs.length; l++){
      textdivs[l].style.zIndex = 1;
    }
  }
}
