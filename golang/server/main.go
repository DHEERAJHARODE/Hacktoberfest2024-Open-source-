package main

import (
	"fmt"
	"log"
	"net/http"
)

func helloFuncHandler(res http.ResponseWriter, req *http.Request) {
	if req.URL.Path != "/hello" {
		http.NotFound(res, req)
		return
	}

	if req.Method != "GET" {
		res.Header().Set("Allow", "GET")
		http.Error(res, "Method not allowed", http.StatusMethodNotAllowed)
		return
	}

	// res.Write([]byte("Hello World!"))
	fmt.Fprintf(res, "Hello World!")
}

func formFuncHandler(res http.ResponseWriter, req *http.Request) {
	if err := req.ParseForm(); err != nil {
		fmt.Fprintf(res, "ParseForm() err: %v", err)
		return
	}
	fmt.Fprintf(res, "POST REQUEST SUCCESSFUL\n")
	email := req.FormValue("email")
	password := req.FormValue("password")
	fmt.Fprintf(res, "Email: %v\nPassword: %v\n", email, password)
}
func main() {
	fileServer := http.FileServer(http.Dir("./static"))

	http.Handle("/", fileServer)
	http.HandleFunc("/hello", helloFuncHandler)
	http.HandleFunc("/form", formFuncHandler)

	if err := http.ListenAndServe(":8080", nil); err != nil {
		log.Fatal(err)
	}
}
