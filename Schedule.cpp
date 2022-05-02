//sources
//https://www.programiz.com/cpp-programming/string-int-conversion (how to turn string into integer)

using namespace std;


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <curses.h>


#ifndef SSI_FUNCTIONS
#define SSI_FUNCTIONS
#include "Schedule.h"
#endif


  //default constructure
Calander::Calander(void){
    }



Calander::Calander(ifstream& is){
string Month, Day, Time, Event;
//TEST
      for(int x=1; x<13; x++){
        for(int y=1; y<8; y++){
          for(int z=1; z<25; z++){
            getline(is, Month, ',');
            getline(is, Day, ',');
            getline(is, Time, ',');
            getline(is, Event, '\n');

            this->event[stoi(Month)][stoi(Day)][stoi(Time)] = Event;
            }
          }
        }

      }



Calander::~Calander(void){
        cout<< "Thanks for using Calander Creator!";
}




int Calander::menu()
{
    int choice;
    cout<<"\nEnter option:\n";
    cout<<"\t(0) Print Your current Calander\n";
    cout<<"\t(1) Search the for a certain Event\n";
    cout<<"\t(2) Adding to Calander\n";
    cout<<"\t(3) Remove from Calander\n";
    cout<<"\t(4) Export Calander\n";
    cout<<"\t(5) Print Calander in Calander Format \n";
    cout<<"\t(6) Exit the program\n";
    cout<<"\t\tChoice ?";
    cin>>choice;
    return(choice);
}   // end menu








void Calander::option0(void){

  for(int x=1; x<13; x++){
    for(int y=1; y<8; y++){
      for(int z=1; z<25; z++){
        if(event[x][y][z] != ""){
          if(z>12){
            cout << x << "/" << y << ", " << z-12 << ":00 PM, " << this->event[x][y][z] << "\n";
          }else{
            cout << x << "/" << y << ", " << z << ":00 AM, " << this->event[x][y][z] << "\n";
          }
        }
      }
    }
  }


}



