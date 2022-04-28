using namespace std;


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>


#ifndef SSI_FUNCTIONS
#define SSI_FUNCTIONS
#include "SSI.h"
#endif



//finished
int menu()
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
	
}	// end menu









void option1(){

	int part_num;
	cout<<"You selected option 1"<<endl;


	cout<<endl;
	cout<<"Enter 2 or 3 digit part numbers to find"<<endl<<"\t"<<"(e.g., ""02"", ""32"", ""244""): ";

	cin>>part_num;



}



void option2(){
	string part_type;
	cout<<"You selected option 2"<<endl;

	cout<<"Enter logic type to find: ";

	cin>>part_type;


//find logic type using find_if()
}


void option3(){
	cout<<"You selected option 3"<<endl;
//adding part to the list using dynamic vector

}




void option4(){
	cout<<"You selected option 4"<<endl;

	//write out o a .part file same as pulling into file

}


//finished
void option5(){
	//cout<<"You selected option 5"<<endl;
	exit(1);

}










