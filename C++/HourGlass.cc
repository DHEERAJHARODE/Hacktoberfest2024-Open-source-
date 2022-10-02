#include <iostream>
using namespace std;

int main() {
    
  int size ;
  cout<<"entre the  size of hour glass";
  cin>>size;
  // reversed pyramid star pattern
  for (int i = 0; i < size; i++) {
    // printing spaces
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    // printing star
    for (int k = 0; k < (size - i) * 2 - 1; k++) {
      cout << "*";
    }
    cout << "\n";
  }
  // pyramid star pattern
  for (int i = 2; i <= size; i++) {
    // printing spaces
    for (int j = size; j > i; j--) {
      cout << " ";
    }
    // printing star
    for (int k = 0; k < i * 2 - 1; k++) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}