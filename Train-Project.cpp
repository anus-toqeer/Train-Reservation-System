#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
void adminsection(){
    string passowrd;
    string pass="admin1122";
    char confirm;
    cout<<"Admin Access Required \nEnter Password to Verify : ";
    cin>>passowrd;
    if(passowrd!=pass){
        cout<<"Invalid Password ..! Access Denied "<<endl;
        return ;
    }
    cout<<"  ~~~WELCOME TO ADMIN SECTION~~~   \n";
    cout<<"\nWant to Delete All Booking? \n";
    cout<<"This will Delete All Bookings(Y/N) : ";
    cin>>confirm;
    if(confirm=='Y'||confirm=='y'){
        ofstream out("bookings.txt",ios::out);
        out.close();

        cout<<"\nAll Booking Cancelled Successfully ..!"<<endl;

    }
    else cout<<"\nOperation Failed. Bookings are not deleted..!"<<endl;
}
void viewseats(){
    cout<<"\n ===SEATS STATUS MENU===  \n"<<endl;
    int trainchoice;
    int number[5]={101,102,103,104,105};
    char trainname[5][20]={"Khyber Express","Musa pak","Awami Express","Greenline","Karachi Express"};
    cout<<"    <||TRAIN's INFORMATION||>   \n"<<endl;
    for(int i=0;i<5;i++)
     cout<<i+1<<" : "<<trainname[i]<<" Train Number : "<<number[i]<<endl;
    cout<<"Enter Train To View Seats : "<<endl;
    cin>>trainchoice;
    while (trainchoice<1 || trainchoice>5){
        cout<<"Invalid Train Choice ..!\nEnter Between(1-5):"<<endl;
        cin>>trainchoice;
    }
    int selectedtrain=number[trainchoice-1];
    int s[31]={0};

    fstream in("bookings.txt");
    int sno,tno;
    char name[50];
    while(in>>tno>>sno){
        in.ignore();
        in.getline(name,50);
        if(tno==selectedtrain && sno>=1 && sno<=30){
            s[sno]=1;
        }
    }
    in.close();
    cout<<"Train no : "<<selectedtrain<<" \nTrain Name : "<<trainname[trainchoice-1]<<endl;
    cout<<"\n Here is the seats status (X represent booked seats ): "<<endl;
    for(int i=1;i<=30;i++){
        if(s[i]!=1) cout<<"["<<i<<"]";
        else cout<<"[X]";
        if(i%5==0) cout<<endl;
    } 
    cout<<endl;
}
void bookingshow(){
    ifstream in("bookings.txt");
    int tno,sno;
    bool notfound=true;
    char name[30];
    cout<<char(218);
    for(int i=0;i<35;i++) cout<<(char)196;
    cout<<char(191);
    cout<<endl;
    cout<<char(179);
    cout<<"   ~~~~ ALL BOOKING DETAILS ~~~~   ";
    cout<<char(179);
    cout<<endl;
    cout<<char(192);
    
    for(int i=0;i<35;i++) cout<<(char)196;
    cout<<char(217);
    cout<<endl;
    cout << "\nTrain No  | Seat No | Passenger Name\n";
    cout << "------------------------------------\n";
    while(in>>tno>>sno){
        in.ignore();
        in.getline(name,30);
        cout << "   " << tno << "     |   " << sno << "     | " << name << endl;
        notfound=false;
    } 
    if(notfound) cout<<"\nNo Booking Has Been Made Yet..!\n"<<endl;
    in.close();
}
void cancel(){
    int canceltrain,cancelseat;
    char nametocancel[30];
    bool found =  false; 

    cout<<"\n   __WANT TO CANCEL A BOOKING__ \n";
    cout<<"Enter Train Number : ";
    cin>>canceltrain;
    cout<<"Enter Seat Number : ";
    cin>>cancelseat;
    cout<<"Enter Passenger name : ";
    cin.ignore();
    cin.getline(nametocancel,30);

    ifstream in("bookings.txt");
    ofstream temp("temp.txt");

    if (!in || !temp) {
        cout << " Error opening files.\n";
        return;
    }

    int tno, sno;
    char tempname[50];

    while (in >>tno>>sno) {
        in.ignore(); 
        in.getline(tempname, 50);
        if (tno == canceltrain && sno == cancelseat && strcmp(tempname, nametocancel) == 0) {
            found = true;
            continue;
        }
        temp << tno << " " << sno << " " << tempname << "\n";
    }

    in.close();
    temp.close();

    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");

    if (found) {
        cout << "\n Booking canceled successfully.\n";
    } else {
        cout << "\n No matching booking found.\n";
    }

}
void booking(){
    cout<<char(218);
    for(int i=0;i<37;i++) cout<<(char)196;
    cout<<char(191);
    cout<<endl;
    cout<<char(179);
    cout<<"      BOOK YOUR TICKETS NOW...!      ";
    cout<<char(179);
    cout<<endl;
    cout<<char(192);
    
    for(int i=0;i<37;i++) cout<<(char)196;
    cout<<char(217);
    cout<<endl;

    int trainnum,seatnum,date,month,a;
    char name[50],confirm;
    bool alreadybooked=false;
    char trainname[5][20]={"Khyber Express","Musa pak","Awami Express","Greenline","Karachi Express"};
    int time[5]={6,9,5,8,11};
    int num[5]={101,102,103,104,105};

    cout<<"Enter Passenger Name : ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"Enter Date(dd-mm) :";
    cin>>date>>month;
    cout<<endl;
    cout<<"  Available Trains... "<<endl;
    cout<<" 1 : Khyber Express \n 2 : Musa Pak \n 3 : Awami Express \n 4 : Greenline \n 5 : Karachi Express "<<endl;
    cout<<"\nEnter Your Choice ...! "<<endl;
    cin>>a;
     if(a==1){
             cout<<"Khypber Express "<<endl;
             cout<<"Route : Lahore To Peshawar "<<endl;
             cout<<"Departure Time : 6 am "<<endl;
             cout<<"Train number : 101 "<<endl;
        }
     else if(a==2){
             cout<<"Musa Pak "<<endl;
             cout<<"Route : Lahore To Multan "<<endl;
             cout<<"Departure Time : 9 am "<<endl;
             cout<<"Train number : 102 "<<endl;
     }
     else if(a==3){
             cout<<"Awami Express "<<endl;
             cout<<"Route : Peshawar To Karachi "<<endl;
             cout<<"Departure Time : 5 pm "<<endl;
             cout<<"Train number : 103 "<<endl;
     }
     else if(a==4){
             cout<<"Green Line  "<<endl;
             cout<<"Route : Rawalpindi to Chichawatni "<<endl;
             cout<<"Departure Time : 8 pm "<<endl;
             cout<<"Train number : 104 "<<endl;

     }
     else if(a==5){
             cout<<"Karachi Express "<<endl;
             cout<<"Route : Lahore To Karachi "<<endl;
             cout<<"Departure Time : 11 pm "<<endl;
             cout<<"Train number : 105 "<<endl;

          }
     else {
        cout<<"Invalid Choice please enter between(1-5) "<<endl;
        cin>>a;
     }

     do{
     cout<<"\nEnter Seat Number(0-30) : ";
     cin>>seatnum;
     if(seatnum<=0 || seatnum>30) cout<<"Invalid Seat Number";
     }while(seatnum<=0 || seatnum>30);

    ifstream in("bookings.txt");
    int tno, sno;
    char tempname[50];

    while (in>>tno>>sno) {
        in.ignore();
        in.getline(tempname, 50);
        if (tno == num[a-1] && sno == seatnum) {
            alreadybooked = true;
            break;
        }
    }
    in.close();
    if(alreadybooked){
     cout<<"This Seat is Already booked On This Train "<<endl;
     return;
    }

    ofstream out("bookings.txt", ios::app);
    if (!out) {
        cout << "Error writing to file.\n";
        return;
    }
    cout<<"Confirm Booking(Y/N) : ";
    cin>>confirm;
    if (confirm != 'Y' && confirm != 'y') {
        cout << "Booking cancelled by user.\n";
        return;
    }
    out << num[a - 1] << " " << seatnum << " " << name << "\n";
    
    out.close();
    for(int i=0;i<40;i++) cout<<"~";
    cout <<"\n|Train Name : "<<trainname[a-1]<<endl;
    cout <<"|Train Number : "<<num[a-1]<<endl;
    cout <<"|Seat Number : "<<seatnum<<endl;
    cout <<"|Passenger Name : "<<name<<endl;
    cout <<"|Date of Departure : "<<date<<"- "<<month<<endl;
    cout <<"|Time of Departure : "<<time[a-1]<<"am"<<endl;

    cout<< "\n       BOOKING SUCCESSFULL!\n";

}

