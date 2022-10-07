# HTML

<body id="body">
  
     <div class="container">
         <div class="btn-area">
             <button type="button" onclick="dark()" class="btn">DARK</button>
             <button type="button" onclick="white()" class="btn">WHITE</button>
         </div>
         <div class="text-content">
             <h2>CodingFlicks</h2>
             <h3>Free HTML CSS JS Resources</h3>
         </div>
     </div>
  </body>
  
# CSS  
  
button{
color: #000;
}
.dark{
background: #000;
color: #fff;
font-weight: bold;
transition: .9s;
}
.white{
background: #fff;
color: #000;
font-weight: bold;
transition: .9s;
}
.btn-area{
height: 92px;
width: 220px;
right: -105px;
top: 35%;
z-index: 1000;
transform: rotate(-90deg);
position: fixed;
}
.text-content{
padding-top: 15%;
}
.text-content h2{
font-size: 130px;
font-family: lato;
text-align: center;
letter-spacing: 5px;
}
.text-content h3{
font-size: 40px;
font-family: lato;
text-align: center;
}


# JS

function white(){
            body.className='white';
        }
    
        function dark(){
            body.className='dark';
        }
