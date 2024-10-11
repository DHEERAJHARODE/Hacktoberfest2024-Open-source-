#include <bits/stdc++.h>
using namespace std;

// Function to count substrings of length K with no
// repeating characters
int numKLenSubstrNoRepeats(const string& S, int K)
{
    if (K > S.size()) {
        return 0; // K cannot be larger than string length
    }

    // Use unordered_map to store character frequencies
    unordered_map<char, int> freq;
    int count_of_good_lenK_windows = 0;
    int left = 0, right = 0;

    while (right < S.size()) {
        // Add character to frequency map
        freq[S[right]]++;

        // tep 1: Slide window until no duplicates**
        while (freq[S[right]] > 1) {
            // Remove character from left side of window
            freq[S[left]]--;
            left++;
        }

        //  Step 2: Count good windows**
        if (right - left + 1 == K) {
            count_of_good_lenK_windows++;

            // Move left window and adjust frequency
            freq[S[left]]--;
            left++;
        }

        right++;
    }

    return count_of_good_lenK_windows;
}

int main()
{
    string S = "geeksforgeeks";
    int K = 5;

    int count = numKLenSubstrNoRepeats(S, K);
    cout << "Number of substrings of length " << K
         << " with no repeating characters: " << count
         << endl;

    return 0;
}
