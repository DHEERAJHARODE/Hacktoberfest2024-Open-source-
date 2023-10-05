#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int solve(string& s, int k)
{
	if (s.size() == 0) return 0;
	unordered_map<char, int> mp;
	int num = 0, left = 0;

	for (int i = 0; i < s.size(); i++) {
		mp[s[i]]++;
		while (mp.size() > k) {
			mp[s[left]]--;
			if (mp[s[left]] == 0) {
				mp.erase(s[left]);
			}
			left++;
		}
		num += i - left + 1;
	}
	return num;
}

int countSub(string& s, int k)
{
	return solve(s, k) - solve(s, k - 1);
}

int main()
{
	string s1 = "pqpqs";
	int k = 2;
	cout << "Total substrings with exactly " << k
		<< " distinct characters : "
		<< countSub(s1, k) << endl;

	string s2 = "aabab";
	k = 2;
	cout << "Total substrings with exactly " << k
		<< " distinct characters : "
		<< countSub(s2, k) << endl;
}
