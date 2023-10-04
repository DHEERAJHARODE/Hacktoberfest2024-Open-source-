function getRandomNumber(min, max) {
    // Use Math.floor() to round down to the nearest integer
    // Math.random() generates a random decimal between 0 (inclusive) and 1 (exclusive)
    // We multiply the random decimal by (max - min + 1) to include max
    // Finally, we add min to ensure it starts from min
    return Math.floor(Math.random() * (max - min + 1)) + min;
  }
  
  // Example usage to generate a random number between 1 and N (e.g., N = 10)
  const N = 10;
  const randomNum = getRandomNumber(1, N);
  
  console.log(`Random number between 1 and ${N}: ${randomNum}`);
  