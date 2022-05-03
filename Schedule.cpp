//sources
//https://www.programiz.com/cpp-programming/string-int-conversion (how to turn string into integer)

using namespace std;


#include <iostream>
#include <string>
#include <wiringPi.h>
#include <csignal>
#include <fstream>
#include <iomanip>
#include <vector>


#ifndef SSI_FUNCTIONS
#define SSI_FUNCTIONS
#include "Schedule.h"
#endif


  //default constructure
Calander::Calander(void){
    }


Calander::~Calander(void){
        cout<< "Thanks for using Calander Creator!";
}


 // Blink an LED
void blink_led_on(int led) {
    digitalWrite(led, HIGH);
}

void blink_led_off(int led) {
    digitalWrite(led, LOW);
}


// default Calander input fucntion file which will read in values for the Calander
// From this it will d
void Calander::load(string Month, string Day, string Hour, string Event){

  int x=0, y=0, z=0;

  x=stoi(Month);
  y=stoi(Day);
  z=stoi(Hour);

  this->event[x][y][z] = Event;
  Month ="";
  Day ="";
  Hour ="";
}

// This is the options menu from where the user can select to print the current Calander
//Option 0 Print the current events to the screen
//Option 1 Search for a current event either on date or Event name
//Option 2 Add to the calander of events
// Option 3 Remove from the calander using
int Calander::menu()
{
    wiringPiSetupGpio();
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);


    blink_led_off(green);
    blink_led_off(yellow);
    blink_led_off(red);

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







