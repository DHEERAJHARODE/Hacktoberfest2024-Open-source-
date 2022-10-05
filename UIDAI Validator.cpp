# UIDAI-Validator



#include<iostream>
#include<regex>
#include<conio.h>
using namespace std;

bool isValidPanCardNo(string panCardNo)
{
	const regex pattern("[A-Z]{5}[0-9]{4}[A-Z]{1}");
	if(panCardNo.empty())
	{
		cout<<"You Did'nt Enter Anything";
	}
	if(regex_match(panCardNo, pattern))
	{
		cout<<"This is a Valid PANcard Number!";
	}
	else
	{
		cout<<"This is not a Valid PANcard Number!";
	}
}

bool isValidLicenseNo(string str)
{
	const regex pattern("^(([A-Z]{2}[0-9]{2})( "
                        ")|([A-Z]{2}-[0-9]{2}))"
                        "((19|20)[0-"
                        "9][0-9])[0-9]{7}$");
	
	if(str.empty())
	{
		cout<<"You Did'nt Enter Anything";
	}
	if(regex_match(str, pattern))
	{
		cout<<"This is a Valid Driving License!";
	}
	else
	{
		cout<<"This is not a Valid Driving License!";
	}
}

bool isValidPassportNo(string str)
{
	const regex pattern(
        "^[A-PR-WYa-pr-wy][1-9]"
         "\\d\\s?\\d{4}[1-9]$");
	
	if(str.empty())
	{
		cout<<"You Did'nt Enter Anything";
	}
	if(regex_match(str, pattern))
	{
		cout<<"This is a Valid Passport!";
	}
	else
	{
		cout<<"This is not a Valid Passport!";
	}
}

bool isValidAadharNumber(string str)
{
	const regex pattern("^[2-9]{1}[0-9]{3}\\s[0-9]{4}\\s[0-9]{4}$");
	
	if(str.empty())
	{
		cout<<"You Did'nt Enter Anything";
	}
	if(regex_match(str, pattern))
	{
		cout<<"This is a Valid Aadhar Number!";
	}
	else
	{
		cout<<"This is not a Valid Aadhar Number!";
	}
}

int main()
{
	string str1;
	int b;
	cout<<"Enter Your Choice"<<endl;
	cout<<"1.Verify PANcard Number"<<endl;
	cout<<"2.Verify Driving License"<<endl;
	cout<<"3.Verify Indian Passport"<<endl;
	cout<<"4.Verify Aadhar Number"<<endl;
	cout<<"5.Exit"<<endl;
	cin>>b;
	switch (b)
	{
	case 1: {
				cout<<"Enter PANCard number"<<endl;
				std::cin.clear();
        		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        		getline(std::cin, str1);
				cout<<isValidPanCardNo(str1)<<endl;
			}
		break;
	case 2: {	
				cout<<"Enter Driving License number"<<endl;
				std::cin.clear();
        		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        		getline(std::cin, str1);
				cout<<isValidLicenseNo(str1)<<endl;
		break;
	}
	case 3: {	
				cout<<"Enter Passport number"<<endl;
				std::cin.clear();
        		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        		getline(std::cin, str1);
				cout<<isValidPassportNo(str1)<<endl;
		break;
	}
	case 4: {	
				cout<<"Enter Aadhar Card number (XXXX XXXX XXXX)"<<endl;
				std::cin.clear();
        		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        		getline(std::cin, str1);
				cout<<isValidAadharNumber(str1)<<endl;
		break;
	}
	case 5:
			break;
	default: cout<<"Invalid Option";
		break;
	}
	return 0;
}