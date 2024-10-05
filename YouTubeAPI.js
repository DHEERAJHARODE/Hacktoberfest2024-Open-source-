// const container = document.querySelector('#container');

const container = document.querySelector("#container");
//declaration
let apikey = "YOUR_API_KEY";
let maxresults = "NO_OF_RESULTS_TO_SHOW";
let playlistid = "PLAYLSIST_ID";
let youtubeurl =
  "https://www.googleapis.com/youtube/v3/playlistItems?part=snippet&maxResults=" +
  maxresults +
  "&playlistId=" +
  playlistid +
  "&key=" +
  apikey;
const xhr = new XMLHttpRequest();
xhr.open("GET", youtubeurl);
xhr.send();
xhr.onreadystatechange = function () {
  if (xhr.readyState === 4 && xhr.status === 200) {
    let json = JSON.parse(xhr.responseText);
    let html = "";
    let thumbnail = "";
    let videoid = "";
    let title = "";
    for (let i in json.items) {
      thumbnail = json.items[i].snippet.thumbnails.medium
        ? json.items[i].snippet.thumbnails.medium.url
        : json.items[i].snippet.thumbnails.default.url;
      videoid = json.items[i].snippet.resourceId.videoId;
      title = json.items[i].snippet.title;
      html +=
        '<div class="container"><div class="lazy"><div class="playButton"><div class="youtube"><iframe class="lazy" src=" https://www.youtube.com/embed/' +
        videoid +
        '" width="560" height="315" fullscreen></iframe></div></div><div class="col1-2_u"><div class="txtBox"><p class=titletext>' +
        title +
        '</p></div><div id="ytplayer' +
        videoid +
        '" class="player"></div></div></div></div>';
    }
    // add this code to show thumbnail
    // <span></span><img class="thumb" width="560" height="315" src="' +
    //     thumbnail +
    //     '"></img>
    document.getElementById("youtube").innerHTML = html;
  }
};

// Set the options globally
// to make LazyLoad self-initialize
window.lazyLoadOptions = {
  // Your custom settings go here
};

// Listen to the initialization event
// and get the instance of LazyLoad
window.addEventListener(
  "LazyLoad::Initialized",
  function (event) {
    window.lazyLoadInstance = event.detail.instance;
  },
  false
);
