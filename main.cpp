//******************************************************************
// Program #: Homework #4 main FIle
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



#include "Schedule.h"








int main(void){
  string Description,Part_number,Part_name;
  string Fam;
  string Pack;
  string VCC1,VCC2,VCC3,VCC4,VIH,VIL;

  	fstream infile;
    infile.open ("infile.part");
    ofstream outfile("outfile.part");

  
  string V_Description,V_Number,V_Name,V_Fam,V_Pack,V_VVC1,V_VCC2,V_VCC3,V_VCC4,V_VIH,V_VIL;
  


  TTL_board V;
  

  
  if(!infile.is_open()) {
    cout << "\nERROR Could not open input file "<<"!\n";
    cout << "Usage: prog1 <input file name>\n";
    return(-1);
  }


       


	
//print statements for cases 0-5
while(1){
	int op;
	op = V.menu();
	
	switch (op) {
		case 0:
			V.option0();
			break;

		case 1:
			V.option1();
			break;

		case 2:
			V.option2();
			break;

		case 3:
			V.option3();
			break;

		case 4:
			V.option4(outfile);
			outfile.close();

			break;

		case 5:
			outfile.close();
			V.option5();
			break;

		default:

		cout<<"Invalid Option!"<<endl;
		break;
		}
	}

}
