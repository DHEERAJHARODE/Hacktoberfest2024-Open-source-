#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;

    // Pushing a element
    s.push(1);
    s.push(2);
    s.push(3);

    cout<<s.top()<<endl;

    // Popping of the function 
    s.pop();
    cout<<s.top();
    return 0;
}
