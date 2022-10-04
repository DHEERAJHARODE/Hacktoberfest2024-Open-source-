// Strong numbers are the numbers that the sum of the factorial of its digits
// is equal to the original number
    
// 145 is a strong number: 1 + 24 + 120 = 145
  
function CalculateFactorial(number) {
    let fact = 1;
    for (let i = 1; i <= number; i++) {
         fact = fact * i;
    }
    return fact;
}

function checkStrongNumber(number){
    let sum = 0;
          
let n = number;
         
 while (n != 0) {
      let remainder = n % 10;
      const fact = CalculateFactorial(remainder);
      n = Math.floor(n / 10);
      sum = sum + fact;
 }
          
 if (sum == number) {
     console.log("Strong Number");
 }
 else {
     console.log("Not Strong Number");
 }
}
 
checkStrongNumber(148)
