//FILE HANDLING
//Name : SARVESH PRAMOD BIWALKAR



#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class student{
	private:
	string name;
	int rollno;
	int mark;
	public:
		char ch;
		void getdata(){
			ofstream o2;
			o2.open("student.txt",ios::app);
			
			if(o2.fail())
			cout<<"Problem in file creation";
			else{						
			cout<<"Enter name of student : ";
			cin.ignore();
			getline(cin,name);
			cout<<"Enter roll no. : ";
			cin>>rollno;
			cout<<"Enter marks : ";
			cin>>mark;
			
			o2<<rollno;
			o2<<"       ";
			o2<<name;
			o2<<"       ";
			o2<<mark;
			o2<<endl;
			o2.close();
		}
	}
	
	void display(){
	    ifstream i1;
	    i1.open("student.txt");
	    if(i1.fail()){
	    cout<<"error in reading file";
		}
	    else{
	       while(true){
	       	i1.get(ch);
			if(i1.eof())
			break;
			cout<<ch;
			}

	    }
	}
};
	
int main(){
	student s1;
	int ch;
	do{
	    cout<<endl<<" Student database:"<<endl;
	    cout<<" .....Menu..... "<<endl;
	    cout<<" 1. Add student record"<<endl;
	    cout<<" 2. Display student record"<<endl;
	    cout<<" 3. Exit"<<endl;
	    cout<<" Enter your choice : ";
	    cin>>ch;
	    switch(ch){
	        case 1:
	        s1.getdata();
	        break;
	        case 2:
	        s1.display();
	        break;
	        case 3:
	        exit(0);
	    }
	}
	while(ch!=3);
	return 0;
}

