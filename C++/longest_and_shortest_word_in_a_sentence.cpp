#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    cin.ignore();

    int len = str.length();



 	int a = 0, b = 0;


	int min_length = len, min_start_index = 0, max_length = 0, max_start_index = 0;

	
	while (b <= len)
	{
		if (b < len && str[b] != ' ')
			b++;
		
		else
		{
			
			int curr_length = b - a;
		
			if (curr_length < min_length)
			{
				min_length = curr_length;
				min_start_index = a;
			}
			
			if (curr_length > max_length)
			{
				max_length = curr_length;
				max_start_index = a;
			}
			b++;
			a = b;
		}
	}
	
	
	string short_word = str.substr(min_start_index, min_length);
	string long_word = str.substr(max_start_index, max_length);


    cout<<"The Shortest Word is: "<<short_word<<"\n";
    cout<<"The Longest Word is: "<<long_word<<"\n";
    return 0;
}
