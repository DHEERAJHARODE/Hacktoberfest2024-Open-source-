#include <iostream>
#include <cstdlib>
#include <ctime> //Time
#include <vector> //Array
#include <chrono> //get time
#include <algorithm> //is_sorted(...)
using namespace std;
using namespace std::chrono; //For get the time
int main(){

	srand(time(NULL)); //For random function
	vector<int> array (13, 0); //My array
	for(unsigned i = 0; i < sizeof(array); i++)
		array[i] = rand()%sizeof(array); //Create a random array

	auto start = high_resolution_clock::now(); //Start time
	while(!is_sorted(array.begin(),array.end())){ //Verify
		unsigned random1 = rand()%sizeof(array); //Random position
		unsigned random2 = rand()%sizeof(array); //Random Position
		int value = array[random1]; //Bubble sort...
		array[random1] = array[random2]; //Bubble sort...
		array[random2] = value; //Bubble sort...
	}
	auto stop = high_resolution_clock::now(); //Stop time

	auto duration = duration_cast<milliseconds>(stop - start); //Take time in milliseconds | 1 Second == 0.001 Milliseconds

	cout << "Array sorted in " << duration.count() << " millisecond" << endl; //Take time in seconds
	cout << "Array sorted in " << duration.count()/1000 << " seconds" << endl;
	for(auto i:array) //Just a print
		cout << i << " ";
	cout << endl;
	return 0; //Correct end
}
