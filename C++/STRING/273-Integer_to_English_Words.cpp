#include <bits/stdc++.h>
using namespace std;

string numberToWordsHelper(int num);

string numberToWords(int num) {
    if (num == 0)
        return "Zero";

    string bigString[] = {"Thousand", "Million", "Billion"};
    string result = numberToWordsHelper(num % 1000);
    num /= 1000;

    for (int i = 0; i < 3; ++i) {
        if (num > 0 && num % 1000 > 0) {
            result = numberToWordsHelper(num % 1000) + bigString[i] + " " + result;
        }
        num /= 1000;
    }

    return result.empty() ? result : result.substr(0, result.size() - 1); // Trim trailing space
}

string numberToWordsHelper(int num) {
    string digitString[] = {"Zero", "One", "Two",   "Three", "Four",
                            "Five", "Six", "Seven", "Eight", "Nine"};
    string teenString[] = {"Ten", "Eleven",  "Twelve",  "Thirteen",
                           "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                           "Eighteen", "Nineteen"};
    string tenString[] = {"", "", "Twenty",  "Thirty", "Forty",
                          "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string result = "";
    if (num > 99) {
        result += digitString[num / 100] + " Hundred ";
    }
    num %= 100;
    if (num < 20 && num > 9) {
        result += teenString[num - 10] + " ";
    } else {
        if (num >= 20) {
            result += tenString[num / 10] + " ";
        }
        num %= 10;
        if (num > 0) {
            result += digitString[num] + " ";
        }
    }

    return result;
}

int main() {
    int num = 1234567;
    cout << numberToWords(num) << endl;  // Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
    return 0;
}
