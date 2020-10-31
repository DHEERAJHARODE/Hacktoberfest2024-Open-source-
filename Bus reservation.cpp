#include<conio.h>
#include<cstdio>
#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
static int p = 0;
class a
{
	char busn[5], driver[20], arrival[10], depart[10], from[20], to[20], seat[8][4][10];
	public: 
		void install();
		void allotment();
		void empty();
		void show();
		void avail();
		void position(int i);
}
bus[10];
void vline(char ch)
{
	for(int i = 80; i > 0;i--)
	cout<<ch;
}
void a::install()
{
	system("cls");
	cout<<"\n\n\n";
	cout<<"\t\t\tEnter the bus number: ";
	cin>>bus[p].busn;
	cout<<"\t\t\tEnter the driver name: ";
	cin>>bus[p].driver;
	cout<<"\t\t\tArrival time: ";
	cin>>bus[p].arrival;
	cout<<"\t\t\tDeparture time: ";
	cin>>bus[p].depart;
	cout<<"\t\t\tFrom:  ";
	cin>>bus[p].from;
	cout<<"\t\t\tTo: ";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
}
void a::allotment()
{
	system("cls");
	int seat;
	char number[5];
	top:
		cout<<"\n\n\n";
		cout<<"\t\t\tEnter the bus number: ";
		cin>>number;
		int n;
		for(n = 0;n <= p;n++)
		{
			if(strcmp(bus[n].busn, number)==0)
			break;
		}
		while(n <= p)
		{
			cout<<"\n\t\t\tEnter the seat number: ";
			cin>>seat;
			if(seat > 32)
			{
				cout<<"\n\t\t\tThere are only 32 seats available in this bus.";
			}else{
				if(strcmp(bus[n].seat[seat/4][(seat%4)-1], "None") == 0)
				{
					cout<<"\t\t\tEnter passenger's name: ";
					cin>>bus[n].seat[seat/4][(seat%4)-1];
					break;
				}else{
					cout<<"\n\t\t\tThe seat number is already reserved.";
				}
			}
			if(n>p)
			{
				cout<<"\n\t\t\tEnter correct bus number. ";
				goto top;
			}
		}
}
void a::empty()
{
	system("cls");
	for(int i = 0;i < 8; i++)
	{
		for(int j = 0; j < 4;j++)
		{
			strcpy(bus[p].seat[i][j], "None");
		}
	}
}
void a::show()
{
	system("cls");
	int n;
	char number[5];
	cout<<"\n\n\t\t\tEnter bus number: ";
	cin>>number;
	for(n = 0;n <= p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n <= p)
	{
		vline('*');
		cout<<"Bus number: \t"<<bus[n].busn<<"\nDriver : \t"<<bus[n].driver<<"\nArrival time: \t"<<bus[n].arrival<<"\nDeparture time: \t"<<bus[n].depart
		<<"\nFrom : \t"<<bus[n].from<<"\nTo : \t"<<bus[n].to<<"\n";
		vline('*');
		bus[0].position(n);
		int a = 1;
		for(int i = 0;i < 8;i++)
		{
			for(int j = 0;j < 4;j++)
			{
				a++;
				if(strcpy(bus[p].seat[i][j], "None")!= 0)
				cout<<"\nThe seat number "<<(a - 1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
			}
		}
		break;
	}
	if(n > p)
	cout<<"\n\nEnter correct bus number.";
}
void a::position(int l)
{
	system("cls");
	int s = 0,p = 0;
	for(int i = 0;i < 8;i++)
	{
		cout<<"\n";
		for(int j = 0;j < 4;j++)
		{
			s++;
			if(strcmp(bus[i].seat[i][j], "None") == 0)
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
				p++;
			}else{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
				p++;
			}
		}
	}
	cout<<"\n\nThere are "<<p<<" seats empty in the bus number: "<<bus[l].busn;
}
void a::avail()
{
	system("cls");
	for(int n = 0;n < p;n++)
	{
		vline('*');
		cout<<"Bus number: \t"<<bus[n].busn<<"\nDriver : \t"<<bus[n].driver<<"\nArrival time: \t"<<bus[n].arrival<<"\nDeparture time: \t"<<bus[n].depart
		<<"\nFrom : \t"<<bus[n].from<<"\nTo : \t"<<bus[n].to<<"\n";
		vline('*');
		vline('_');
	}
}
int main()
{
	system("cls");
	int w;
	while(1)
	{
		cout<<"\n\n\n";
		cout<<"\t\t\t**** BUS RESERVATION ****\n\n";
		cout<<"\t\t\t[1]. Install\n";
		cout<<"\t\t\t[2]. Reservation\n";
		cout<<"\t\t\t[3]. Show\n";
		cout<<"\t\t\t[4]. Buses available\n";
		cout<<"\t\t\t[5]. Exit";
		cout<<"\n\n\t\t\tEnter your choice:  ";
		cin>>w;
		switch(w)
		{
			case 1: bus[p].install();
				break;
			case 2: bus[p].allotment();
				break;
			case 3: bus[0].show();
				break;
			case 4: bus[0].avail();
				break;
			case 5: exit(0);
		}
	}
	return 0;
}
