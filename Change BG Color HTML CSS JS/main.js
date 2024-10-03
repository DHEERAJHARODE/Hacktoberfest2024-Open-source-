const button = document.querySelector('button');
const h2El = document.querySelector('h2');
const bgEl = document.querySelector('section');
// const hexColorEl = [1,2,3,4,5,6,7,8,9,'A','B','c','D','E','F'];

if (button && h2El && bgEl) {

  // Function to generate a valid 6-character hex code
  function generateHexColor() {
    let color = Math.random().toString(16).slice(2, 8);
    return color.padEnd(6, '0').toUpperCase(); // Ensures 6 characters, pads with '0' if too short
  }

  // Function to handle button click
  button.addEventListener('click', () => {
    const color = `#${generateHexColor()}`;
    bgEl.style.backgroundColor = color; // Set background color
    h2El.innerText = color; // Display hex code
  });

} else {
  console.error("One or more required elements are missing on the page.");
}
