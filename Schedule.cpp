using namespace std;


#include <iostream>
#include <string>
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

    Calander::Calander(ifstream& is){

      string day, time, event;

      for(int x=1; x<8; x++){
        for(int y=1; y<25; y++){
          getline(is, day, ',');
          getline(is, time, ',');
          getine(is, even, '\n');

          if(x == "0"){

            event[day][0] =
          }else{

          }
        }
      }
    }

    Calander::~Calander(void){
        //cout << "Deleting Part # " << Part_number << endl;
    }




int Calander::menu()
{
    int choice;

    cout<<"\nEnter option:\n";
    cout<<"\t(0) Print Your Current Calander\n";
    cout<<"\t(1) Search the for a Certian Event\n";
    cout<<"\t(2) Adding to Calander\n";
    cout<<"\t(3) Remove from Calander\n";
    cout<<"\t(4) Exporte Calander\n";
    cout<<"\t(4) Print Calander\n";
    cout<<"\t(5) Exit the program\n";
    cout<<"\t\tChoice ?";

    cin>>choice;
    return(choice);

}   // end menu








void Calander::option0(void){
  cout<<"OP 0";
}



void Calander::option1(void){
  cout<<"OP 1";
}




void Calander::option2(void){
  cout<<"OP 2";
}

//For option3 the function goes through and scans in new values and adds to the list
//it ask through each time for the part numbers and from this point it sends to the load function which will add it

void Calander::option3(void){
  cout<<"OP 3";
}


//This function writes out to an output file
//it loops through for size of the vector and outputs for each value

void Calander::option4(ofstream& ofile){

  //Goes through the event array and prints all events
  //and dates to the output file to save the data
  for(int x=1; x<8; x++){
    for(int y=1; y<25; y++){
      ofile << x << ", " << y << ", " << this->event[x][y] << "\n";
    }
  }

}

void Calander::option5(void){
  cout<<"OP 5";
}

//this essentially exits the program
void Calander::option6(void){
char op5;
cout<<"Exiting program."<<"\n" <<"Enter 'Y' to continue none of your data will be save:";
cin>>op5;
  if(op5 == 'Y'){
    exit(1);
  }
  else{
    menu();
  }

}
