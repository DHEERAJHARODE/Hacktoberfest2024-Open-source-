
window.playablePiano = function () {
    const pianoKeys = document.querySelectorAll(".piano-keys .keys"),
      volumeSlider = document.querySelector(".volume-slider input"),
      keysCheckbox = document.querySelector(".keys-checkbox input");
  
    let allKeys = [],
      audio = new Audio(`tunes/a.wav`); // by default, audio src is "a" tune
  
    const playTune = (key) => {
      audio.src = `tunes/${key}.wav`; // passing audio src based on key pressed
      audio.play(); // playing audio
  
      const clickedKey = document.querySelector(`[data-key="${key}"]`); // getting clicked key element
      clickedKey.classList.add("active"); // adding active class to the clicked key element
      setTimeout(() => {
        // removing active class after 150 ms from the clicked key element
        clickedKey.classList.remove("active");
      }, 150);
    };
  
    pianoKeys.forEach((key) => {
      allKeys.push(key.getAttribute("data-key")); // adding data-key value to the allKeys array
      key.addEventListener("click", () => playTune(key.getAttribute("data-key")));
    });
  
    const handleVolume = (e) => {
      audio.volume = e.target.value; // passing the range slider value as audio volume
    };
  
    const showHideKeys = () => {
      pianoKeys.forEach((key) => key.classList.toggle("hide"));
    };
  
    const pressedKey = (e) => {
      if (allKeys.includes(e.key)) playTune(e.key); // only call playTune if the pressed key is in allKeys array
    };
  
    keysCheckbox.addEventListener("click", showHideKeys);
    volumeSlider.addEventListener("input", handleVolume);
    document.addEventListener("keydown", pressedKey);
  };
  
  // Call the playablePiano function to enable the piano functionality
  window.playablePiano();
  
