// this is the solution for grid traveller problem 
// i used dynamic program to solve this problem


const gridTraveller = (m,n , memo={})=>{
   const key = m+','+n;
   if(key in memo) return memo[key];
   if(m==1||n==1) return 1;
   if(m==0||n==0) return 0;
   memo[key] = gridTraveller(m-1,n,memo) + gridTraveller(m,n-1,memo); 
   return memo[key];
}
console.log(gridTraveller(1,1));
console.log(gridTraveller(2,3));
console.log(gridTraveller(5,4));
console.log(gridTraveller(4,5));
console.log(gridTraveller(100,100));