#include<iostream>
#include<conio.h>
#include<ctype.h>
#include<fstream>

using namespace std;

class Sample {
        int roll;
        string name;
    public :
        Sample() {
            roll = 0;
            name = "NA";
        }
        Sample(int sk, string name) {
            this->roll = sk;this->name=name;
        }
        void display()
        {
            cout<<"\n ROll = "<<this->roll;
            cout<<"\n Name = "<<this->name;
        }
};

int main() {
    Sample ob(100, "Ankit Kumar");
    fstream fout;
    fout.open("student_into.txt", ios::in);
    while(fout.read((char *) &ob, sizeof(ob))) {
        ob.display();
    }
    return 0;
}
