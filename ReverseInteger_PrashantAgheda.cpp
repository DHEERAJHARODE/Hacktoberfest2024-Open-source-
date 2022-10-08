#include<iostream>
using namespace std;

int reverseNumber(int n)
{
    int digit = 0, answer = 0;
    while(n != 0)
    {
        digit = n % 10;

        if( (answer > INT_MAX/10) || (answer < INT_MIN/10) )
        {
            cout << "\nInteger value out of range...";
            return 0;
        }

        answer = (answer * 10) + digit;
        n = n / 10;
    }

    return answer;
}


int main()
{
    int number = 0, answer = 0;
    cout << "* Enter the Number: ";
    cin >> number;
    
    answer = reverseNumber(number);

    cout << "\nReversed Number: " << answer;

    return 0;
}
