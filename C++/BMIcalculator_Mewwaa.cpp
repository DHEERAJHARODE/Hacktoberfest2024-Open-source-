/*
Author: Ewa Zalewska
Concept: BMI calculator
Github: https://github.com/Mewwaa
*/

#include<iostream>
#include <cmath>

using namespace std;
int main()
{
    float bmi,w,h,sm;
    string score;
    cout<<"Enter your weight in kilograms : ";
        cin>>w;
    cout<<"Enter your height in centimeters : ";
        cin>>h;
    sm = (h/100)*(h/100);

    bmi=(w/sm);

    if(bmi>25)
        score="overweight, you should consider changing your diet";
    else if(bmi>18.5 && bmi<=25)
        score="optimal, your diet is good";
    else
        score="underweight, you should consider changing your diet";

     cout<<"Your BMI is : "<<bmi<<endl;
    cout<<"You're "<<score<<endl;

    return 0;
}
