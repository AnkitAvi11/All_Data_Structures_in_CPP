#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<fstream>

using namespace std;

class Stack {

    private :
        int top;
        int arr[10];
        int maxi;

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
        cout<<"\n\t STACK OVERFLOW CONDITION REACHED.\nCAN'T ADD MORE ELEMENTS.";
        getch();
        return;
    }else{
        cout<<"\n\t Elements in the Stack now : \n";
        this->traverse();
        this->arr[++this->top] = sk;
        cout<<"\n\n\t THIS IS HOW THE STACK LOOKS AFTER PUSH OPERATION : \n";
        this->traverse();
    }
    getch();
}

int Stack::pop()
{
    if(this->top==-1) {
        return -1;
    }else {
        return this->arr[this->top--];
    }
}

void Stack::traverse() {
    if(this->top==-1) {
        cout<<"\n\t NO ELEMENTS IN THE ARRAY";
    }
    for(int i=this->top;i>=0;i--){
        cout<<"\t [ POS->"<<i<<"::Data->"<<arr[i] <<"]";
    }
}

void markComplete(char *email, char *password)
{

}

void stackMenu()
{
    Stack ob;
    int choice=0;
    do{
        system("CLS");
        cout<<"\n\t =========================================================================================\n";
        cout<<"\n\t\t\tSTACK USING ARRAYS\n";
        cout<<"\n\t =========================================================================================\n";
        cout<<"\n\t 1. PUSH OPERATION";
        cout<<"\n\t 2. POP OPERATION";
        cout<<"\n\t 3. TRAVERSAL \n";
        cout<<"\n\t 4. MARK THIS COURSE COMPLETE \n";
        cout<<"\n\t 5. GO BACK \n";
        cout<<"\n\t =========================================================================================\n";
        cout<<"\n\t Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1 : cout<<"\n\t Enter a number:";int num;cin>>num;ob.push(num);break;
            case 2 :
                {
                    int popped = ob.pop();
                    if(popped < 0) {
                        cout<<"\n\t STACK UNDERFLOW CONDITION REACHED";
                    }else{
                        cout<<"\n\t ELEMENT POPPED : "<<popped;
                        cout<<"\n\t STACK AFTER POP OPERATION : ";ob.traverse();
                    }
                    getch();
                    break;
                }


            case 3 : cout<<"\n STACK ELEMENTS : \n";ob.traverse();getch();break;
            case 4:;
            case 5 : cout<<"\n\t Exiting ...";break;
            default : cout<<"\n\t Enter a valid option";

        }
    }while(choice!=5);
}