void Calander::option1(void){
  string Month, Am_Pm, event;
  int input_month=-1, input_day=-1, input_time=-1, n=1, Choice;

  cout<<"Here you can search through the scheduler by date and time or event. Please enter 1 to search by date and time or 2 to search by event. ";
  cin>>Choice;
  if(Choice == 1){
    cout<<"Please enter the first 3 capalized letters of the month Ex.(MAR). (enter \"-1\" to leave blank): ";
    cin>>Month;
    cout<<"Please enter a numerical Day value Ex.(27). (enter \"-1\" to leave blank): ";
    cin>>input_day;
    cout<<"Please enter a numerical Hour of Time from 1 - 12. Ex.(6 PM is 6) & (6 AM is 6): ";
    cin>>input_time;
    cout<<"Is your event AM or PM Ex in capalized letters.(PM)" << endl;
    cin>>Am_Pm;
  }

  if(Am_Pm != "PM" && Am_Pm != "AM"){
    cout<<"Incorrect Input for Time coordinate"<<endl;
    cout<<"Returning to main menu";
    menu();
  }

  if(input_time != -1 && (input_time > 31 || input_time < 1)){

  }

  if(Am_Pm == "PM"){

  }

  if((input_day <= 1 || input_day > 31) && (input_day != -1)){
    cout<<"Invalid input for day, should be between 1 and 31"<<endl;
    cout<<"Returning to main menu!";
    menu();
  }

  if(Month != "-1" && Month != "")
    input_month = MonthConvert(Month);

 if(input_month == 2){
    if(input_day > 28){
      cout<<"Invalid input, there are only 28 days in FEB."<<endl;
      cout<<"Returning to main menu!";
      menu();
    }
  }else if(input_month == 4 || input_month == 6 || input_month == 9 || input_month == 11){
    if(input_day > 30){
      cout<<"Invalid input, there are only 30 days in "<<Month<<"."<<endl;
      cout<<"Returning to main menu!";
      menu();
    }
  }


  cout<<"Results:"<<endl<<endl;

  if(Choice == 1){
    if(input_month != -1 && input_day != -1 && input_time != -1){
      cout<<n<<".) "<<input_month<< "\\"<<input_day<< ", "<<input_time<<", "<<this->event[input_month][input_day][input_time]<<"\n";
      n++;
    }else if(input_month != -1 && input_day != -1 && input_time == -1){
      for(int z=0; z<25; z++){
        if(this->event[input_month][input_day][z] != ""){
          cout<<n<<".) "<<input_month<< "\\"<<input_day<< ", "<<z<<", "<<this->event[input_month][input_day][z]<<"\n";
          n++;
        }
      }
    }else if(input_month != -1 && input_day == -1 && input_time == -1){
      for(int y=0; y<31; y++){
        for(int z=0; z<25; z++){
          if(this->event[input_month][y][z] != ""){
            cout<<n<<".) "<<input_month<< "\\"<<y<< ", "<<z<<", "<<this->event[input_month][y][z]<<"\n";
            n++;
          }
        }
      }
    }else if(input_month == -1 && input_day != -1 && input_time != -1){
      for(int x=0; x<13; x++){
        if(this->event[x][input_day][input_time] != ""){
          cout<<n<<".) "<<x<< "\\"<<input_day<< ", "<<input_time<<", "<<this->event[x][input_day][input_time]<<"\n";
          n++;
        }
      }
    }else if(input_month == -1 && input_day != -1 && input_time == -1){
      for(int x=0; x<13; x++){
        for(int z=0; z<25; z++){
          if(this->event[x][input_day][z] != ""){
            cout<<n<<".) "<<x<< "\\"<<input_day<< ", "<<z<<", "<<this->event[x][input_day][z]<<"\n";
            n++;
          }
        }
      }
    }else if(input_month != -1 && input_day == -1 && input_time != -1){
      for(int y=0; y<32; y++){
        if(this->event[input_month][y][input_time] != ""){
          cout<<n<<".) "<<input_month<< "\\"<<y<< ", "<<input_time<<", "<<this->event[input_month][y][input_time]<<"\n";
          n++;
        }
      }
    }else if(input_month != -1 && input_day == -1 && input_time == -1){
      for(int y=0; y<32; y++){
        for(int z=0; z<25; z++){
          if(this->event[input_month][y][z] != ""){
            cout<<n<<".) "<<input_month<< "\\"<<y<< ", "<<z<<", "<<this->event[input_month][y][z]<<"\n";
            n++;
          }
        }
      }
    }else if(input_month == -1 && input_day == -1 && input_time != -1){
      for(int x=0; x<13; x++){
        for(int y=0; y<32; y++){
          if(this->event[x][y][input_time] != ""){
            cout<<n<<".) "<<x<< "\\"<<y<< ", "<<input_time<<", "<<this->event[x][y][input_time]<<"\n";
            n++;
          }
        }
      }
    }else if(input_month == -1 && input_day == -1 && input_time == -1){
      cout << "Not enough information, returning to main menu.";
      menu();
    }
  }else if(Choice == 2){
    for(int x=1; x<13; x++){
      for(int y=1; y<8; y++){
        for(int z=1; z<25; z++){
          if(this->event[x][y][z] == event){
            cout<<n<<".) "<<x<< "\\"<<y<< ", "<<z<<", "<<this->event[x][y][z]<<"\n";
            n++;
          }
        }
      }
    }
  }

  if(n==1){
    cout<<"Could not find any events under that date, time, or name."<<endl;
    cout<<"Returning to main menu.";
    menu();
  }


}



