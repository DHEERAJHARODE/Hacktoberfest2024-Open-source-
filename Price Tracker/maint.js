// Fetch BTC Price
function fetchBitcoinPrice() {
  fetch('https://api.coindesk.com/v1/bpi/currentprice/BTC.json')
      .then(response => response.json())
      .then(data => {
          const priceElement = document.getElementById('btc');
          const price = data.bpi.USD.rate;
          priceElement.innerText = `$ ${price}`;

          // Formula to convert btc price in 100%     
          let btcc = `${price}`;

          // Converting btc value in comma to normal numeric value without commas
          const btcstr = btcc.toString();
          let ogbtc = btcstr.replace(/,/g,"");
          
          
          console.log(ogbtc);


          prcbtc = ogbtc - 25000;
          prcbtc = (prcbtc*(-0.02))+250;
          prcbtc = Math.floor(prcbtc) + "px";
          console.log(prcbtc);
          const elem = document.getElementById('btcliquid');
          elem.style.top = prcbtc;


      })
      .catch(error => {
          console.log('Error:', error);
      });
}
// Fetch ETH price
function fetchETHPrice() {
  fetch('https://api.coingecko.com/api/v3/simple/price?ids=ethereum&vs_currencies=usd')
      .then(response => response.json())
      .then(data => {
          document.getElementById('eth').textContent = `$ ${data.ethereum.usd.toFixed(2)}`;


          
          // Formula to convert eth price in 100%

          let prceth = `${data.ethereum.usd.toFixed(2)-1500}`;
          prceth = (prceth*(-0.2))+250;
          prceth = Math.floor(prceth) + "px";
          console.log(prceth);
          const elem = document.getElementById('ethliquid');
          elem.style.top = prceth;



      });
}
// Fetch AVAX price
function fetchAVAXPrice() {
  fetch('https://api.coingecko.com/api/v3/simple/price?ids=avalanche-2&vs_currencies=usd')
      .then(response => response.json())
      .then(data => {
          document.getElementById('avax').textContent = `$ ${data['avalanche-2'].usd.toFixed(2)}`;



          // Formula to convert avax price in 100%

          let prcavax = `${data['avalanche-2'].usd.toFixed(2)-10}`;
          prcavax = Math.floor(prcavax*(-20))+250;
          prcavax = Math.floor(prcavax) + "px";
          console.log(prcavax);
          const elem = document.getElementById('avaxliquid');
          elem.style.top = prcavax;
          // elem.style.top = '200px';



      });
}

// Initial fetch
fetchBitcoinPrice();
fetchETHPrice();
fetchAVAXPrice();
// Fetch price every 5 seconds
setInterval(fetchBitcoinPrice, 5000);
setInterval(fetchETHPrice, 5000);
setInterval(fetchAVAXPrice, 5000);


