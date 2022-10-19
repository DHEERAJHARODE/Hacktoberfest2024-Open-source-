#include<iostream>
using namespace std;
int main(){
int n,  cpu[10], w[10], trun[10],arive[10], i;

cout<< "Enter Prosses Number ";
cin>>n;
for(i=0; i<n;i++){
  //  cout<<" Cpu time  of p" << (i+1) << endl ;
cout<< "Enter Prosses Number ";
cin>>cpu[i];
}
w[0]=0;
for(i=1; i<n; i++){
    w[i]=w[i-1]+cpu[i-1];
// cout<< "Cpu waiting time of P"<<w << endl ;
}
for (i=0; i<n ; i++){
    trun[i]=w[i]+cpu[i];
 //   cout<< "Cpu waiting time of P" <<trun<< endl ;
}
cout<< "Process     CPU     W.T     😭";
for(i=0;i<n;i++){

    cout<<"p"<<i+1<<"      "<<i+1<<"        "<<w<<"     "<<trun<<endl;
}
for(i-0;i<n;i++){
  float  sum_w=sum_w+w[i];
  float  sum_t=sum_t+trun[i];
}
float sum_w=sum_w/n;
float sum_t=sum_t/n;
cout<< "Average Waiting time "<<sum_w;
cout<<"Avarage Truning Time "<<sum_t;
return 0;
}