#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    int compscore=0, playerscore=0;
    char options[]={'r','p','s'};
    srand(time(NULL));
    cout<<"Welcome to rock paper scissors game\n";
    cout<<"You have 5 turns to play in a game\n";
    cout<<"Let's start the game\n";
    while(1==1)
    {
        char userinput;
        cout<<"_____________________________________\n";
        cout<<"Enter your choice : ";
        cin>>userinput;
        int compinput=rand()%3;
        if(options[compinput]=='r' && userinput=='r')
        {
            cout<<"Computer : "<<options[compinput]<<"   Yours : "<<userinput<<endl;
            cout<<"Nothing will happen\n";
            cout<<"Computer's score is "<<compscore<<" Your score is "<<playerscore<<endl;
        }
        else if(options[compinput]=='r' && userinput=='p')
        {
            cout<<"Computer : "<<options[compinput]<<"   Yours : "<<userinput<<endl;
            cout<<"Paper captures rock. You get a point\n";
            playerscore++;
            cout<<"Computer's score is "<<compscore<<" Your score is "<<playerscore<<endl;
        }
        else if(options[compinput]=='r' && userinput=='s')
        {
            cout<<"Computer : "<<options[compinput]<<"   Yours : "<<userinput<<endl;
            cout<<"Rock breaks scissor. Computer gets a point\n";
            compscore++;
            cout<<"Computer's score is "<<compscore<<" Your score is "<<playerscore<<endl;
        }
        else if(options[compinput]=='p' && userinput=='r')
        {
            cout<<"Computer : "<<options[compinput]<<"   Yours : "<<userinput<<endl;
            cout<<"Paper captures rock. Computer gets a point\n";
            compscore++;
            cout<<"Computer's score is "<<compscore<<" Your score is "<<playerscore<<endl;
        }
        else if(options[compinput]=='p' && userinput=='p')
        {
            cout<<"Computer : "<<options[compinput]<<"   Yours : "<<userinput<<endl;
            cout<<"Nothing will happen\n";
            cout<<"Computer's score is "<<compscore<<" Your score is "<<playerscore<<endl;
        }
        else if(options[compinput]=='p' && userinput=='s')
        {
            cout<<"Computer : "<<options[compinput]<<"   Yours : "<<userinput<<endl;
            cout<<"Scissor tears paper. You get a point\n";
            playerscore++;
            cout<<"Computer's score is "<<compscore<<" Your score is "<<playerscore<<endl;
        }
        else if(options[compinput]=='s' && userinput=='r')
        {
            cout<<"Computer : "<<options[compinput]<<"   Yours : "<<userinput<<endl;
            cout<<"Rock breaks scissors. You get a point\n";
            playerscore++;
            cout<<"Computer's score is "<<compscore<<" Your score is "<<playerscore<<endl;
        }
        else if(options[compinput]=='s' && userinput=='p')
        {
            cout<<"Computer : "<<options[compinput]<<"   Yours : "<<userinput<<endl;
            cout<<"Scissor tears paper. Computer gets a point\n";
            compscore++;
            cout<<"Computer's score is "<<compscore<<" Your score is "<<playerscore<<endl;
        }
        else if(options[compinput]=='s' && userinput=='s')
        {
            cout<<"Computer : "<<options[compinput]<<"   Yours : "<<userinput<<endl;
            cout<<"Nothing will happen\n";
            cout<<"Computer's score is "<<compscore<<" Your score is "<<playerscore<<endl;
        }
        if(compscore==5)
        {
            cout<<"Computer won the game\n";
            break;
        }
        else if(playerscore==5)
        {

            cout<<"You won the game. Congratulations\n";
            break;
        }

    }

    return 0;
}