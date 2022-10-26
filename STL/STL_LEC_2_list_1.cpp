#include<bits/stdc++.h>
using namespace std;

void display(list<int> ls){
    for(auto it = ls.begin(); it != ls.end(); it++){
        cout << *it << " ";
    } cout << endl;

    if(!ls.empty()){
        cout << "List is empty" << endl;
    }
}

void siz(list<int> ls){
    cout << "Size of list is: " << ls.size() << endl;
}

int main(){
    list<int> ls;
    ls.push_back(8); display(ls); // 8
    ls.push_front(7); display(ls); // 7 8
    ls.push_front(6); display(ls); // 6 7 8
    ls.emplace_front(5); display(ls); // 5 6 7 8
    ls.emplace_back(9); display(ls); // 5 6 7 8 9
    siz(ls);
    ls.pop_back();  display(ls); // 5 6 7 8
    ls.pop_front(); display(ls); // 6 7 8
    siz(ls);
    ls.remove(7); display(ls); // 6 8
    ls.clear(); display(ls); // list is empty
}