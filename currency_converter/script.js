const dropList = document.querySelectorAll(".drop-list select"),
fromCurrency= document.querySelector(".from select"),
toCurrency = document.querySelector(".to select"),
getButton = document.querySelector("form button");

for (let i = 0; i < dropList.length; i++) {
    for(currency_code in country_code){
        let selected;
        if(i==0){
            selected = currency_code == "USD" ? "selected" : "";
        }
        else if(i == 1){
            selected = currency_code == "NPR" ? "selected" : "";
        }
       let optionTag = `<option value="${currency_code}"${selected}>${currency_code}</option>`;
       dropList[i].insertAdjacentHTML("beforeend",optionTag);
    }
    dropList[i].addEventListener("change", e => {
        loadFlag(e.target);
    });
    
}

function loadFlag(element){
    for(code in country_code){
        if(code == element.value){
            let imgTag = element.parentElement.querySelector("img");
            imgTag.src = `https://flagsapi.com/${country_code[code]}/flat/64.png`;
        }
    }
}

window.addEventListener("load", () =>{
    e.preventDefault();
    getExchangeRate();
});

getButton.addEventListener("click", e =>{
    e.preventDefault();
    getExchangeRate();
});
exchangerateTxt.innerHTML="Getting Exchange Rate...";
function getExchangeRate(){
    const amount = document.querySelector(".amount input");
    let amountVal = amount.value;
    if(amountVal == "" || amountVal == "0"){
        amount.value="1";
        amountVal=1;
    }
    let url = `https://v6.exchangerate-api.com/v6/def155e098e2783021916a3c/latest/${fromCurrency.value}`;
    fetch(url).then(response => response.json()).then(result => {
        let exchangerate = result.conversion_rates[toCurrency.value];
        let  totalExchangeRate = (amountVal * exchangerate).toFixed(2);
        exchangerateTxt = document.querySelector(".exchange-rate");
        exchangerateTxt.innerHTML = `${amountVal} ${fromCurrency.value} = ${totalExchangeRate} ${toCurrency.value}`;
    })
}