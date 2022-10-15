// Declaring Global Variables
var min = "00";
var colon = ':';
var sec = "00";
var stat = "Set Timer";
var stater = 0;
var st = 0;
var bt = 0;
var stbtn = "START";
var startstatus = 0;
var btst = 1;
var timeSecond = 1000;
var designPattern = "-------------------";
// Importing Audio Files
var bell = new Audio('res/bell.mp3');
var click = new Audio ('res/click.mp3');


function pad(num) {
    if (num >= 0 && num <= 9) {
        num = '0' + num;
    }
    return num;
}

function display() {
    document.getElementById("min").innerHTML = min;
    document.getElementById("colon").innerHTML = colon;
    document.getElementById("sec").innerHTML = sec;
    document.getElementById("stat").innerHTML = stat;
    document.getElementById("st").innerHTML = st;
    document.getElementById("bt").innerHTML = bt;
    document.getElementById("mnbtn1").innerHTML = stbtn;
    document.getElementById("msg").innerHTML = designPattern;

}



function sessionTimeIncrement() {
    if (startstatus == 0) {
        click.play();
        st++;
        min = sec = "00";
        display();
    } else {
        resetTheCurrentSessionMessage();
    }
}

function sessionTimeDecrement() {
    if (startstatus == 0) {
        if (st > 0) {
            click.play();
            st--;
            min = sec = "00";
            display();
        }
    } else {
        resetTheCurrentSessionMessage();
    }
}

function breakTimeIncrement() {
    if (startstatus == 0) {
        click.play();
        bt++;
        min = sec = "00";
        display();
    } else {
        resetTheCurrentSessionMessage();
    }
}

function breakTimeDecrement() {
    if (startstatus == 0) {
        if (bt > 0) {
            click.play();
            bt--;
            min = sec = "00";
            display();
        }
    } else {
        resetTheCurrentSessionMessage();
    }
}

function resetTheCurrentSessionMessage() {
    document.getElementById("msg").innerHTML = "Reset current session!";
    setTimeout(function () {
        document.getElementById("msg").innerHTML = designPattern;
    }, 3000)
}



var ss;
var ct;
var secbk;
var minbk;
function start() {


    if (st == 0) {
        document.getElementById("msg").innerHTML = "Set Session Time!";
        setTimeout(function () {
            document.getElementById("msg").innerHTML = designPattern;
        }, 3000)
        return;
    }
    if (startstatus == 0) {
        startstatus = 1;
    } else {
        return;
    }
    bell.play();
    stater++;
    stat = "Session " + stater;
    document.getElementById("stat").style.color = "#ffe7c4";
    document.getElementById("min").style.color = "#ffe7c4";
    document.getElementById("sec").style.color = "#ffe7c4";
    document.getElementById("colon").style.color = "#ffe7c4";
    display();
    sec = 60;
    min = st - 1;
    ct = (st * 60) - 1;


    timer();

}
function timer() {
    var i = 0;

    ss = setInterval(function () {
        sec--;
        secbk = sec;
        minbk = min;
        sec = pad(sec);



        if (sec < 0) {
            sec = 59;
            secbk = 59
            min--;
            minbk--;
        }

        min = pad(min);


        display();

        sec = secbk;
        min = minbk;

        if (i > ct) {

            if (bt == 0) {
                clearInterval(ss);
                startstatus = 0;
                reset();
            } else {
                clearInterval(ss);
                btstart();
            }
        }
        i++;
    }, timeSecond)
}


function btstart() {
    if (btst == 0) btst = 1;
    else btst = 0;
    if (btst == 0) {
        bell.play();
        min = bt - 1;
        var minb = min;
        sec = 59;
        ct = (bt * 60) - 2;
        sessionBreakeColorChange("#ff2929");
        stat = "BREAK";

        min = pad(min);

        display();
        sec = 60;
        min = minb;
        timer();
    } else {
        bell.play();
        sessionBreakeColorChange("#ffe7c4")
        stater++;
        stat = "SESSION " + stater;
        sec = 60;
        var secb = sec;
        sec = 59;
        min = st - 1;
        var minb = min;
        ct = (st * 60) - 1;
        min = pad(min);

        display();
        sec = secb;
        min = minb;
        timer();
    }
}
function sessionBreakeColorChange(color) {
    document.getElementById("stat").style.color = color;
    document.getElementById("min").style.color = color;
    document.getElementById("sec").style.color = color;
    document.getElementById("colon").style.color = color;
}

function reset() {
    clearInterval(ss);
    startstatus = 0;
    min = "00";
    sec = "00";
    stat = "Set Timer";
    stater = 0;
    st = 0;
    bt = 0;
    stbtn = "START";
    sessionBreakeColorChange("#ffffff");
    display();
}








