#include <bits/stdc++.h>
using namespace std;
int shortestChainLen(
string start, string target,
set<string>& D)
{

	if(start == target)
	return 0;

	// If the target string is not
	// present in the dictionary
	if (D.find(target) == D.end())
		return 0;

	// To store the current chain length
	// and the length of the words
	int level = 0, wordlength = start.size();

	// Push the starting word into the queue
	queue<string> Q;
	Q.push(start);

	// While the queue is non-empty
	while (!Q.empty()) {

		// Increment the chain length
		++level;

		// Current size of the queue
		int sizeofQ = Q.size();
		for (int i = 0; i < sizeofQ; ++i) {

			// Remove the first word from the queue
			string word = Q.front();
			Q.pop();

			// For every character of the word
			for (int pos = 0; pos < wordlength; ++pos) {

				// Retain the original character
				// at the current position
				char orig_char = word[pos];

				// Replace the current character with
				// every possible lowercase alphabet
				for (char c = 'a'; c <= 'z'; ++c) {
					word[pos] = c;

					// If the new word is equal
					// to the target word
					if (word == target)
						return level + 1;

					// Remove the word from the set
					// if it is found in it
					if (D.find(word) == D.end())
						continue;
					D.erase(word);

					// And push the newly generated word
					// which will be a part of the chain
					Q.push(word);
				}

				// Restore the original character
				// at the current position
				word[pos] = orig_char;
			}
		}
	}

	return 0;
}

// Driver program
int main()
{
	// make dictionary
	set<string> D;
	D.insert("poon");
	D.insert("plee");
	D.insert("same");
	D.insert("poie");
	D.insert("plie");
	D.insert("poin");
	D.insert("plea");
	string start = "toon";
	string target = "plea";
	cout << "Length of shortest chain is: "
		<< shortestChainLen(start, target, D);
	return 0;
}