void Calander::option2(void){
  int Day, Hour, Min;
  int i=0;
  string Response, Month, input_event,input_length;
  string event;
  int input_month;
  int length_input;

  cout<<"Please enter the first 3 capalized letters of the Month Ex.(MAR)" << endl;
  cin>>Month;
  input_month = MonthConvert(Month);

  while(input_month > 12 || input_month < 1){
    cout<<"Invalid input, "<<Month<<" is not a Month."<<endl;
    cout<<"Please input a valid Month:";
    cin>>Month;
    input_month = MonthConvert(Month);
  }

  cout<<"Please enter the first numerical day Ex.(28)" << endl;
  cin>>Day;

  while(input_month == 2 && (Day > 28 || Day < 1)){
     cout<<"Invalid input, there are only 28 days in FEB.";
     cin>>Day;
   }
   while((input_month == 4 || input_month == 6 || input_month == 9 || input_month == 11) && (Day > 30 || Day < 1)){
     cout<<"Invalid input, there are only 30 days in "<<Month<<".";
     cin>>Day;
   }
   while((input_month == 1 || input_month == 3 || input_month == 5 || input_month == 7 || input_month == 8 || input_month == 10 || input_month == 12) && (Day > 31 || Day < 1)){
      cout<<"Invalid input, there are only 31 days in "<<Month<<"."<<endl;
      cin>>Day;
   }

    cout<<"Please enter a numerical Hour of Time from 1 - 12 to mark when the event begins. Ex. (6 PM is 6) & (6 AM is 6):";
    cin>>Hour;

    while(Hour > 12 || Hour < 1){
      cout<<"Invalid input for Hour. Please enter a numerical Hour of Time from 1 - 12 to mark when the event begins. Ex. (6 PM is 6) & (6 AM is 6):"<<endl;
      cin>>Hour;
    }



    cout<<"Is your event AM or PM in capalized letters. Ex.(PM)" << endl;
    cin>>Response;
    cout<<Response<<endl;

    while(Response != "AM" && Response != "PM"){
      cout<<"Invalid input, please enter either AM or PM in capalized letters. Ex.(PM): ";
      cin>>Response;
    }

    if(Response == "PM"){
      Hour += 12;
    }

    cout<<"Input the event: " << endl;
    cin>>input_event;

    cout<<"Input your integer event length or 24(End of the day) if it goes till the end of the day" << endl;
    cin>>input_length;

    if(input_length + Hour > 24){
      for(int z=Hour; z<Hour+input_length; z++){

      }
    }
    else{
      for(int z=Hour; z<Hour+input_length; z++){
        if(this->event[input_month][][z])
      }
    }
}

//For option3 the function goes through and scans in new values and adds to the list
//it ask through each time for the part numbers and from this point it sends to the load function which will add it

void Calander::option3(void){
  int Day, Hour, Min;
  string Response, Month, input_event,input_length;
  int input_month;

  cout<<"Please enter the first 3 capalized letters of the Month Ex.(MAR)" << endl;
  cin>> Month;
  input_month = MonthConvert(Month);

  while(input_month > 12 || input_month < 1){
    cout<<"Invalid input, there are only 28 days in FEB."<<endl;
    cin>>Month;
    input_month = MonthConvert(Month);
  }

  cout<<"Please enter the first numerical day Ex.(28)" << endl;
  cin>>Day;

  while(input_month == 2 && (Day > 28 || Day < 1)){
     cout<<"Invalid input, there are only 28 days in FEB.";
     cin>>Day;
   }
   while((input_month == 4 || input_month == 6 || input_month == 9 || input_month == 11) && (Day > 30 || Day < 1)){
     cout<<"Invalid input, there are only 30 days in"<<input_month<<".";
     cin>>Day;
   }
   while((input_month == 1 || input_month == 3 || input_month == 5 || input_month == 7 || input_month == 8 || input_month == 10 || input_month == 12) && (Day > 31 || Day < 1)){
      cout<<"Invalid input, there are only 31 days in"<<input_month<< "."<<endl;
      cin>>Day;
   }

    cout<<"Please enter a numerical Hour of Time from 1 - 12. Ex. (6 PM is 6) & (6 AM is 6):" << endl;
    cin>> Hour;

    if(Hour > 12){
      cout<<"Incorrect Input for Hour"<<endl;
      cout<<"Returning to main menu"<<endl<<endl;
      menu();
    }



    cout<<"Is your event AM or PM Ex in capalized letters.(PM)" << endl;
    cin>> Response;
    cout<<Response<<endl;

  if(Response != "PM" && Response != "AM" ){
    cout<<"Incorrect Input for Time coordinate"<<endl;
    cout<<"Returning to main menu"<<endl<<endl;
    menu();
  }

  cout<<"Found "<< this->event[input_month][Day][Hour]<<" on "<<input_month<<"/"<<Day<<", "<<Hour<<"."<<endl;
  cout<<"Are you sure you want to delete this event? (Y/N) ";
  cin>>Response;

  if(Response == "Y"){
    cout<<"Event "<<this->event[input_month][Day][Hour]<<" deleted from calander"<<endl;
    cout<<"Returning to main menu.";
    menu();
  }else if(Response == "N"){
    cout<<"No events deleted from calander"<<endl;
    cout<<"Returning to main menu.";
    menu();
  }else{
    cout<<"ERROR: Invalid response, no events deleted from calander."<<endl;
    cout<<"Returning to main menu.";
    menu();
  }

}

