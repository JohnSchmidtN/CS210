/* John Schmidt
 Date: November 14, 2025
 CS 210: Programming Languages
 Description: This Program implements a simple clock that displays
 both 12-hour and 24-hour format with the ability to add time
 */

#include <iostream>

using namespace std;

class ChadaClock {

	// private data used by methods within the class
private:
	int hours24;
	int minutes;
	int seconds;
	bool isPM;  // true if PM false if AM

	int CalcHour12(bool& isPM) { // Checks to false for AM
		if (hours24 == 0) {
			isPM = false;
			return 12;
		}
		else if (hours24 == 12) {
			isPM = true;  // Checks to true for PM
			return 12;
		}

		else if (hours24 > 12) {
			isPM = true;  // Checks to true for PM
			return hours24 - 12;
		}
		else {
			isPM = false;  // Checks to false for AM
			return hours24;
		}
	};
	// Causes hour to increment and roll over at 24
	void AddHour(void) {
		hours24++;  
		if (hours24 == 24) {
			hours24 = 0;
		}
	};
	// Causes minute to increment and roll over at 60
	void AddMinute(void) {
		minutes++;
		if (minutes == 60) {
			minutes = 0;
			AddHour(); // Calls to AddHour to increment hour when minutes roll over
		}
	};
	// causes second to increment and roll over at 60
	void AddSecond(void) {
		seconds++;
		if (seconds == 60) {
			seconds = 0;
			AddMinute();  // Calls to AddMinute to increment minute when seconds roll over
		}
	};

	void DisplayTime(void) {
		// Displays top border for the 12-hour clock
		for (int i = 0; i < 27; i++) {
			cout << "*";
		}
		// Spacing between the 12-hour and 24-hour clocks
		cout << "    ";
		// Displays top border for the 24-hour clock
		for (int i = 0; i < 27; i++) {
			cout << "*";
		}
		// Causes new line after top borders
		cout << endl;
		// Displays titles for both the 12-hour and 24-hour clocks
		cout << "*      12-Hour Clock:     *    *      24-Hour Clock:     *" << endl;

		// Displays 12-hour clock
		cout << "*       ";
		// Displays hours
		if (CalcHour12(isPM) < 10) {
			cout << "0" << CalcHour12(isPM) << ":";
		}
		else {
			cout << CalcHour12(isPM) << ":";
		}

		// Displays minutes
		if (minutes < 10) {
			cout << "0" << minutes << ":";
		}
		else {
			cout << minutes << ":";
		}

		// Displays seconds

		if (seconds < 10) {
			cout << "0" << seconds;
		}
		else {
			cout << seconds;
		}

		// Displays AM or PM
		if (isPM == true) {
			cout << " PM       *";
		}
		else {
			cout << " AM       *";
		}

		// Adds spacing between the two clocks
		cout << "    ";

		// Displays 24-hour clock
		cout << "*        ";

		// Displays hours
		if (hours24 < 10) {
			cout << "0" << hours24 << ":";
		}
		else {
			cout << hours24 << ":";
		}

		// Displays minutes
		if (minutes < 10) {
			cout << "0" << minutes << ":";
		}
		else {
			cout << minutes << ":";
		}

		// Displays seconds
		if (seconds < 10) {
			cout << "0" << seconds << "         *" << endl;
		}
		else {
			cout << seconds << "        *" << endl;
		}

		// Bottom border of 12-hour clock
		for (int i = 0; i < 27; i++) {
			cout << "*";
		}

		// Spacing between the two clocks
		cout << "    ";

		// Bottom border of 24-hour clock
		for (int i = 0; i < 27; i++) {
			cout << "*";
		}
	};

	// Displays menu options
	void DisplayMenu(void) {
		// Spacing to center menu
		cout << "                ";
		// Top border of menu
		for (int i = 0; i < 27; i++) {
			cout << "*";
		}
		cout << endl;

		// Menu option 1
		cout << "                * 1 - Add One Hour        *" << endl;

		// Menu option 2
		cout << "                * 2 - Add One Minute      *" << endl;

		// Menu option 3
		cout << "                * 3 - Add One Second      *" << endl;

		// Menu option 4
		cout << "                * 4 - Exit Program        *" << endl;

		// Spacing to center menu
		cout << "                ";

		// Bottom border of Menu
		for (int i = 0; i < 27; i++) {
			cout << "*";
		}
	};

public:
	// Clears the screen
	void ClearScreen(void) {
		system("CLS");
	};
	// Displays the time and menu
	void Display(void) {
		DisplayTime();
		cout << endl;
		DisplayMenu();
	};
	// Reads user inputs for the menu and calls appropriate methods
	bool ReadUserInput(void) {

		int input;
		cin >> input;

		switch (input) {
		// Calls to add hour
		case 1:
			AddHour();
			return false;
			break;
		// Calls to add minute
		case 2:
			AddMinute();
			return false;
			break;
		// Calls to add second
		case 3:
			AddSecond();
			return false;
			break;
		// Exits the program
		case 4:
			return true;
			break;
		}
	};
	// Initializes the clock with predefined time
	void Initialize(int hour, int minute, int second) {
		hours24 = hour;
		minutes = minute;
		seconds = second;
	};
};
// Main method
int main(void) {
	// Creates the instance of ChadaClock
	ChadaClock clock;
	// Initializes the clock  
	clock.Initialize(3, 45, 52);
	// Main loop
	while (1) {
		clock.ClearScreen();
		clock.Display();
		cout << endl;
		if (clock.ReadUserInput()) {
			break;
		}

	}
}



