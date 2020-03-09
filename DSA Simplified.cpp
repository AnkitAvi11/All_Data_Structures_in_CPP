#include<iostream>
#include<conio.h>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

/**
    DEALING WITH THE USERS ONLY
    ---------------------------
    THIS MODULES CONTAINS THE CODING OF THE FEATURES AS FOLLOWED
    1. LOGIN
    2. SIGNUP
    3. CHANGE / RESET PASSWORD
    4. SHOW ALL USER DETAILS (ADMIN ACCESS WILL BE REQUIRED)
*/

char user_email[100], user_password[100];   //  global variables to maintain login session

class User {
    private :
        int uid;
        char name[100];
        char email[100];
        char password[100];

    public :

        User()
        {
            this->uid = -1;
            strcpy(name, "NA");
            strcpy(email, "NA");
            strcpy(password, "NA");
        }

        User(int uid, char name[], char email[], char password[])
        {
            this->uid = uid;
            strcpy(name, name);
            strcpy(email, email);
            strcpy(password, password);
        }

        void getData();
        void displayData();

        char *getemail() {return this->email;}

        void setname(char[]);
        void setemail(char[]);
        void setpassword(char[]);
};

void User::getData()
{
    cin.ignore();
    cout<<"\n Enter your Name : ";
    cin.getline(name, 100);

    cout<<"\n Enter your Email : ";
    cin.getline(email, 100);

    cout<<"\n Enter a password : ";
    cin.getline(password, 100);
}

void User::displayData()
{
    cout<<setw(20)<<name<<setw(40)<<email<<setw(20)<<password;
}

/**
    FUNCTION TO ADD A NEW USER
    REGISTERATION FUNCTION
*/

void insertData()
{
    User ob, user;

    fstream file;
    file.open("user_records.txt", ios::in);

    if(file) {
        user.getData();
        while(file.read((char *)&ob, sizeof(ob))) {
            if(strcmpi(ob.getemail(), user.getemail())==0){
                cout<<"\n This email already exists. \n\t Please use another email.";getch();return;
            }
        }
        fstream insertfile;
        insertfile.open("user_records.txt", ios::app);
        if(insertfile)
        {
            insertfile.write((char *) &user, sizeof(user));
        }
        insertfile.close();
    }

    file.close();

    cout<<"\n User Data entered.";
    getch();
}

/**
    THIS FUNCTION READS ALL THE USER DATA
    MORE OF A ADMIN CONTROLLED FUNCTION
*/

void readData() {
    string password;

    cout<<"\n\t THIS IS AN ADMIN PRIVILEDGE";
    cout<<"\n\t PLEASE ENTER ADMIN PASSWORD TO CONTINUE : ";
    cin.ignore();
    getline(cin, password);

    if(password.compare("AnkitSingh@383")==0) {
        User ob;

        fstream file;
        file.open("user_records.txt", ios::in);

        if(file) {
            system("cls");
            cout<<"\n\t SHOWING THE USER DETAILS\n";
            cout<<"\n\t =========================================================================================\n";
            cout<<setw(20)<<"NAME"<<setw(40)<<"EMAIL ADDRESS"<<setw(20)<<"PASSWORD";
            cout<<"\n\t =========================================================================================\n";
            while(file.read((char *)&ob, sizeof(ob))) {
                cout<<endl;
                ob.displayData();
            }
            cout<<"\n\n\t =========================================================================================\n";
            cout<<"\n\n\t PRESS ANY KEY TO CONTINUE ...";
        }
        getch();
        file.close();
    } else {
        cout<<"\n\t PASSWORD ENTERED IS WRONG ";
        cout<<"\n\t PRESS ANY KEY TO CONTINUE ...";
        getch();
        return;
    }
}

/**
    FUNCTION TO MAINTAIN A LOGIN SESSION
    AND TO LOGIN A USER
*/

bool loginUser (char *email, char *password) {

}

void main_menu () {
    int choice=0;
    do{
        system("cls");
        cout<<"\n\t =========================================================================================\n";
        cout<<"\n\t\t\tDATA STRUCTURES AND ALGOS SIMPLIFIED\n";
        cout<<"\n\t =========================================================================================\n";
        cout<<"\n\t 1. Register New User";
        cout<<"\n\t 2. Show All Users";
        cout<<"\n\t 3. Login (user)";
        cout<<"\n\t 4. Delete a User";
        cout<<"\n\t 5. Exit \n";
        cout<<"\n\t =========================================================================================\n";
        cout<<"\n\t Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1: insertData();break;
            case 2: readData();break;
            case 3:;
            case 4:;
            case 5: cout<<"\n\t Exiting application ...";getch();break;
            default :cout<<"\n\t Enter a valid option";getch();;

        }
    }while(choice!=5);
}

int main () {

    return 0;
}

