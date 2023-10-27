#include <stdio.h>
#include <string.h>


char* decimalToRoman(int num) {
    static char romanNumeral[20]; \
    memset(romanNumeral, 0, sizeof(romanNumeral));

    
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int i = 0; // Index for values and symbols arrays
    while (num > 0) {
        while (num >= values[i]) {
            strcat(romanNumeral, symbols[i]);
            num -= values[i];
        }
        i++;
    }

    return romanNumeral;
}

int main() {
    int decimalNumber;
    printf("Enter a decimal number (up to 9 digits): ");
    scanf("%d", &decimalNumber);

    if (decimalNumber >= 1 && decimalNumber <= 999999999) {
        char* roman = decimalToRoman(decimalNumber);
        printf("Roman Numeral: %s\n", roman);
    } else {
        printf("Please enter a valid decimal number between 1 and 999999999.\n");
    }

    return 0;
}
