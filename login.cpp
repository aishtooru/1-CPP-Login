#include<iostream>
#include<fstream>
using namespace std;

class temp {
    string username, email, password;
    string searchName, searchPass, searchEmail;
    fstream file;
    public:
    void login();
    void signUp();
    void forgot();

}obj;

int main() {
    char choice;
    cout<<"\n1-Login";
    cout<<"\n2-Sign Up";
    cout<<"\n3-Forgot Password";
    cout<<"\n4-Exit";
    cout<<"\nEnter your choice: ";
    cin>>choice;

    switch(choice) {
        case '1':
        obj.login();
        break;

        case '2':
        obj.signUp();
        break;

        case '3':
        obj.forgot();
        break;

        case '4':
        return 0;
        break;

        defaault:
        cout<<"Invalid Selection";
    }
}

void temp :: signUp() {
    cout<<"\nEnter Your Username: ";
    cin>>username;
    cout<<"\nEnter Your Email:";
    cin>>email;
    cout<<"Enter Your Password: ";
    cin>>password;

    file.open("login.txt", ios::out | ios::app);
    file<<username<<"*"<<email<<"*"<<password<<endl;
    file.close();
}

void temp :: login() {
    cout<<"------LOGIN----- "<<endl;
    cout<<"Enter Your Username: "<<endl;
    cin>>searchName;
    cout<<"Enter Your Password: ";
    cin>>searchPass;

    file.open("login.txt", ios::in);

    if (!file.is_open()) {
        cout << "[DEBUG ERROR] File login.txt cannot be opened!" << endl;
        return;
    }


    bool found = false;
    while(getline(file, username, '*') &&
          getline(file, email, '*') &&
          getline(file, password, '\n')) {
        
        if (username == searchName) {
            found = true;
            if (password == searchPass) {
                cout << "Account Login Successful" << endl;
                cout << "Welcome, " << username << "!" << endl;
                cout << "Email :: " << email << endl;
            } else {
                cout << "Incorrect Password" << endl;
            }
            break;
          }
        
    }
    if(!found) {
        cout<<"Account Not Found, please make sure to sign up first."<<endl;
    }
    file.close();

}

void temp :: forgot() {
    cout<<"\nENter Your Username:";
    cin>>searchName;
    cout<<"\nEnter Your Email: ";
    cin>>searchEmail;

    file.open("login.txt", ios::in);
    if(!file.is_open()){
        cout<<"\n[DEBUG ERROR] File login.txt cannot be opened!"<<endl;
        return;
    }

    bool found = false;

    while(getline(file,username, '*') &&
          getline(file, email, '*') &&
          getline(file, password, '\n')) {
        
            if(username == searchName && email == searchEmail) {
                found = true;
                cout<<"\nAccount Found!";
                cout<<"\nYour Password is: "<<password<<endl;
                break;
            }

    }
    if(!found) {
        cout<<"\nAccount Not Found!"<<endl;
    }
    file.close();
}