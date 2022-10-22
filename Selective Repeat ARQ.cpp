/*
Sukhmeet Singh Bawa
20070122146
CSB
*/

#include <bits/stdc++.h>

using namespace std;

queue<int> framesNotRecieved;

void transmitFrame(int frameIndex)
{
	cout << "Sending Frame " << frameIndex << " \t";
	if (!(rand() % 2))
	{
		cout << "Recieved Frame : " << frameIndex << endl;
	}
	else
	{
		cout << "Not Recieved Frame : " << frameIndex << endl;
		framesNotRecieved.push(frameIndex);
	}
}

int main(int argc, char const *argv[])
{
	srand(time(0));
	int windowSize = 0, frameSize = 0, index = 0;
	cout << "Enter Frame Size: ";
	cin >> frameSize;
	cout << "Enter Window Size: ";
	cin >> windowSize;
	int numberOfWindowsUsed = 0;
	frameSize--;
	int limitor = windowSize;
	do
	{
		cout << "Window " << numberOfWindowsUsed << endl;
		if (!framesNotRecieved.empty())
		{
			limitor = windowSize - framesNotRecieved.size();
			for (int i = 0; i < framesNotRecieved.size(); i++)
			{
				transmitFrame(framesNotRecieved.front());
				framesNotRecieved.pop();
			}
		}
		else
		{
			limitor = windowSize;
		}
		for (int k = index; k < index + limitor && k <= frameSize; k++)
		{
			// cout << k << endl;
			transmitFrame(k);
		}
		numberOfWindowsUsed++;
		index += limitor;
	} while (!framesNotRecieved.empty() || numberOfWindowsUsed < frameSize / windowSize);
	int operations = 0;
	return 0;
}
