//this is a log in and registration project
#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdlib>

using namespace std;

void login();
void registration();
void forgot();
int main(){

cout<<"\t\t\t_______________________________________________________________________\n\n\n";
cout<<"                                                    Welcome to Login page                       \n\n\n";
cout<<"\t\t\t_______________________            Menu       __________________________\n\n\n";
cout<<"\t| Press 1 to LOGIN                       |"<<endl;
cout<<"\t| Press 2 to REGISTRATION                |"<<endl;
cout<<"\t| Press 3 to FORGET PASSWORD             |"<<endl;
cout<<"\t| Press 4 to EXIT                        |"<<endl;

int choice;
cout<<" Please Enter your choice :  ";
cin>>choice;


switch(choice){
    case 1:login();
     break;
    case 2: registration();
    break;
    case 3: forgot();
    break;
    case 4: cout<<"Thank you!!";
    break;
    default:
    system("cls");
     cout<<"\t\t\t Please Enter correct choice!!";
     main();
}

}
// login function definition
void login(){
    system("cls");
    int count;
    string usernameId ,password,id,passcode;

cout<<"\t\t\t___Enter Username and Password____\n\n";
cout<<"\t\t\tUSERNAME ";
cin>>usernameId;
cout<<"\t\t\tPASSWORD ";
cin>>password;

ifstream input("records.txt");//retrieve the username and password from records file

while(input>>id>>passcode){

    if(id==usernameId && passcode==password){
        count=1;
        system("cls");
    }
}
input.close();

if(count==1){
    cout<<usernameId<<"\n You Logged in Successfully\n";
    main();
}
else {
    cout<<" \n LOGIN ERROR! TRY AGAIN\n";
    main();
}


}
//registration function definition

void registration(){
    system("cls");
    string rusernameid,rpassword,rid,rpasscode;
    cout<<"\t\t\t Enetr username : ";
    cin>>rusernameid;
    cout<<"\t\t\t Enter the password : ";
    cin>>rpassword;


    ofstream f1("record.txt",ios::app);//store the username and password in records file
f1<<rusernameid<<' '<<rpassword<<endl;
system("cls");
cout<<"Successfully Registered! \n";

main();

}

// forgot function definition

void forgot(){

    system("cls");
    int option;
    cout<<"\t\t\t Forgot your password\n";
    cout<<"Press 1 to search your id by username"<<endl;
    cout<<"press 2 to go to back to main menu\n";
    cin>>option;

    switch(option){
        case 1 :
        {
            int count=0;
            string susername,sid,spass;
            cout<<"\n\t\t\tEnter the username you remembered :";
            cin>>susername;

            ifstream f2("records.txt");
            while(f2>>sid>>spass){
                if(sid==susername){
                    count=1;
                }
                f2.close();

                if (count==1){

                    cout<<"\n\n Your account is found!\n";
                    cout<<"\n Your password is : "<<spass;
                }
                else {
                    cout<<"\n\t Sorry! this account is not found! \n";
                    main();
                }
                break;
            };
        }
    case 2 :
            {
                main();

            }

            default: cout<<"\t\t\t WRONG CHOICE! TRY AGAIN\n";
            forgot();

    }

}
