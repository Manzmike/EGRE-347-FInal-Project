prog1.exe : main.o Schedule.o
	g++ main.o Schedule.o -lwiringPi -o prog1

main.o : main.cpp Schedule.h
	g++ -c main.cpp

Schedule.o : Schedule.cpp Schedule.h
	g++ -c Schedule.cpp


clean :
	rm *.o
	rm prog1