//This function writes out to an output file
//it loops through for size of the vector and outputs for each value

void Calander::option4(ofstream& ofile){

  //Goes through the event array and prints all events
  //and dates to the output file to save the data
  for(int x=1; x<13; x++){
    for(int y=1; y<8; y++){
      for(int z=1; z<25; z++){
        ofile << x << ", " << y << ", " << z << "," << this->event[x][y][z] << "\n";
      }
    }
  }

}




void Calander::option5(void){

  bool found = false;
  int c = 0;
  string buffer;

  for(int x=1; x<13; x++){
    c=0;
    cout<<"Enter a char to progress to your next month: ";
    cin>>buffer;

    cout<<endl<<endl<<"+---+"<<endl;
    MonthPrint(x);
    cout<<"+---+"<<endl;

    if(x == 2){
      for(int y=1; y<29; y++){
        for(int z=1; z<25; z++){
          if(this->event[x][y][z] != ""){
            found = true;
          }
        }
        if(found == true)
          cout << "*";
        else
          cout << "-";

        found = false;
        c++;

        if(c == 7){
          cout<<endl;
          c=0;
        }
      }
    }
    else if(x == 4 || x == 6 || x == 9 || x == 11){
      for(int y=1; y<31; y++){
        for(int z=1; z<25; z++){
          if(this->event[x][y][z] != ""){
            found = true;
          }
        }
        if(found == true)
          cout << "*";
        else
          cout << "-";

        found = false;
        c++;

        if(c == 7){
          cout<<endl;
          c=0;
        }
        if(y==30)
          cout<<endl;
      }
    }
    else{
      for(int y=1; y<32; y++){
        for(int z=1; z<25; z++){
          if(this->event[x][y][z] != ""){
            found = true;
          }
        }
        if(found == true)
          cout << "*";
        else
          cout << "-";

        found = false;
        c++;

        if(c == 7){
          cout<<endl;
          c=0;
        }
        if(y==31)
          cout<<endl;
      }
    }
  }

  cout<<endl<<endl;
}

//this essentially exits the program
void Calander::option6(void){
char op6;
cout<<"Exiting program."<<"\n" <<"Enter 'Y' to continue none of your data will be save:";
cin>>op6;
  if(op6 == 'Y'){
    exit(1);
  }
  else{
    menu();
  }

}



void Calander::MonthPrint(int x){
  if(x==1){
    cout<<"|Jan|"<<endl;
  }
  else if(x==2){
    cout<<"|Feb|"<<endl;
  }
  else if(x==3){
    cout<<"|MAR|"<<endl;
  }
  else if(x==4){
    cout<<"|Apr|"<<endl;
  }
  else if(x==5){
    cout<<"|May|"<<endl;
  }
  else if(x==6){
    cout<<"|Jun|"<<endl;
  }
  else if(x==7){
    cout<<"|Jul|"<<endl;
  }
  else if(x==8){
    cout<<"|Aug|"<<endl;
  }
  else if(x==9){
    cout<<"|Sep|"<<endl;
  }
  else if(x==10){
    cout<<"|Oct|"<<endl;
  }
  else if(x==11){
    cout<<"|Nov|"<<endl;
  }
  else{
    cout<<"|Dec|"<<endl;
  }
}



int Calander::MonthConvert(string Month){
  int input_month;

  if(Month == "JAN"){
    input_month = 1;
  }else if(Month == "FEB"){
    input_month = 2;
  }else if(Month == "MAR"){
    input_month = 3;
  }else if(Month == "APR"){
    input_month = 4;
  }else if(Month == "MAY"){
    input_month = 5;
  }else if(Month == "JUN"){
    input_month = 6;
  }else if(Month == "JUL"){
    input_month = 7;
  }else if(Month == "AUG"){
    input_month = 8;
  }else if(Month == "SEP"){
    input_month = 9;
  }else if(Month == "OCT"){
    input_month = 10;
  }else if(Month == "NOV"){
    input_month = 11;
  }else if(Month == "DEC"){
    input_month = 12;
  }
  else{
    input_month = 13;
    return input_month;
  }

  return input_month;

}
