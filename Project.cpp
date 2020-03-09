#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>

using namespace std;

class User {
    private :
        int roll;
        string name;
    public :
        User() {
            this->roll = -1;
            this->name = "NA";
        }

        User(int roll, string name)
        {
            this->roll = roll;
            this->name = name;
        }

        void display();
        void getData();
};

void User::getData() {cin>>roll;cin>>name;}

void User::display()
{
    cout<<"\n Roll : "<<this->roll<<"\t Name : "<<this->name;
}

int main() {
    User ob;
    fstream file("records.dat", ios::in | ios::binary | ios::app );
    if(file)
    {
        while(file.read((char *)&ob, sizeof(ob))) {
            ob.display();cout<<endl;
        }
        file.close();
    }
    return 0;
}
