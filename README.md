# Calander Creator

The Calander Creator is a program that allows users to manage their events in a calendar-like structure. It provides functionality for adding, searching, removing, exporting, and visually viewing events scheduled for a particular day, month, or year.

## Features

- Schedule an event.
- Search for an event by date, time, or name.
- Display scheduled events.
- Remove events.
- Export the calendar to an output file.
- Display the calendar in a readable format with indication for days with events.

## Dependencies

- `wiringPi`: Required for GPIO functionality on Raspberry Pi.
- `iostream`, `string`, `csignal`, `fstream`, `iomanip`, `vector`: Standard C++ libraries for various functionalities.

## Usage

1. Create an object of the `Calander` class.
2. Utilize various functions available like `load()`, `menu()`, `option0()`, etc., to manage events.

## How it Works

The user is presented with a menu to:
- View current events.
- Search for events.
- Add events to the calendar.
- Remove events from the calendar.
- Export the calendar.
- Print the calendar in a calendar format.
- Exit the program.

The program uses LED lights (red, yellow, green) to indicate various states. For example, a red LED might be used to show a conflict in scheduling. The program also utilizes the wiringPi library for interacting with GPIO pins on a Raspberry Pi.

The `load()` function is used to read in values for the calendar. The program stores events in a 3D array, with dimensions representing month, day, and hour.

Events can be searched by date and time or by event name. The search functionality is equipped to handle different search criteria, such as searching by just the month, the month and day, or even the month, day, and time.

## Additional Information

The code makes use of the `stoi` function for string to integer conversion, a method which is detailed [here](https://www.programiz.com/cpp-programming/string-int-conversion).

## License

This project is open-source and free for all to use. Ensure you have the necessary dependencies installed before compiling and running the program.

## Acknowledgments

The program's design and functionalities are inspired by the need for a simple and efficient event manager that integrates with hardware components like LEDs.
