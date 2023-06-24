//this is a log in and registration project
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void login();
void registration();
void forgot();
int main(){
    
cout<<"\t\t\t_______________________________________________________________________\n\n\n";
cout<<"                                   Welcome to Login page                       \n\n\n";
cout<<"\t\t\t_______________________            Menu       __________________________\n\n\n";
cout<<"\t| Press 1 to LOGIN                       |"<<endl;
cout<<"\t| Press 2 to REGISTRATION                |"<<endl;
cout<<"\t| Press 3 to FORGOT PASSWORD             |"<<endl;
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

void login(){
    system("cls");
    int count;
    string usernameId ,password,id,passcode;

cout<<"\t\t\t___Enter Username and Password____\n\n";
cout<<"\t\t\tUSERNAME ";
cin>>usernameId;
cout<<"\t\t\tPASSWORD ";
cin>>password;

ifstream input("records.txt");

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