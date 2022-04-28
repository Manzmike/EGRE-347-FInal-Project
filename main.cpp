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
