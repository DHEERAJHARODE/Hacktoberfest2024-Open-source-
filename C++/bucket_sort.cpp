#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void display(float *array, int size) {

   for(int i = 0; i<size; i++)

      cout<< array[i]<<"  ";

   cout<<endl;

}

void bucketSort(float *array, int size) {

   vector<float> bucket[size];

   for(int i = 0; i<size; i++) { //adding elements into different buckets

      bucket[int(size*array[i])].push_back(array[i]);

   }

   for(int i = 0; i<size; i++) {

      sort(bucket[i].begin(), bucket[i].end()); //sort individual buckets

   }

   int index = 0;

   for(int i = 0; i<size; i++) {

      while(!bucket[i].empty()) {

         array[index++] = *(bucket[i].begin());

         bucket[i].erase(bucket[i].begin());

      }

   }

}

int main() {

   int n;

   cout << "Enter the number of elements to be sorted: ";

   cin >> n;

   float arr[n]; //create an array with given number of elements

   cout<<"Enter the elements:"<<endl;

   for(int i = 0; i<n; i++) {

      cin>>arr[i];

   }

   cout<<"\nARRAY BEFORE SORTING: ";

   display(arr, n);

   bucketSort(arr, n);

   cout <<"\nARRAY AFTER SORTING USING BUCKET SORT: ";

   display(arr, n);

}
Footer
© 2022 GitHub, Inc.