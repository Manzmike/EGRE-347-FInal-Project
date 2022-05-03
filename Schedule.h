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




class Calander
{
    private:
    string event[12][31][24];
    string Copy_event[12][31][24];
    string input_month,input_day,input_time;
    // the entire year

    public:

    Calander(void);

    ~Calander(void);



    void load(string,string,string,string);
    int menu();
    void option0();
    void option1();
    void option2();
    void option3();
    void option4(ofstream&);
    void option5();
    void option6();
    void MonthPrint(int);
    int MonthConvert(string);
    string ConvertMonth(int);

    const int red = 5;
    const int yellow = 6;
    const int green = 13;


};
