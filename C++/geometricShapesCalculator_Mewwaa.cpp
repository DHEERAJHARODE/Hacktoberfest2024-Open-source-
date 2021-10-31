/*
Author: Ewa Zalewska
Concept: Geometric shapes calculator
Github: https://github.com/Mewwaa
*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include<cstdlib>
using namespace std;

int main()
{
    int form,dimesion2,dimension3;
    cout<<"!!! Please write lengths only in centimetres, otherwise, this calculator won't count results right !!!"<<endl;
    cout<<"-----------------"<<endl;
    cout<<"Chose if the area of shape you want to calculate is in 2D or in 3D"<<endl;
    cout<<"1 - 2D"<<endl;
    cout<<"2 - 3D"<<endl;
    cout<<"-----------------"<<endl;
    cin>>form;
    cout<<"-----------------"<<endl;

    switch (form) {
    case 1:
        cout<<"Chose the shape which area you want to calculate"<<endl;
        cout<<"1 - square"<<endl;
        cout<<"2 - rectangle"<<endl;
        cout<<"3 - triangle"<<endl;
        cout<<"4 - parallelogram"<<endl;
        cout<<"5 - rhombus"<<endl;
        cout<<"6 - trapezoid"<<endl;
        cout<<"7 - circle"<<endl;
        cout<<"-----------------"<<endl;
        cin>>dimesion2;
        cout<<"-----------------"<<endl;
        switch (dimesion2) {
        case 1:
            double a1,result1;
            if (dimesion2 == 1){
                cout<<"What's the value of side length?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>a1;
                cout<<"-----------------"<<endl;
                result1=a1*a1;
                cout<<"Area of your square in square cm is: ";
                printf("%.2f",result1);

            }else{

            }
        break;
        case 2:
            double a2,b2,result2;
            if (dimesion2 == 2){
                cout<<"What's the value of length side a?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>a2;
                cout<<"-----------------"<<endl;
                cout<<"What's the value of length side b?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>b2;
                cout<<"-----------------"<<endl;
                result2=a2*b2;
                cout<<"Area of your rectangle in square cm is: ";
                printf("%.2f",result2);

            }else{

            }
        break;
        case 3:
            double a3,h3,result3;
            if (dimesion2 == 3){
                cout<<"What's the length of base?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>a3;
                cout<<"-----------------"<<endl;
                cout<<"What's the value of height?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>h3;
                cout<<"-----------------"<<endl;
                result3=(a3*h3)/2;
                cout<<"Area of your traingle in square cm is: ";
                printf("%.2f",result3);

            }else{

            }
        break;
        case 4:
            double a4,h4,result4;
            if (dimesion2 == 4){
                cout<<"What's the length of base?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>a4;
                cout<<"-----------------"<<endl;
                cout<<"What's the value of height?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>h4;
                cout<<"-----------------"<<endl;
                result4=a4*h4;
                cout<<"Area of your parallelogram in square cm is: ";
                printf("%.2f",result4);

            }else{

            }
        break;
        case 5:
            double e5,f5,result5;
            if (dimesion2 == 5){
                cout<<"What's the length of the shorter diagonal?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>e5;
                cout<<"-----------------"<<endl;
                cout<<"What's the length of the longer diagonal?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>f5;
                cout<<"-----------------"<<endl;
                result5=(e5*f5)/2;
                cout<<"Area of your rhombus in square cm is: ";
                printf("%.2f",result5);

            }else{

            }
        break;
        case 6:
            double a6,b6,h6,result6;
            if (dimesion2 == 6){
                cout<<"What's the length of the shorter base?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>a6;
                cout<<"-----------------"<<endl;
                cout<<"What's the length of the longer base?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>b6;
                cout<<"-----------------"<<endl;
                cout<<"What's the value of height?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>h6;
                cout<<"-----------------"<<endl;
                result6=(((a6+b6)*h6)/2);
                cout<<"Area of your trapezoid in square cm is: ";
                printf("%.2f",result6);

            }else{

            }
        break;
        case 7:
            double r7,result7;
            if (dimesion2 == 7){
                cout<<"What's the radius of the circle?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>r7;
                cout<<"-----------------"<<endl;
                result7=M_PI*(r7*r7);
                cout<<"Area of your circle in square cm is: ";
                printf("%.2f",result7);

            }else{

            }
        break;
        default:
        cout << "Something goes wrong..."<<endl;
        }





    break;
    case 2:
        cout<<"Chose the shape which area you want to calculate"<<endl;
        cout<<"1 - circular cylinder"<<endl;
        cout<<"2 - cube"<<endl;
        cout<<"3 - square pyramid"<<endl;
        cout<<"4 - sphere"<<endl;
        cout<<"5 - hemisphere"<<endl;
        cout<<"-----------------"<<endl;
        cin>>dimension3;
        cout<<"-----------------"<<endl;
        switch (dimension3) {
        case 1:
            double r11,h11,result11;
            if (dimension3 == 1){
                cout<<"What's the radius of cylinder's base?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>r11;
                cout<<"-----------------"<<endl;
                cout<<"What's cylinder's height?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>h11;
                cout<<"-----------------"<<endl;
                result11=(2*M_PI*(r11*r11))+(2*M_PI*r11*h11);
                cout<<"Area of your circular cylinder in square cm is: ";
                printf("%.2f",result11);

            }else{

            }
        break;
        case 2:
            double a22,result22;
            if (dimension3 == 2){
                cout<<"What's the value of length side a?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>a22;
                cout<<"-----------------"<<endl;
                result22=6*(a22*a22);
                cout<<"Area of your cube in square cm is: ";
                printf("%.2f",result22);

            }else{

            }
        break;
        case 3:
            double a33,h33,result33;
            if (dimension3 == 3){
                cout<<"What's the length of base?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>a33;
                cout<<"-----------------"<<endl;
                cout<<"What's the value of height?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>h33;
                cout<<"-----------------"<<endl;
                result33=(a33*a33)+(4*((a33*h33)/2));
                cout<<"Area of your pyramid in square cm is: ";
                printf("%.2f",result33);

            }else{

            }
        break;
        case 4:
            double r44,result44;
            if (dimension3 == 4){
                cout<<"What's the radius of sphere?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>r44;
                cout<<"-----------------"<<endl;
                result44=4*M_PI*(r44*r44);
                cout<<"Area of your sphere in square cm is: ";
                printf("%.2f",result44);

            }else{

            }
        break;
        case 5:
            double r55,result55;
            if (dimension3 == 5){
                cout<<"What's the radius of hemisphere?"<<endl;
                cout<<"-----------------"<<endl;
                cin>>r55;
                cout<<"-----------------"<<endl;
                result55=3*M_PI*(r55*r55);
                cout<<"Area of your hemisphere in square cm is: ";
                printf("%.2f",result55);
            }else{

            }
        break;
        default:
        cout << "Something goes wrong..."<<endl;
        }

    break;
    default:
    cout << "Something goes wrong..."<<endl;
    }



}
