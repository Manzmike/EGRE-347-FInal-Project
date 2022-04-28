// Main file

//Uses Classes
//Uses Menu
// Add events
// looks at events
// Importing events
// export events
// Importing a time lib for 


// Making looking a actual time schu


//Takes time and if time is off then then tells user to exit and do touch *

//Ical/GCal exporting
//

//x


int main(void)
{	
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