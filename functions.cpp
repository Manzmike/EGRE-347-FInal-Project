//******************************************************************
// Program #: Homework SSI FIle
//
// Programmer: Michael Lindsay
// Due Date: NA
//
// EGRE 347, Spring 2022       Instructor: Robert Klenke
//
// Pledge: I have neither given nor received unauthorized aid on this program.
//
// Description: All of the needed decreactions for the file
//
// Input: None in this file
//
// Output: none
//
//******************************************************************
using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <deque>


#include "SSI.h"


    

    //default constructure
    TTL_board::TTL_board(void){
        

    }

    TTL_board::~TTL_board(void){
        //cout << "Deleting Part # " << Part_number << endl;
    }


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


//this will loop through each time and ask the student each time to enter a key before printing
//from this point it willl seek if input value is q if so it will quit

void TTL_board::option0(void){
    int i=0;
    cout<<"You selected option 0"<<endl;
    string input_val;
    input_val="notq";
    
    for(auto it = V_Description.begin();it != V_Description.end() || input_val == "q"; it++) {
        cout<<endl<<"\t"<<"Hit (q) to quit, any other key to continue:";
        cin>>input_val;
       
        i++;

        if(input_val == "q"){
            return;
        }

        if(i == V_Number.size()){
            return;
        }

         print(i);
     }
}



//option 2 impliments a temp vector string values from this point it as well loops through to find 
// the logic type to find
// As well it will output and ask which value to seek 
//from this point it will promot you to input the part number
//then it will print
//if that value is out of the range it will exit

void TTL_board::option1(void){
   
    string input;
    int select;
    int i=0;

    vector<string> Namevector,Numbervector,Desvector,Famvector,Packvector,VCC1vector,VCC2vector,VCC3vector,VCC4vector,VIHvector,VILvector;
    cout<<"Enter 2 or 3 digit part numbers to find"<<endl<<"\t"<<"(e.g., ""02"", ""32"", ""244""): ";
    cin>>input;
    for(auto it = V_Number.begin();it != V_Number.end(); it++) {
        SearchNumber(input, i, Namevector,Numbervector,Desvector,Famvector,Packvector,VCC1vector,VCC2vector,VCC3vector,VCC4vector,VIHvector,VILvector);
    }
    if(Numbervector.size()>0){
        for(int i=0;i < Numbervector.size();i++) {
            cout<<"(" << i << ")  "<< Numbervector[i]<<" "<<Namevector[i]<<endl;
        }
        while(1){
            cout<<"Select part: "; 
            cin>>select;

            if(select > Numbervector.size()-1){
                cout<<endl<<endl<<"Returning to main menu"<<endl<<endl;
                return;
            }

            else{
                print(select,Namevector,Numbervector,Desvector,Famvector,Packvector,VCC1vector,VCC2vector,VCC3vector,VCC4vector,VIHvector,VILvector);
            }
        }
    }


}


//option 2 impliments a temp vector string values from this point it as well loops through to find 
// the logic type to find
// As well it will output and ask which value to seek 
//from this point it will promot you to input the part number
//then it will print
//if that value is out of the range it will exit


void TTL_board::option2(void){
    string input;
    int select;
    int i=0;
    
    vector<string> Namevector,Numbervector,Desvector,Famvector,Packvector,VCC1vector,VCC2vector,VCC3vector,VCC4vector,VIHvector,VILvector;
    cout<<"Enter logic type to find: ";
    cin>>input;
    for(auto it = V_Name.begin();it != V_Name.end(); it++) {
        SearchName(input, i, Namevector,Numbervector,Desvector,Famvector,Packvector,VCC1vector,VCC2vector,VCC3vector,VCC4vector,VIHvector,VILvector);
        
    }
    if(Namevector.size()>0){
        for(int i=0;i < Namevector.size()-1;i++) {
            cout<<"(" << i << ")  "<< Namevector[i]<<endl;
        }
        while(1){
            cout<<"Select part: "; 
            cin>>select;

            if(select > Namevector.size()-1){
                cout<<endl<<endl<<"Returning to main menu"<<endl<<endl;
                return;
            }

            else{
                print(select,Namevector,Numbervector,Desvector,Famvector,Packvector,VCC1vector,VCC2vector,VCC3vector,VCC4vector,VIHvector,VILvector);
            }
        }

    }

}

//For option3 the function goes through and scans in new values and adds to the list
//it ask through each time for the part numbers and from this point it sends to the load function which will add it

void TTL_board::option3(void){
   
string Description,Part_number,Part_name,Fam,Pack,VCC1,VCC2,VCC3,VCC4,VIH,VIL;
string BUFFER;
    getline(cin,BUFFER);
    cout<<"Enter Part Number (ex. SN7415N): ";
      getline(cin,Part_number);
     cout<<"Enter Part Name (ex. Triple 3 Input AND Gate) :";
      getline(cin,Part_name);
    cout<<"Enter Part Description:";
      getline(cin,Description);
    cout<<"Enter Part Family (i.e., TTL, CMOS, BiCMOS) :";
      getline(cin,Fam);
    cout<<"Enter Part Package (i.e., SSOP, SOIC, DIP, CFP, LCCC,SO) :";
      getline(cin,Pack);
    cout<<"Enter VCC options (most be 4 numbers i.e., 3.3 2.5 1.8 0.0):";
      cin>>VCC1;
      cin>>VCC2;
      cin>>VCC3;
      cin>>VCC4;
    getline(cin,BUFFER);
    cout<<"Enter Vil (e.g., 0.8) :";
      getline(cin,VIL);
    cout<<"Enter Vih (e.g., 2.7) :";
      getline(cin,VIH);
      
load(Part_name,Part_number,Description,Fam,Pack,VCC1,VCC2,VCC3,VCC4,VIH,VIL);

}


//This function writes out to an output file
//it loops through for size of the vector and outputs for each value

void TTL_board::option4(ofstream& ofile){
    
    for(int i=0;i < V_Name.size();i++) {
        ofile << V_Number[i] << endl;
        ofile << V_Name[i] <<endl;
        ofile << V_Description[i] << endl;
        ofile << V_Fam[i] <<endl;
        ofile <<V_Pack[i] << endl;
        ofile << V_VCC1[i] << " " << V_VCC2[i] << " " << V_VCC3[i] << " " << V_VCC4[i] << endl;
        ofile << V_VIH[i] << endl;
        ofile << V_VIL[i] << endl;
    }
    
}

//this essentially exits the program
void TTL_board::option5(void){
    exit(1);
}


