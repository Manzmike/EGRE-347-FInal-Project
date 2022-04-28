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




class TTL_board
{
    private:
    int time_yn[7][24];
    string event[7][24];
    string input_day,input_time;
    // the entire year

    public:

    TTL_board(void);
    TTL_board(ifstream&);

    ~TTL_board(void);


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
