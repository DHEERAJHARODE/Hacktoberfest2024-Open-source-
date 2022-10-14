//variables to get elements 
main = document.getElementById('main');
dino = document.getElementById('dino');
cactus = document.getElementById('cactus');

//function to add a jump animation class and timer of 500ms to remove it
function jump() {
    if (dino.classList != 'jump-action'){
        dino.classList.add("jump-action");
    }
    setTimeout (() => {
        dino.classList.remove("jump-action");
    }, 500);
    console.log('done')
};

//check if top of of dino is colliding with side of cactus to check if player died
let dead = setInterval(function() {
    dinotop = parseInt(window.getComputedStyle(dino).getPropertyValue("top")); //top of dino
    cactusleft = parseInt(window.getComputedStyle(cactus).getPropertyValue("left")); //side of cactus
    if (cactusleft<40 && cactusleft>0 && dinotop>=200) {
        cactus.style.animation = 'none';
        cactus.style.display = 'none'
        alert('you lose');
    }
}, 10);
