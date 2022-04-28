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
    TTL_board::TTL_board(void){
        

    }

    TTL_board::~TTL_board(void){
        //cout << "Deleting Part # " << Part_number << endl;
    }



//finished
//finished
int TTL_board::menu()
{
    int choice;

    cout<<"\nEnter option:\n";
    cout<<"\t(0) Print the part list\n";
    cout<<"\t(1) Search for logic number\n";
    cout<<"\t(2) Search for logic type\n";
    cout<<"\t(3) Add part to the list\n";
    cout<<"\t(4) Save the list\n";
    cout<<"\t(5) Exit the program\n";
    cout<<"\t\tChoice ?";

    cin>>choice;
    return(choice);
    
}   // end menu








void TTL_board::option0(void){
cout<<"OP 0";
}



void TTL_board::option1(void){
cout<<"OP 1";

}




void TTL_board::option2(void){
cout<<"OP 2";
}

//For option3 the function goes through and scans in new values and adds to the list
//it ask through each time for the part numbers and from this point it sends to the load function which will add it

void TTL_board::option3(void){
   
string Description,Part_number,Part_name,Fam,Pack,VCC1,VCC2,VCC3,VCC4,VIH,VIL;
string BUFFER;
cout<<"OP 3";

}


//This function writes out to an output file
//it loops through for size of the vector and outputs for each value

void TTL_board::option4(ofstream& ofile){
    
cout<<"OP 4";
    
}

//this essentially exits the program
void TTL_board::option5(void){
cout<<"OP 5";
    exit(1);
}










