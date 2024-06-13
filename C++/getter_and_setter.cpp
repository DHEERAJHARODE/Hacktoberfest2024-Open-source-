#include<iostream>
using namespace std;

class Movie{
    // Private means that the information will only be visible to the code that is inside the class
    private:
        string rating;

    public:
        string name;
        string maker;

        // Constructor
        Movie(string nam, string make, string rate){
            name = nam;
            maker = make;
            rating = rate;
        }
        Movie(){
            name = "None";
            maker = "None";
            rating = "None";
        }
        string setrate(string rate){
            if(rate == "R" || rate == "R++"){
                rating = rate;
                return rating;
            }
            else{
                rating = "nr";
                return rating;
            }
        }
};


int main(){
    Movie avenger("Avengers XXX", "Me", "R");
    Movie sasapool("SASAPOOL", "SASAPOOL", "R++");
    Movie fake("fake", "binod", "binod");

    cout<<fake.setrate("R++");

    return 0;
}
