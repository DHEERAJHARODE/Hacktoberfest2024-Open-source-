#include <iostream>
using namespace std;

//bruth force

// int main(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n][m];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];
//         }
//     }
//     cout<<"Matrix is: "<<endl;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     int x;
//     cout<<"Enter the key which you want to seacrh  in matrix: "<<endl;
//     cin>>x;
//     bool flag =false;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j]==x){
//                 cout<<"Value iss found at: "<<i<<" "<<j<<endl;
//                 flag=true;
//             }
//         }
//     }
//     if(flag){
//         cout<<"Value is found"<<endl;
//     }
//     else{
//         cout<<"vale is not found"<<endl;
//     }
//     return(0);
// }

// optimised method

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Matrix is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int target;
    cin >> target;

    int r = 0, c = m - 1;
    bool flag = false;
    while (r < n && c >= 0)
    {
        if (arr[r][c] > target)
        {
            cout << r << " " << c << endl; // positon of elemnt
            flag = true;
        }
        if (arr[r][c] > target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    if (flag)
    {
        cout << "element found";
    }
    else
    {
        cout << "element is not exit";
    }
    return (0);
}
