const btn=document.querySelector("button");
const h1=document.querySelector("h1");
const span=document.querySelector("span");

// Fetching API

let id=1;
const url="https://api.adviceslip.com/advice"
const getData=async function(){
    const xhr=new XMLHttpRequest();
    const response=await fetch(`${url}/${Math.floor(Math.random() * 118) + 1}`);
    if(response.ok){
         const data=await response.json();
         return data;
        }
    else{
        console.log("something went wrong..");
    }
}


btn.addEventListener("click",()=>{
    
 getData()
.then(data=>{
    id++;
    span.textContent=id;
    h1.textContent=`"${data.slip.advice}"`;
})
.catch(()=>{
    console.log("Check your internet connection");
})
btn.classList.toggle('rotate');
})
