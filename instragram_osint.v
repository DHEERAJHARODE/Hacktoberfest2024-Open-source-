// Program is to check whether instagram username is available or not
// By Aravindha Hariharan

import net.http
import os

if os.args.len == 1 {
    println("ERROR: Required username")
    exit(0)
}
username := os.args[1]

resp := http.fetch(http.FetchConfig{
    url: 'https://www.instagram.com/$username/?__a=1',
    user_agent: 'Mozilla/5.0 (Windows NT 6.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/57.0.2987.133 Safari/537.36'
}) or {
    println('failed to fetch data from the server')
    return
}

if resp.text.len == 2 {
    println("Username is available")
}else{
    println("Username Already")
}

/*
Output:

v instagram_osint.v
ERROR: Required username

v instagram_osint.v facebook
Username Already

v instagram_osint.v "temp@123"
Username is available
*/