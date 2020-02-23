#include<iostream>
#include<conio.h>
#include<cstdlib>

using namespace std;

class Stack {

    private :
        int top;
        int arr[10];
        int maxi=10;

    public :
        Stack () {
            this->top=-1;
            this->maxi=10;
        }

        void push(int sk);
        int pop();
        void traverse();

};

void Stack::push(int sk)
{
    if(this->top==this->maxi-1) {
        cout<<"\n Stack overflow";
        exit(1);
    }else{
        this->arr[++this->top] = sk;
    }
}

int Stack::pop()
{
    if(this->top==-1) {
        cout<<"\n Stack underflow";
        exit(1);
    }else {
        return this->arr[this->top--];
    }
}

void Stack::traverse() {
    if(this->top==-1) {
        cout<<"\n No elements in the array";
    }
    for(int i=0;i<=this->top;i++){
        cout<<this->arr[i]<<"\t";
    }
    getch();
}

int main()
{
    Stack ob;
    int choice=0;
    do{
        system("CLS");
        cout<<"\n 1. Push";
        cout<<"\n 2. Pop";
        cout<<"\n 3. Traverse";
        cout<<"\n 4. Exit";
        cout<<"\n Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1 : cout<<"\n Enter a number:";int num;cin>>num;ob.push(num);break;
            case 2 : cout<<"\n Element Popped : "<<ob.pop();getch();break;
            case 3 : ob.traverse();break;
            case 4 : cout<<"\n Exiting ...";exit(1);break;
            default : cout<<"\n Enter a valid option";

        }
    }while(choice!=4);
    return 0;
}
