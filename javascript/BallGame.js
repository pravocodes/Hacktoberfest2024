<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title> Catch the Ball</title>
  <style>
    .container{
        background-color:antiquewhite;
        height:25%;
        border:1px solid white;
        border-radius:12px;
    }

    button{
      display: block;
      margin-left: auto;
      margin-right: auto;
    }
    h1,h2,h3{
      text-align: center;
      color:black;
    }
   
    HTML{
    
    }
    canvas {
      display: block;
      margin-left: auto;
      margin-right: auto;
      background-color: rgb(255, 255, 255);
    }

    button{
      padding:12px;
      border:1px solid black;
      border-radius:12px;
    }
    button:hover{
      background-color: rgb(255, 203, 203);
    }
  </style>

</head>

<body>
  <div class="container">
    <h1>Catch the Ball Game using javascript</h1>
    <br>
    <h2>Instructions</h2>
    <h3>To earn points, click the falling ball before it falls below the bottom green border. If the ball falls below the bottom green border, you will loose 1 life. Loose 3 lives and the game is over. Every 30 seconds, the ball will increase its falling speed. This will happen 4 times. The faster the ball falls, the more points you will earn for clicking on the ball.</h3>
    <button onclick="init()">Start Game</button>
    <br>
  </div>
   

 
<script> 

    // Declaring variables
    var container;
    var canvas = document.createElement( 'canvas' );
    var context = canvas.getContext("2d");
    var ball;
    var lives = 3;
    var score = 0;
    var speed = 2;
    var secondMilestone = 1;
    var pointsGiven = 5;
    var mouseX;
    var mouseY;
    var timeLeft = 30;
    var timerId;
    
    // Function to get random variable between a minimum and a maximum
    function getRandomInt(min, max) {
      min = Math.ceil(min);
      max = Math.floor(max);
      return Math.floor(Math.random() * (max - min) + min); //The maximum is exclusive and the minimum is inclusive
    }

    // Function to set up the canvas, set the ball variables properties, and start the countdown upon clicking the "Start Game" button
    function init(){
       setupCanvas();
       ball = {x:getRandomInt(25, 975), y:-50, radius:20, status: 0, color:"#FFA500"};
       timerId = setInterval(countdown, 1000);
 
    }

    // Function to draw the user's score
    function drawScore() {
    context.beginPath();
    context.font = "24px Arial";
    context.fillStyle = "#212121";
    context.fillText("Score: "+score, canvas.width-250, 30);
    context.closePath();
    }

    // Function to draw the player's lives and monitor if the lives are all gone
    function drawLives() {
    context.beginPath();
    context.font = "24px Arial";
    context.fillStyle = "#C62828";
    context.fillText("Lives: "+lives, 8, 30);
    context.closePath();
    // If all lives are gone, set the timer to 0 (This creates a reaction in the timer function to end the game)
    if (lives == 0)
    {
      timeLeft = 0;
    }
    }

    // Function to draw timer and eliminate timer when the max speed is reached
    function drawTimer() {
      // When the max speed (milestone) is reached, timer is eliminated and replaced with text
      if (secondMilestone == 5){
      var timerText = "Your speed is maxed out!";
      }
      // Execute live timer
      else{
        var timerText = "Speed up in: "+timeLeft;
      }
      context.beginPath();
      context.font = "24px Arial";
      context.fillStyle = "#212121";
      context.fillText(timerText, canvas.width-650, 30);
      context.closePath();
    }

    // Function to draw the top boarder
    function drawTopBoarder(){
    context.beginPath();
    context.rect(0, 0, 1000, 50);
    context.fillStyle = "#DCE775";
    context.fill();
    context.closePath();
    }

    // Function to draw the bottom border
    function drawBottomBoarder(){
    context.beginPath();
    context.rect(0, 600, 1000, 50);
    context.fillStyle = "#DCE775";
    context.fill();
    context.closePath();
    }

    // Function to draw the ball object
    function drawBall(){
    context.beginPath();
    context.arc(ball.x, ball.y, ball.radius, 0, Math.PI*2, false);
    context.fillStyle = ball.color;
    context.fill();
    context.closePath();
    }

    // Function to check if ball is clicked, check if ball is out of play, and return ball to the top border if either action is triggered.
    function ballCheck(){
      // On click, get the current X and Y position of the mouse cursor
      var rect = canvas.getBoundingClientRect();
      document.addEventListener("click", () => {
      mouseX = (event.clientX-rect.left)/(rect.right-rect.left)*canvas.width; // Gets Mouse X
      mouseY = (event.clientY-rect.top)/(rect.bottom-rect.top)*canvas.height; // Gets Mouse Y
      // Check if the mouse's current position is the same as the ball's 
      if (mouseX <= ball.x+20 && mouseX >= ball.x-20)// Check matching X
     {
       if (mouseY <= ball.y+20 && mouseY >= ball.y-20)// Check matching Y
       {
         score += pointsGiven;// Increase the score by the set points to be given
         ball.y = -50;// Place the ball at it's starting Y position
         ball.x = getRandomInt(25, 975);// Randomly choose a X position for the ball 
       }
     }
    });
    // Check if ball is out of play
    if (ball.y >= 640)
      {
      lives -= 1; // Decrease the players lives by 1 life
      ball.y = -50;// Place the ball at it's starting Y position
      ball.x = getRandomInt(25, 975);// Randomly choose a X position for the ball 
      }
  }

    // Function to manage the timer, increase the reward and speed, and reset reward, speed, lives, score, and ball position if player runs out of lives.
    function countdown() {
        // When time reaches 0, reset the timer and increase the rewards and speed so long as the speed is under 20 
        if (timeLeft == 0) {
        clearTimeout(timerId);
        timeLeft = 30;
        timerId = setInterval(countdown, 1000);
        // If speed is under 20, check if the speed is equal to 2 or not
        if(speed < 20)
      {
        // If speed is equal to 2, check if lives are equal to 0 or not
        if (speed == 2)
        {
          // If lives are equal to 0, end the game and ask if the user wants to play again and then reset the game
          if(lives==0){
            // Declare that the game is over, show the score, and ask if the user wants to play again
            alert("Game Over! Your score is "+ score +". Press OK to play again.");
            lives = 3;// Reset lives
            speed = 2;// Reset speed
            secondMilestone = 1;// Reset milestones
            pointsGiven = 5;// Reset reward
            score = 0;// Reset score
            ball.y = -50;// Place the ball at it's starting Y position
            ball.x = getRandomInt(25, 975);// Randomly choose a X position for the ball
          }
          // If user is still in play and 30 seconds go by, increase the speed and reward
          else{
            speed = 5;// Increase speed to 5
            secondMilestone = 2;// Set milestone to 2
            pointsGiven = 5*secondMilestone;// Set the reward to be the original reward times the milestone
          }
        }
        // Check if lives are equal to 0 or not
        else{
          // If lives are equal to 0, end the game and ask if the user wants to play again and then reset the game
          if(lives==0){
            // Declare that the game is over, show the score, and ask if the user wants to play again
            alert("Game Over! Your score is "+ score +". Press OK to play again.");
            lives = 3;// Reset lives
            speed = 2;// Reset speed
            secondMilestone = 1;// Reset milestones
            pointsGiven = 5;// Reset reward
            score = 0;// Reset score
            ball.y = -50;// Place the ball at it's starting Y position
            ball.x = getRandomInt(25, 975);// Randomly choose a X position for the ball
          }
          // If user is still in play and 30 seconds go by, increase the speed and reward
          else{
            speed += 5; // Increase speed by 5
            secondMilestone += 1; // Increase the milestone by 1
            pointsGiven = 5*secondMilestone; // Set the reward to be the original reward times the milestone
          }
        }
      }
      } 
      // If time left is not equal to 0, decrease the timer by 1
      else {
        timeLeft--;
      }
    }

    // Function to control speed of the falling ball
    function ballMovement(){
        ball.y += speed;       
    }
 
    //Function to set up canvas
     function setupCanvas() {
	    container = document.createElement( 'div' );
	    container.className = "container";
	    canvas.width = 1000; 
	    canvas.height = 640; 
	    document.body.appendChild(container);
	    container.appendChild(canvas);	
	    context.strokeStyle = "#ffffff";
	    context.lineWidth =2;  	
    }

    // Function to draw game
    function draw() {
        context.clearRect(0,0,canvas.width, canvas.height);  
        drawBall();
        ballMovement();
        drawTopBoarder();
	      drawBottomBoarder();
        drawScore();
        drawTimer();
        drawLives();
        ballCheck();
    }
 
    // Execute the draw() function
    setInterval(draw, 1000/35); 

</script>

</body>
</html>
