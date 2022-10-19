class Solution {
public:
    int compareVersion(string s1, string s2) {
        int n1 = s1.length(); // extracting length of string s1
        int n2 = s2.length(); //extracting length of string s2
        
        int i = 0, j = 0; // variables(pointers) used for moving
        
        int number1 = 0, number2 = 0;  // numbers that generated between any two dots of the strings
        
        // start traversing from string 1 and string 2
        while(i < n1 || j < n2)
        {
            // generating number between dots for string s1
            while(i < n1 && s1[i] != '.')
            {
                number1 = number1 * 10 + (s1[i] - '0');
                i++;
            }
            
            // generating number between dots for string s2
            while(j < n2 && s2[j] != '.')
            {
                number2 = number2 * 10 + (s2[j] - '0');
                j++;
            }
            
            // if number1 is greater than number2, from here return 1
            if(number1 > number2)
            {
                return 1;
            }
            
             // if number1 is less than number2, from here return -1
            if(number1 < number2)
            {
                return -1;
            }
            
            // if equal then we have to proceed further
            // again give numbers to zero, as we again generate numbers b/w dots 
            number1 = 0, number2 = 0;
            
            // move both pointers
            i++;
            j++;
        }
        
        // after traversing whole string, if all the versions are equal, that means
        // strings are equal, so return 0
        return 0;
    }
};