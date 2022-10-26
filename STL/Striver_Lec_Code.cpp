 #include <bits/stdc++.h> 
using namespace std; 

struct node {
	string str; 
	int num;
	double doub; 
	char x; 

	node(str_, num_, doub_, x_) {
		str = str_; 
		num = num_; 
		doub = doub_; 
		x = x_; 
	}
};
array<int, 3> arr; // -> {0, 0, 0} 

// max size of 10^7 -> int, double, char 
int arr[10000000];

// max size of 10^8 -> bool
	bool arr[100000000];  
int main() {

	// max size of 10^6 -> int, double, char 
	int arr[1000000]; 


	// max size of 10^7 -> bool
	bool arr[10000000]; 

	double val = 10.0;
	cout << val << endl; // prints 10.0 

	cout << raj::getVal() << endl; // prints 50 


	int 
	double 
	char
	

	// create a data type where you store 
	{string, int, double, char} 


    // wrong way of defining 
	node raj; 
	raj.str = "striver"; 
	raj.num = 79; 
	raj.doub = 91.0; 

	node raj = new node("striver", 79, 91.0, ""); 


	{arr[], int, double}; 



	// Arrays -> int arr[100]; 


	array<int, 3> arr;  // -> {?, ?, ?}


	array<int, 5> arr = {1}; // -> {1, 0, 0, 0, 0}


	int arr[10000] = {0}; 



	array<int, 5> arr; 
	arr.fill(10); -> /// {10, 10, 10, 10, 10} 


	arr.at(index); 

	for(int i = 0;i<5;i++) {
		cout << arr.at(i) << " "; 
	}


	// iterators 
	// begin(), end(), rbegin(), rend() 

	// 

	array<int, 5> arr = {1, 3, 4, 5, 6}; 
	for(auto it: arr.begin(); it!=arr.end();it++) {
		cout << *it << " "; 
	}



	for(auto it: arr.rbegin(); it>arr.rend();it++) {
		cout << *it << " "; 
	}

	for(auto it: arr.end() - 1; it>=arr.begin();it--) {
		cout << *it << " "; 
	}

	// for each loop 
	for(auto it: arr) {
		cout << it << " "; 
	}

	string s = "xhegcwe"; 
	// x h e g c w e 
	for(auto c:s) {
		cout << c << " "; 
	}


	// size 
	cout << arr.size(); 

	// front 
	cout << arr.front(); // arr.at(0); 

	// back
	cout << arr.back(); // arr.at(arr.size() - 1); 




	// VECTOR 

	int arr[50];

	// segmentation fault if you push_back 10^7 times

	vector<int> arr; // -> {}
	cout << arr.size() << endl; // -> print 0 
	arr.push_back(0); // {0}
	arr.push_back(2); // {0,2}
	cout << arr.size() << endl; // -> print 2
	arr.pop_back(); // {0}
	cout << arr.size() << endl; // print 1  

	arr.push_back(0); // {0,0}
	arr.push_back(2); // {0,0,2}


	vec.clear(); // --> erase all elements at once {}


	vector<int> vec1(4, 0); // -> {0,0,0,0}
	vector<int> vec2(4, 10); // -> {10,10,10,10}

	// copy the entire vec2 into vec3
	vector<int> vec3(vec2.begin(), vec2.end()); // -> [)
	vector<int> vec3(vec2); 



	vector<int> raj;
	raj.push_back(1); // raj.emplace_back(1); // emplace_back takes lesser time than push back 
	raj.push_back(3); 
	raj.push_back(2); 
	raj.push_back(5); // -> {1, 3, 2, 5} 

	vector<int> raj1(raj.begin(), raj.begin() + 2);  // -> {1, 3}  


	// lower bound , upper bound 

	// swap swap(v1, v2) 
	// begin(), end(), rbegin(), rend() 


	// to defining 2d vectors 

	vector<vector<int>> vec; 

	vector<int> raj1;
	raj1.push_back(1); 
	raj1.push_back(2); 

	vector<int> raj2;
	raj2.push_back(10); 
	raj2.push_back(20); 

	vector<int> raj3;
	raj3.push_back(19); 
	raj3.push_back(24); 
	raj3.push_back(27); 

	vec.push_back(raj1); 
	vec.push_back(raj2); 
	vec.push_back(raj3); 

	// it is vector itself 
	for(auto vctr: vec) {
		for(auto it: vctr) {
			cout << it << " "; 
		}
		cout << endl; 
	}


	for(int i = 0;i<vec.size();i++) {
		for(int j = 0;j<vec[i].size();j++) {
			cout <<  vec[i][j] << " "; 
		}
		cout << endl; 
	}


	// define 10 x 20 
	vector<vector<int>> vec(10, vector<int> (20, 0)); 
	vec.push_back(vector<int>(20, 0)); 
	cout << vec.size() << endl; // 11 prints
	
	vec[2].push_back(1); 


	vector<int> arr[4]; 
	arr[1].push_back(0); 


	// 10 x 20 x 30 // int arr[10][20][30] 
	vector<vector<vector<int>>> vec(10, vector<vector<int>> vec(20, vector<int> (30, 0));)





















}





