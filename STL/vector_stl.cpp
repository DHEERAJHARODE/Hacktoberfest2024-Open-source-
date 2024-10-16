#include<bits/stdc++.h>
using namespace std;

void vector_explain(){
    vector<int>v;

    v.push_back(1);
    v.emplace_back(20);

    vector<pair<int,int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);

    vector<int> ve(5,100);

    vector<int>v1(5,20);
    vector<int>v2 = {10,20,30,40,50};

    // Iterator
    vector <int>::iterator it = v2.begin();
    it++;
    cout<<*(it)<<" ";

    it = it+2;
    cout<<*(it)<<endl;

    vector<int>::iterator it1 = v2.end();
    cout<<*(it1-1);

    //Printing Vector 
    for(vector<int>::iterator it = v2.begin();it!=v2.end();it++)
        cout<<*(it)<<" ";
    cout<<endl;
    for(auto it = v2.begin();it!=v2.end();it++)
        cout<<*(it)<<" ";
    cout<<endl;
    for(auto it : v2)
        cout<<it<<"\t";


}

void vector_delete()
{
    vector<int>v = {10,20,30,40,50};

    v.erase(v.begin()+1);
    for(auto it : v)
        cout<<it<<"\t"; // 10 30 40 50

    v.erase(v.begin()+1,v.begin()+4);
    for(auto it : v)
        cout<<it<<"\t"; // 10 , 50

}
void vector_insert()
{
    vector<int>v = {10 ,20};
    v.insert(v.begin()+1,15);
    /*for(auto it : v)
        cout<<it<<"\t"; */

    //cout<<endl;

    v.insert(v.begin()+3,2,30);
    /*for(auto it : v)
        cout<<it<<"\t"; */

    // Copy Vector

    vector<int> cpy = {5,8};
    v.insert(v.begin(),cpy.begin(),cpy.end()) ;
    for(auto it : v)
        cout<<it<<"\t";
    
    cout<<endl;

    cout << v.size();

    v.pop_back();

    cout<<endl;
    for(auto it : v)
        cout<<it<<"\t";

    vector<int> v1 = {10,20};
    vector<int> v2 = {30,40};

    v2.swap(v1);

    cout<<endl;
    for(auto it : v2)
        cout<<it<<"\t";

    cout<<endl;
    for(auto it : v1)
        cout<<it<<"\t";
    
    v1.clear();

    cout<<endl;
    cout<<v1.empty();


}

int main(){
    //vector_explain();
    //vector_delete();
    vector_insert();
    return 0;
}
