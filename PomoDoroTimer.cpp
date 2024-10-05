#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

void countdown(int seconds, int BreakTime)
{
    int remainingHours = seconds / 3600;
    while (remainingHours > 0)
    {
        int hourseconds = 3600;
        cout << "Starting One hour Pomodoro Session.. !!!!!" << endl;

        // countdown 1 hour
        while (hourseconds > 0)
        {

            int hours = hourseconds / 3600;
            int minutes = (hourseconds % 3600) / 60; // it givese the real time remaining minutes
            int sec = hourseconds % 60;              // it gives the real time remaining minutes
            cout << setw(2) << setfill('0') << hours << " : "
                 << setw(2) << setfill('0') << minutes << " : "
                 << setw(2) << setfill('0') << sec << '\r';
            cout.flush();
            Sleep(1000);
            --hourseconds;
        }

        --remainingHours;
        if (remainingHours)
        {
            cout << "One hour Completed Break Time!!!!!!!!!!" << endl;

            int breakSeconds = BreakTime * 60;
            while (breakSeconds > 0)
            {
                int bminutes = breakSeconds / 60;
                int bsec = breakSeconds % 60;

                cout << " Break Timer : "
                     << setw(2) << setfill('0') << bminutes << " : "
                     << setw(2) << setfill('0') << bsec << '\r';
                cout.flush();
                Sleep(1000);
                --breakSeconds;
            }
            cout << "Break is over!!! Starting Another Pomodoro Session!!! " << endl;
        }
    }

    cout << "All Pomodoro are done. Time's Up and I'm Proud of you so much for finishing this study/work session!!! Mwahhhh" << endl;
}

int main()
{

    int hours, totalSeconds, breaktime;
    cout << "Set the Pomodoro timer(hours): " << endl;
    cin >> hours;
    while (true)
    {
        cout << "Set the break time for Study Sessions (Max 10 mins only): " << endl;
        cin >> breaktime;
        if (breaktime <= 10)
        {
            break;
        }
        cout << "Not okay bro!! You can't take longer break!!! YOU GOTTA WORK OR GO DESTROY YOUR LIFE LAZY ASS" << endl;
    }

    totalSeconds = hours * 3600;
    countdown(totalSeconds, breaktime);

    return 0;
}

// Coded by Dipanshu Sahu , Github username - dipanshu447