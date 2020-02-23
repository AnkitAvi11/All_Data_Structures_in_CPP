#include<iostream>
#include<conio.h>
#include<cstdlib>

using namespace std;

class ParentClass
{
        int num;
    protected :
        string name;
    public:
        ParentClass() {this->num=0;this->name="NA";cout<<"\n Parent CTOR";}

        ParentClass (int sk, string name) {
            cout<<"\n Parent CTOR";
            this->num=sk;
            this->name = name;
        }

        void display()
        {
            cout<<"\n Number = "<<this->num<<"\nName="<<this->name;
        }
};

class DerivedClass : private ParentClass
{
        int dnum;
        ParentClass ob;

    public :

        DerivedClass () {
            cout<<"\n Derived CTOR";
        }

        DerivedClass (int num, string name, int dnum) : ParentClass(num, name) {
            cout<<"\n Derived class CTOR";
            this->dnum=dnum;
        }

        void display()
        {
            ParentClass::display();
            cout<<"\n Dnum = "<<this->dnum;
        }

};

int main()
{
    DerivedClass ob(1,"ankit", 2);
    ob.display();
    return 0;
}
