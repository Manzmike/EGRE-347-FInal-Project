//******************************************************************
// Program #: Homework #2 .h FIle
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



enum Family {TTL ,BiCMOS ,CMOS};
enum Package {SSOP, SOIC, DIP, CFP, LCCC, SO};


class TTL_board
{
  
    void print(int,vector<string>,vector<string>,vector<string>,vector<string>,vector<string>,vector<string>,vector<string>,vector<string>,vector<string>,vector<string>,vector<string>);
    //prints vals
    void load(string,string,string,string,string,string,string,string,string,string,string);
    //prints vals
  

    int menu();
    void option0();
    void option1();
    void option2();
    void option3();
    void option4(ofstream&);
    void option5();
    void SearchNumber(string, int &, vector<string>&,vector<string>&,vector<string>&,vector<string>&,vector<string>&,vector<string>&,vector<string>&,vector<string>&,vector<string>&,vector<string>&,vector<string>&);
    void SearchName(string, int &, vector<string>&,vector<string>&,vector<string>&,vector<string>&,vector<string>&,vector<string>&,vector<string>&,vector<string>&,vector<string>&,vector<string>&,vector<string>&);



    
};

