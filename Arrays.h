#ifndef ARRAYS_H
#define ARRAYS_H
#include<istream>

using namespace std;

class Arrays
{
    public:
        Arrays();
        void display();
        virtual ~Arrays();

    protected:

    private:
        int arr[100];
        int top;
};

Arrays::Arrays() {
    this->top=-1;
}

void Arrays::display()
{
    cout<<"Top = "<<top;
}

#endif // ARRAYS_H