// Option 2 outputs the data in a readable for where the user can take the data printed from the
//screen and understand what of all the events they have going once
void Calander::option0(void){

  blink_led_on(green);
  delay(1000);

  for(int x=1; x<13; x++){
    for(int y=1; y<8; y++){
      for(int z=1; z<25; z++){
        if(this->event[x][y][z] != ""){
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
  string Month, Am_Pm, event, Day, Choice, Hour;
  int input_month=-1, input_day=-1, input_time=-1, num=0;

  cout<<"Here you can search through the scheduler by date and time or event. Please enter 1 to search by date and time or 2 to search by event. ";
  cin>>Choice;

  while(Choice != "1" && Choice != "2"){
    cout<<"Invalid input, please enter 1 to search by date and time or 2 to search by event. ";
    cin>>Choice;
  }

  if(Choice == "1"){
    cout<<"Please enter the first 3 capalized letters of the month Ex.(MAR). (enter \"-1\" to leave blank): ";
    cin>>Month;
    input_month = MonthConvert(Month);

    while(Month != "-1" && Month != "JAN" && Month != "FEB" && Month != "MAR" && Month != "APR" && Month != "MAY" && Month != "JUN" && Month != "JUL" && Month != "AUG" && Month != "SEP" && Month != "OCT" && Month != "NOV" && Month != "DEC"){
      cout<<"Invalid input, please enter the first 3 capalized letters of the month Ex.(MAR). (enter \"-1\" to leave blank): ";;
      cin>>Month;
      input_month = MonthConvert(Month);
    }

    cout<<"Please enter a numerical Day value Ex.(27). (enter \"-1\" to leave blank): ";
    cin>>Day;
    input_day = stoi(Day);

    if(input_month == 2){
      while((input_day > 28 || input_day < 1) && input_day != -1){
        cout<<"Invalid input, there are only 28 days in FEB."<<endl;
        cout<<"Please enter a numerical Day value Ex.(27). (enter \"-1\" to leave blank): ";
        cin>>Day;
        input_day = stoi(Day);
      }
    }else if(input_month == 4 || input_month == 6 || input_month == 9 ||input_month == 11){
      while((input_day > 30 || input_day < 1) && input_day != -1){
        cout<<"Invalid input, there are only 30 days in "<<Month<<"."<<endl;
        cout<<"Please enter a numerical Day value Ex.(27). (enter \"-1\" to leave blank): ";
        cin>>Day;
        input_day = stoi(Day);
      }
    }else{
      while((input_day > 31 || input_day < 1) && input_day != -1){
        cout<<"Invalid input, there are only 31 days in FEB."<<endl;
        cout<<"Please enter a numerical Day value Ex.(27). (enter \"-1\" to leave blank): ";
        cin>>Day;
        input_day = stoi(Day);
      }
    }

    cout<<"Please enter a numerical Hour of Time from 1 - 12. Ex.(6 PM is 6) & (6 AM is 6): ";
    cin>>Hour;
    input_time = stoi(Hour);

    while(input_time > 12 && input_time < 1){
      cout<<"Invalid input, enter a numerical Hour of Time from 1 - 12. Ex.(6 PM is 6) & (6 AM is 6): ";
      cin>>Hour;
      input_time = stoi(Hour);
    }

    cout<<"Is your event AM or PM? Ex.(PM)" << endl;
    cin>>Am_Pm;

    while(Am_Pm != "AM" && Am_Pm != "PM"){
      cout<<"Invalid input, please enter either AM or PM capitalized. ";
      cin>>Am_Pm;
    }

    if(Am_Pm == "PM"){
      Hour += 12;
    }

    if(input_month != -1 && input_day !=-1 && input_time != -1){
      if(this->event[input_month][input_day][input_time] != ""){
        if(input_time>12){
          cout << this->event[input_month][input_day][input_time] << " found at " << ConvertMonth(input_month) << " " << input_day << ", " << input_time-12 << ":00 PM, " << "\n";
        }else{
          cout << this->event[input_month][input_day][input_time] << " found at " << ConvertMonth(input_month) << " " << input_day << ", " << input_time << ":00 AM, " << "\n";
        }
        cout<<"Returning to main menu.";
      }else{
        cout << "No events found at ";
        if(input_time>12){
          cout << ConvertMonth(input_month) << " " << input_day << ", " << input_time-12 << ":00 PM, " << "\n";
        }else{
          cout << ConvertMonth(input_month) << " " << input_day << ", " << input_time << ":00 AM, " << "\n";
        }
        cout<<"Returning to main menu.";
      }
    }else if(input_month != -1 && input_day != -1 && input_time == -1){
      for(int z=1; z<25; z++){
        if(this->event[input_month][input_day][z] != ""){
          if(z>12){
            num++;
            cout << num << ".)" << ConvertMonth(input_month) << " " << input_day << ", " << z-12 << ":00 PM, " << this->event[input_month][input_day][z] << "\n";
          }else{
            num++;
            cout << num << ".)" << ConvertMonth(input_month) << " " << input_day << ", " << z << ":00 AM, " << this->event[input_month][input_day][z] << "\n";
          }
        }
      }
      if(num > 0){
        cout<<"Found the above events."<<endl;
        cout<<"Returning to main menu.";
      }else{
        cout<<"No events found at " << ConvertMonth(input_month) << " " << input_day << ", " << "\n";
        cout<<"Returning to main menu.";
      }

    }else if(input_month == -1 && input_day != -1 && input_time == -1){
      for(int x=1; x<13; x++){
        for(int z=1; z<25; z++){
          if(this->event[x][input_day][z] != ""){
            if(z>12){
              num++;
              cout << num << ".)" << ConvertMonth(x) << " " << input_day << ", " << z-12 << ":00 PM, " << this->event[x][input_day][z] << "\n";
            }else{
              num++;
              cout << num << ".)" << ConvertMonth(x) << " " << input_day << ", " << z << ":00 AM, " << this->event[x][input_day][z] << "\n";
            }
          }
        }
      }
      if(num > 0){
        cout<<"Found the above events."<<endl;
        cout<<"Returning to main menu.";
      }else{
        cout<<"No events found at " << input_day << "\n";
        cout<<"Returning to main menu.";
      }
    }else if(input_month != -1 && input_day == -1 && input_time == -1){
      for(int y=1; y<32; y++){
        for(int z=1; z<25; z++){
          if(this->event[input_month][input_day][z] != ""){
            if(z>12){
              num++;
              cout << num << ".)" << ConvertMonth(input_month) << " " << y << ", " << z-12 << ":00 PM, " << this->event[input_month][y][z] << "\n";
            }else{
              num++;
              cout << num << ".)" << ConvertMonth(input_month) << " " << y << ", " << z << ":00 AM, " << this->event[input_month][y][z] << "\n";
            }
          }
        }
      }
      if(num > 0){
        cout<<"Found the above events."<<endl;
        cout<<"Returning to main menu.";
      }else{
        cout<<"No events found in " << ConvertMonth(input_month) << "\n";
        cout<<"Returning to main menu.";
      }
    }else if(input_month == -1 && input_day == -1 && input_time == -1){
      cout<<"Not enough information given."<<endl;
      cout<<"Returning to main menu.";
    }else if(input_month != -1 && input_day == -1 && input_time != -1){
      for(int y=1; y<32; y++){
        if(this->event[input_month][y][input_time] != ""){
          if(input_time>12){
            num++;
            cout << num << ".)" << ConvertMonth(input_month) << " " << y << ", " << input_time-12 << ":00 PM, " << this->event[input_month][y][input_time] << "\n";
          }else{
            num++;
            cout << num << ".)" << ConvertMonth(input_month) << " " << input_day << ", " << input_time << ":00 AM, " << this->event[input_month][y][input_time] << "\n";
          }
        }
      }
      if(num > 0){
        cout<<"Found the above events."<<endl;
        cout<<"Returning to main menu.";
      }else{
        if(input_time>12){
          cout<<"No events found at " << ConvertMonth(input_month) << " " << input_time-12 << ":00 PM" << "\n";
        }else{
          cout<<"No events found at " << ConvertMonth(input_month) << " " << input_time << ":00 AM" << "\n";
        }
        cout<<"Returning to main menu.";
      }
    }else if(input_month == -1 && input_day == -1 && input_time != -1){
      for(int x=1; x<13; x++){
        for(int y=1; y<32; y++){
          if(this->event[x][x][input_time] != ""){
            if(input_time>12){
              num++;
              cout << num << ".)" << ConvertMonth(x) << " " << y << ", " << input_time-12 << ":00 PM, " << this->event[x][y][input_time] << "\n";
            }else{
              num++;
              cout << num << ".)" << ConvertMonth(x) << " " << y << ", " << input_time << ":00 AM, " << this->event[x][y][input_time] << "\n";
            }
          }
        }
      }
      if(num > 0){
        cout<<"Found the above events."<<endl;
        cout<<"Returning to main menu.";
      }else{
        if(input_time>12){
          cout<<"No events found at " << input_time-12 << ":00 PM" << "\n";
        }else{
          cout<<"No events found at " << input_time << ":00 AM" << "\n";
        }
        cout<<"Returning to main menu.";
      }
    }else if(input_month == -1 && input_day != -1 && input_time != -1){
      for(int x=1; x<13; x++){
        if(this->event[x][input_day][input_time] != ""){
          if(input_time>12){
            num++;
            cout << num << ".)" << ConvertMonth(x) << " " << input_day << ", " << input_time-12 << ":00 PM, " << this->event[x][input_day][input_time] << "\n";
          }else{
            num++;
            cout << num << ".)" << ConvertMonth(x) << " " << input_day << ", " << input_time << ":00 AM, " << this->event[x][input_day][input_time] << "\n";
          }
        }
      }
      if(num > 0){
        cout<<"Found the above events."<<endl;
        cout<<"Returning to main menu.";
      }else{
        if(input_time>12){
          cout<<"No events found at " << input_day << ", " << input_time-12 << ":00 PM" << "\n";
        }else{
          cout<<"No events found at " << input_day << ", " << input_time << ":00 AM" << "\n";
        }
        cout<<"Returning to main menu.";
      }
    }

  }else{
    for(int x=1; x<13; x++){
      for(int y=1; y<32; y++){
        for(int z=1; z<25; z++){
          if(this->event[x][y][z] == event){
            if(z>12){
              num++;
              cout << num << ".)" << ConvertMonth(x) << " " << y << ", " << z-12 << ":00 PM, " << this->event[x][y][z] << "\n";
            }else{
              num++;
              cout << num << ".)" << ConvertMonth(x) << " " << y << ", " << z << ":00 AM, " << this->event[x][y][z] << "\n";
            }
          }
        }
      }
    }
    if(num > 0){
      cout<<"Found the above events."<<endl;
      cout<<"Returning to main menu.";
    }else{
      cout<<"No events found under "<<event<<"."<<endl;
      cout<<"Returning to main menu.";
    }
  }

}



//Option 2 adds to the fucntion while asking the date , time , and how long numerically the event will last
// From this point the data is sent to the private list which there it saves the data.
// the data as well while loops until the user has put in a correct value for each of the Month , day , time , Hour , and AM or PM .

void Calander::option2(void){
  int Day, Hour, End, Num=0;
  int i=0;
  string Response, Am_Pm, Month, input_event,input_length,Yn,input_day;
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
  cin>>input_day;
  Day = stoi(input_day);

  while(input_month == 2 && (Day > 28 || Day < 1)){
     cout<<"Invalid input, there are only 28 days in FEB.";
     cin>>input_day;
    Day=stoi(input_day);
   }
   while((input_month == 4 || input_month == 6 || input_month == 9 || input_month == 11) && (Day > 30 || Day < 1)){
     cout<<"Invalid input, there are only 30 days in "<<Month<<".";
     cin>>input_day;
    Day=stoi(input_day);
   }
   while((input_month == 1 || input_month == 3 || input_month == 5 || input_month == 7 || input_month == 8 || input_month == 10 || input_month == 12) && (Day > 31 || Day < 1)){
      cout<<"Invalid input, there are only 31 days in "<<Month<<"."<<endl;
      cin>>input_day;
      Day=stoi(input_day);
   }

    cout<<"Please enter a numerical Hour of Time from 1 - 12 to mark when the event begins. Ex(6 PM is 6) & (6 AM is 6):";
    cin>>Hour;

    while(Hour > 12 || Hour < 1){
      cout<<"Invalid input for Hour."<<endl<<" Please enter a numerical Hour of Time from 1 - 12 to mark when the event begins. Ex(6 PM is 6) & (6 AM is 6):"<<endl;
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
    length_input = stoi(input_length);

    while(length_input < 1 || length_input > 24){
      cout<<"Invalid input."<<endl<<" Please enter your integer event length or 24(End of the day) if it goes till the end of the day. (it must be between 1 and 24 hours)."<<endl;
      cin>>input_length;
      length_input = stoi(input_length);
    }

    if(length_input + Hour > 24){
      blink_led_on(yellow);
      cout<<"NOTE: schedule cannot schedule events across multiple days. If you have an event that takes place multiple days you will need to schedule it for each day individually."<<endl;
      for(int z=Hour; z<25; z++){
        if(this->event[input_month][Day][z] != ""){
          Num++;
          cout<<Num<<".) "<<input_month<<"/"<<Day<<", "<<z<<", "<<this->event[input_month][Day][z];
        }
      }
    }else{
      for(int z=Hour; z<=(Hour+length_input)-1; z++){
        if(this->event[input_month][Day][z] != ""){
          Num++;
          cout<<Num<<".) "<<input_month<<"/"<<Day<<", "<<z<<", "<<this->event[input_month][Day][z];
        }
      }
    }


    End = Hour+length_input;
    if(End>12){
      End = End-12;
      Am_Pm = "PM";
    }

    if(Num > 0){
      blink_led_on(red);
      cout<<"The current event being added overlaps with the above event(s). Would you still like to add the event? (Y/N) (NOTE: scheduling this event will over write all overlapping events) ";
      cin>>Yn;

      while(Yn != "Y" && Yn != "N"){
        cout<<"Input invalid, please enter Y to add the event or N to return to the main menu without adding the event. ";
        cin>>Yn;
      }
      if(Yn == "Y"){
        for(int z=Hour; z<=(Hour+length_input)-1; z++){
          this->event[input_month][Day][z] = input_event;
        }
        cout<<"Event "<<input_event<<" scheduled for "<<Month<<" "<<Day<<" from "<<input_time<<Response<<" till "<<End<<Am_Pm<<"."<<endl;
        cout<<"Returning to main menu.";

      }else{
        cout<<"No events scheduled."<<endl;
        cout<<"Returning to main menu.";

      }
    }else{
      blink_led_on(green);
      cout<<"Input Time"<<input_time;
      cout<<"Are you sure you want to schedule "<<input_event<<" for "<<Month<<" "<<Day<<" from "<<Hour<<":00 "<<Response<<" till "<<End<<":00 "<<Am_Pm<<"? (Y/N)"<<endl;
      cin>>Yn;

      while(Yn != "Y" && Yn != "N"){
        cout<<"Input invalid, please enter Y to add the event or N to return to the main menu without adding the event. ";
        cin>>Yn;
      }
      if(Yn == "Y"){
        for(int z=Hour; z<=(Hour+length_input)-1; z++){
          this->event[input_month][Day][z] = input_event;
        }
        cout<<"Event "<<input_event<<" scheduled for "<<Month<<" "<<Day<<" from "<<Hour<<":00 "<<Response<<" till "<<End<<":00 "<<Am_Pm<<"."<<endl;
        cout<<"Returning to main menu.";
        //menu();
      }else{
        cout<<"No events scheduled."<<endl;
        cout<<"Returning to main menu.";
        //menu();
      }
    }
}

//For option3 the function goes through and scans in new values and adds to the list
//it ask through each time for the part numbers and from this point it sends to the load function which will add it

void Calander::option3(void){
  string Event, Month, Day, Hour, choice;
  int num=0, remove;

  cout<<"Enter the name of an event you would like to delete (case sensitive): ";
  cin>>Event;

  for(int x=1; x<13; x++){
    for(int y=1; y<32; y++){
      for(int z=1; z<25; z++){
        if(this->event[x][y][z] != ""){
          if(z>12){
            cout << num << ".)" << ConvertMonth(x) << " " << y << ", " << z-12 << ":00 PM, " << this->event[x][y][z] << "\n";
            num++;
          }else{
            cout << num << ".)" << ConvertMonth(x) << " " << y << ", " << z << ":00 AM, " << this->event[x][y][z] << "\n";
            num++;
          }
        }
      }
    }
  }
  if(num > 0){
    cout<<"Found the above events. Type any number from the list above to remove the corresponding event, or type 0 to remove all of them. (type -1 to exit to main menu) ";
    cin>>choice;
    remove = stoi(choice);

    while(remove > num){
      cout<<"Invalid input, pleas type a number from the list above to remove the corresponding event, or type 0 to remove all of them. (type -1 to exit to main menu) ";
      cin>>choice;
      remove = stoi(choice);
    }

    if(remove == -1){
      cout<<"Exiting to main menu.";
    }else if(remove == 0){
      cout<<"Are you sure you want to delete all events listed above? (Y/N)"<<endl;
      cin>>choice;

      while(choice != "Y" && choice != "N"){
        cout<<"Input invalid, please enter Y to add the event or N to return to the main menu without adding the event. ";
        cin>>choice;
      }

      if(choice == "Y"){
        for(int x=1; x<13; x++){
          for(int y=1; y<32; y++){
            for(int z=1; z<25; z++){
              if(this->event[x][y][z] != ""){
                this->event[x][y][z] == "";
              }
            }
          }
        }

        cout<<"All above events deleted."<<endl;
        cout<<"Returning to main menu.";
      }else{
        cout<<"No events deleted."<<endl;
        cout<<"Returning to main menu.";
      }
    }else{
      num = 1;
      for(int x=1; x<13; x++){
        for(int y=1; y<32; y++){
          for(int z=1; z<25; z++){
            if(this->event[x][y][z] != "" && num == remove){
              this->event[x][y][z] = "";
              if(z>12){
                cout << ConvertMonth(x) << " " << y << ", " << z-12 << ":00 PM, " << this->event[x][y][z] << " removed from callander.";
              }else{
                cout << ConvertMonth(x) << " " << y << ", " << z << ":00 AM, " << this->event[x][y][z] << " removed from callander.";
              }
            }else{
              num++;
            }
          }
        }
      }
    }

  }else{
    cout<<"No events found under "<<Event<<endl;
    cout<<"Returning to main menu";
  }

}

//This function writes out to an output file
//it loops through for size of the vector and outputs for each value
//from this it'd output to Final_Cal.txt
void Calander::option4(ofstream& ofile){

  //Goes through the event array and prints all events
  //and dates to the output file to save the data
  for(int x=1; x<13; x++){
    for(int y=1; y<8; y++){
      for(int z=1; z<25; z++){
        if(this->event[x][y][z] != ""){
          ofile << x << "," << y << "," << z << "," << this->event[x][y][z] << "\n\n";
        }
      }
    }
  }

}



// This is a output for the calander in a calander Format
// Essentially it will hav e a "*" if there is a event then
//else there will just be a dash at the event /
// the function will ask for a input to proceede to the next month
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
//this will exit with the option of 'Y' else
//if nothing is inputted it returns to the menu

void Calander::option6(void){
char op6;
cout<<"Exiting program."<<"\n" <<"Enter 'Y' to continue none of your data will be save:";
cin>>op6;
  if(op6 == 'Y'){
    exit(1);
  }

}


// seperate function
//MonthPrint
//Takes the Month input for the month and converts it to string output
//this is used for option 5 for the ideal printing of the months
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


// seperate function
//MonthCalander
//Takes the Month input for and converts it to numerical values
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


// seperate function
//ConvertMonth
//Takes the Month input int and converts it to string values
string Calander::ConvertMonth(int Month){
  string input_month;

  if(Month == 1){
    input_month = "JAN";
  }else if(Month == 1){
    input_month = "FEB";
  }else if(Month == 3){
    input_month = "MAR";
  }else if(Month == 4){
    input_month = "APR";
  }else if(Month == 5){
    input_month = "MAY";
  }else if(Month == 6){
    input_month = "JUN";
  }else if(Month == 7){
    input_month = "JUL";
  }else if(Month == 8){
    input_month = "AUG";
  }else if(Month == 9){
    input_month = "SEP";
  }else if(Month == 10){
    input_month = "OCT";
  }else if(Month == 11){
    input_month = "NOV";
  }else if(Month == 12){
    input_month = "DEC";
  }

  return input_month;

}
