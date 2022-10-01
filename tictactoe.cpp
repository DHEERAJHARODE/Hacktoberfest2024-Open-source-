#include<bits/stdc++.h>
using namespace std;
void print(int ttt[])
{
    // system("cls");
    for(int i=1; i<=9;i++){
        cout<<ttt[i-1]<<" ";
        if(i%3==0){
            cout<<endl;
        }
    }
}
int check(int ttt[], int id1, int id2, int id3){
    if(ttt[id1]==2){
        return id1;
    }else if(ttt[id2]==2){
        return id2;
    }else{
        return id3;
    }
}
int whereToPlace(int ttt[])
{
    if(ttt[0] * ttt[1] * ttt[2] == 50){
        return check(ttt,0,1,2);
    }else if(ttt[3] * ttt[4] * ttt[5] == 50){
        return check(ttt,3,4,5);
    }else if(ttt[6] * ttt[7] * ttt[8] == 50){
        return check(ttt,6,7,8);
    }else if(ttt[0] * ttt[3] * ttt[6] == 50){
        return check(ttt,0,3,6);
    }else if(ttt[1] * ttt[4] * ttt[7] == 50){
        return check(ttt,1,4,7);
    }else if(ttt[2] * ttt[5] * ttt[8] == 50){
        return check(ttt,2,5,8);
    }else if(ttt[0] * ttt[4] * ttt[8] == 50){
        return check(ttt,0,4,8);
    }else if(ttt[2] * ttt[4] * ttt[6] == 50){
        return check(ttt,2,4,6);
    }

    if(ttt[0] * ttt[1] * ttt[2] == 18){
        return check(ttt,0,1,2);
    }else if(ttt[3] * ttt[4] * ttt[5] == 18){
        return check(ttt,3,4,5);
    }else if(ttt[6] * ttt[7] * ttt[8] == 18){
        return check(ttt,6,7,8);
    }else if(ttt[0] * ttt[3] * ttt[6] == 18){
        return check(ttt,0,3,6);
    }else if(ttt[1] * ttt[4] * ttt[7] == 18){
        return check(ttt,1,4,7);
    }else if(ttt[2] * ttt[5] * ttt[8] == 18){
        return check(ttt,2,5,8);
    }else if(ttt[0] * ttt[4] * ttt[8] == 18){
        return check(ttt,0,4,8);
    }else if(ttt[2] * ttt[4] * ttt[6] == 18){
        return check(ttt,2,4,6);
    }else
    return 99;

}

// function for winning condition
int whoWins(int ttt[]){
    if(((ttt[0] * ttt[1] * ttt[2] )== 125)
        or
        ((ttt[3] * ttt[4] * ttt[5]) == 125)
        or
        ((ttt[6] * ttt[7] * ttt[8]) == 125)
        or
        ((ttt[0] * ttt[3] * ttt[6]) == 125)
        or
        ((ttt[1] * ttt[4] * ttt[7]) == 125)
        or
        ((ttt[2] * ttt[5] * ttt[8]) == 125)
        or
        ((ttt[0] * ttt[4] * ttt[8]) == 125)
        or
        ((ttt[2] * ttt[4] * ttt[6]) == 125)
    ){
        return 5;
    }else if(((ttt[0] * ttt[1] * ttt[2] )== 27)
        or
        ((ttt[3] * ttt[4] * ttt[5]) == 27)
        or
        ((ttt[6] * ttt[7] * ttt[8]) == 27)
        or
        ((ttt[0] * ttt[3] * ttt[6]) == 27)
        or
        ((ttt[1] * ttt[4] * ttt[7]) == 27)
        or
        ((ttt[2] * ttt[5] * ttt[8] )== 27)
        or
        ((ttt[0] * ttt[4] * ttt[8]) == 27)
        or
        ((ttt[2] * ttt[4] * ttt[6]) == 27)
    ){
        return 3;
    }else
    return 2;

}

// for changing the grid board
void makeChanges(int ttt[], int index){
    ttt[index-1]=3;
}
int main(){
    int ttt[9];
    ttt[0]=5;
    for(int i=1; i<9;i++){
        ttt[i]=2;
    }
    cout<<"---- The game is between player and computer ----"<<endl;
    cout<<"5 for computer"<<endl;
    cout<<"3 for player"<<endl;
    cout<<"-------LET'S START-------"<<endl;
    print(ttt);
 bool player =1;
    int temp =0;
    int index ;
    for(int i=0; i<=7;i++){
        temp++;
        if(player){
            cout<<"It's your turn"<<endl;
            cin>>index;
            cout<<"-------***********-------"<<endl;
            makeChanges(ttt,index);
            print(ttt);
            player = !player;
            cout<<"-------***********-------"<<endl;
        }else{
            int idx = whereToPlace(ttt);
            if(idx==99){
                for(int i=0;i<9;i=i+2){
                    if(ttt[i]==2){
                        ttt[i]=5;
                        break;
                    }
                }
            }else{
                ttt[idx]=5;
            }
            player = !player;
            print(ttt);
        }
        if(i>=3){
            if(whoWins(ttt)==5){
                cout<<"Computer wins"<<endl;
                temp =0;
                break;

            }else if(whoWins(ttt)==3){
                cout<<"Player wins"<<endl;
                temp=0;
                break;
            }else{
                continue;
            }
        }
        if(temp==7 or temp ==8){
            cout<<"Match Drawn"<<endl;
        }
    }
    return 0;
}
