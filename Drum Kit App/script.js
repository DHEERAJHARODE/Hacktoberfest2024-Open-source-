/*
  Challenge: Complete the drum kit app
   * Add the button and audio elements for the
     snare, tom, and hi-hat sounds.
   * Update the JavaScript so clicking each button
     will play the corresponding sound.
   * Play each sound when pressing a specific key.
*/

// Retrieve the kick button element
const kickButton = document.getElementById("kick");
const rideButton = document.getElementById("ride");
const snareButton = document.getElementById("snare");
const tomButton = document.getElementById("tom");
const hiHatButton = document.getElementById("hihat");

// Retrieve the kick sound element
const kickSound = document.getElementById("kick-sound");
const rideSound = document.getElementById("ride-sound");
const snareSound = document.getElementById("snare-sound");
const tomSound = document.getElementById("tom-sound");
const hiHatSound = document.getElementById("hihat-sound");

// Attach a click event listener to the kick button
kickButton.addEventListener("click", function() {
  // Reset the sound time to replay it
  kickSound.currentTime = 0;
  
  // Play the kick sound
  kickSound.play();
});

rideButton.addEventListener("click", function() {
  // Reset the sound time to replay it
  rideSound.currentTime = 0;
  
  // Play the kick sound
  rideSound.play();
});

snareButton.addEventListener("click", function() {
  snareSound.currentTime = 0;
  snareSound.play();
});

tomButton.addEventListener("click", function() {
  tomSound.currentTime = 0;
  tomSound.play();
});

hiHatButton.addEventListener("click", function() {
  hiHatSound.currentTime = 0;
  hiHatSound.play();
});

// Attach a keydown event listener to the document
document.addEventListener("keydown", function(event) {
  // Check if the pressed key is "a"
  if (event.key === "a") {
    kickSound.currentTime = 0;
    kickSound.play();
  } else if (event.key === "s") {
    rideSound.currentTime = 0;
    rideSound.play();
  } else if (event.key === "d") {
    snareSound.currentTime = 0;
    snareSound.play();
  } else if (event.key === "f") {
    tomSound.currentTime = 0;
    tomSound.play();
  } else if (event.key === "g") {
    hiHatSound.currentTime = 0;
    hiHatSound.play();
  }
});