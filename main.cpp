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
//#include <wiringPi.h>
//#include <csignal>
#include <curses.h>


#include "Schedule.h"



/*void blink_led_on(int led) {
    digitalWrite(led, HIGH);
}

void blink_led_off(int led) {
    digitalWrite(led, LOW);
}
*/

/*
wiringPiSetupGpio();
pinMode(red, OUTPUT);
pinMode(yellow, OUTPUT);
pinMode(green, OUTPUT);
*/


int main(void){
  string Month, Day, Hour, Event;

  	fstream infile;
    infile.open("Inital_Cal.txt");
    ofstream outfile("Inital_Cal20.txt");


  Calander V;


//infile opening
//checks if the infile is opened each time
 if(!infile.is_open()) {
    cout << "\nERROR Could not open input file "<<"!\n";
    cout << "Usage: prog1 <input file name>\n";
    return(-1);
 }





while(!infile.eof()) {
  Month="";
  Day="";
  Hour="";
	getline(infile, Month, ',');
  //cout<<Month<<endl;
  getline(infile, Day, ',');
  //cout<<Day<<endl;
  getline(infile, Hour, ',');
  //cout<<Hour<<endl;
  getline(infile, Event, '\n');
  //cout<<Event<<endl;
  infile.ignore();

  //cout<<"Test"<<endl;
	V.load(Month, Day, Hour, Event);
}



//print statements for cases 0-6
// the while loop reitterates through the code after each case;

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
			V.option5();
			break;


    case 6:
      outfile.close();
      V.option6();
        break;

		default:

		cout<<"Invalid Option!"<<endl;
		break;
		}
	}

}
