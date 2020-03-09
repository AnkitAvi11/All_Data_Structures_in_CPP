#include<iostream>
#include<conio.h>
#define MAX 10

using namespace std;

class Queue {
    private :
        int arr[MAX];
        int front, rear;

    public :
        Queue ()
        {
            this->front = this->rear = -1;
        }

        void insertElement(int);
        int deleteElement();
        void traverse();

};

void Queue::insertElement(int sk)
{
    if(this->rear == MAX-1) {cout<<"\n Queue overflow";return;}
    else
    {
        if(this->rear==-1) {this->rear = this->front = 0;this->arr[this->rear]=sk;}
        else{
            this->arr[++this->rear]=sk;
        }
    }
}

int Queue::deleteElement() {
    if(this->front==-1 || this->front!=this->rear+1) {cout<<"\n No element in the Queue. Queue is empty.";return 0;}
    else {
        return this->arr[this->front++];
    }
}

void Queue::traverse() {
    if(this->front==-1 || this->front!=this->rear+1) {cout<<"\n No element in the Queue. Queue is empty.";return;}
    else {
        for(int i=this->front;i<=this->rear;i++)
            cout<<this->arr[i]<<" => ";
    }
}

int main ()
{
    Queue ob;
    int choice;
    do {
        cout<<"\n 1. Insert element";
        cout<<"\n 2. Delete Element";
        cout<<"\n 3. Traverse";
        cout<<"\n 4. Exit";
    }while(choice!=4);
    return 0;
}