void showtrains(){
    int a; char ch;
    cout<<"||Here is the list of Trains available || \n";
    for(int i=0 ; i<41 ;i++) cout<<"=";
    cout<<endl<<endl;
    cout<<" 1 : Khyber Express \n 2 : Musa Pak \n 3 : Awami Express \n 4 : Greenline \n 5 : Karachi Express "<<endl;
   do{
     cout<<"\nEnter Your Choice(1-5) ...! "<<endl;
     cin>>a;
    
         if(a==1){
             cout<<"Khypber Express "<<endl;
             cout<<"Route : Lahore To Peshawar "<<endl;
             cout<<"Departure Time : 6 am "<<endl;
             cout<<"Train number : 101 "<<endl;
        }
     else if(a==2){
             cout<<"Musa Pak "<<endl;
             cout<<"Route : Lahore To Multan "<<endl;
             cout<<"Departure Time : 9 am "<<endl;
             cout<<"Train number : 102 "<<endl;
     }
     else if(a==3){
             cout<<"Awami Express "<<endl;
             cout<<"Route : Peshawar To Karachi "<<endl;
             cout<<"Departure Time : 5 pm "<<endl;
             cout<<"Train number : 103 "<<endl;
     }
     else if(a==4){
             cout<<"Green Line  "<<endl;
             cout<<"Route : Rawalpindi to Chichawatni "<<endl;
             cout<<"Departure Time : 8 pm "<<endl;
             cout<<"Train number : 104 "<<endl;

     }
     else if(a==5){
             cout<<"Karachi Express "<<endl;
             cout<<"Route : Lahore To Karachi "<<endl;
             cout<<"Departure Time : 11 pm "<<endl;
             cout<<"Train number : 105 "<<endl;

          }
     else cout<<"Invalid Choice please enter between(1-5) "<<endl;

            cout<<"Want to check another..?Press(Y for Yes) and(N for No) Y/N..."<<endl;;
            cin>>ch;
        while(ch!='n'&& ch!='N'&& ch!='y' && ch!='Y'){
              cout<<"Enter only Y/N.."<<endl;
              cin>>ch;
          }
     }while(ch=='Y' || ch=='y' );
}
int main(){
    char choice;
    do{
    cout<<char(218);
    for(int i=0;i<45;i++) cout<<(char)196;
    cout<<char(191);
    cout<<endl;
    cout<<char(179);
    cout<<" ~~~~ Welcome To Train Reservation MENU ~~~~ ";
    cout<<char(179);
    cout<<endl;
    cout<<char(192);
    
    for(int i=0;i<45;i++) cout<<(char)196;
    cout<<char(217);
    cout<<endl;


    cout<<"A : View Trains "<<endl;
    cout<<"B : Book Tickets "<<endl;
    cout<<"C : Cancel Ticket "<<endl;
    cout<<"D : Show Bookings "<<endl;
    cout<<"F : View Seats "<<endl;
    cout<<"G : Admin Section"<<endl;
    cout<<"E : Exit "<<endl;
    cout<<" Enter your Choice "<<endl;
    cin>>choice;
    
    switch(choice){
          case 'a' :
          case 'A' : showtrains(); break;
          case 'B' :
          case 'b' : booking(); break;
          case 'c' :
          case 'C' : cancel(); break;
          case 'd' :
          case 'D' : bookingshow(); break;
          case 'f' :
          case 'F' : viewseats() ; break;
          case 'g' :
          case 'G' : adminsection(); break;
          case 'e' :
          case 'E' : cout<<"GoodBYE Have a Good Day "<<endl; break;

          default : cout<<"Invalid Choice Entered ..!\nEnter Again   : "<<endl;

        }
    } while(choice!='E' && choice !='e');
    return 0;
}