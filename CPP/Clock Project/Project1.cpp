#include <pch.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <format>
#include <chrono>

using namespace std;

/* 'clock' function creates the clocks and parameteres can be changed multiple times with each use */
namespace Clock {
    string Clock(unsigned int hour, unsigned int minute, unsigned int second) {
        unsigned int americanHour;
        string midday;

        /* if, else is used to determine the hour and AM/PM for the 12-hour clock */
        if (hour > 13 && minute >= 0) {
            americanHour = hour - 12;
            midday = "PM";
        }
        else if (hour == 12) {
            americanHour = hour;
            midday = "PM";
        }
        else {
            americanHour = hour;
            midday = "AM";
        }
        // I need to be able to print ## besides # for the time//
        /* clocks are outputted with format */
        cout << " " << setfill('*') << setw(27) << "   " << setw(22) << '\n';
        cout << " *    "
            << " 12-Hour Clock"
            << "   *    *   ";
        cout << "24-Hour Clock"
            << "  "
            << "*" << endl;
        cout << " *"
            << "       " << americanHour << ":" << hour << ":" << hour << ":"
            << " " << midday << "     *    *      ";
        cout << hour << ":" << minute << ":" << second << "      "
            << "*" << '\n';
        cout << " " << setfill('*') << setw(27) << "   " << setw(22) << '\n';

        return 0;
    };
}

/* this function displays the menu whenever needed */
void Menu() {
    cout << '\n' << "Do you want to make changes to the clocks?" << '\n' << '\n';
    cout << "Answer with the corresponding number described in the menu below: "
        << '\n'
        << '\n';
    cout << "    " << setfill('*') << setw(29) << '\n';
    cout << "    " << "*"
        << "   "
        << "1 - add one hour"
        << "       "
        << "*" << '\n';
    cout << "    " << "*"
        << "   "
        << "2 - add one minute"
        << "     "
        << "*" << '\n';
    cout << "    " << "*"
        << "   "
        << "3 - add one second"
        << "     "
        << "*" << '\n';
    cout << "    " << "*"
        << "   "
        << "4 - no, exit to clocks"
        << " "
        << "*" << '\n';
    cout << "    " << setfill('*') << setw(29) << '\n';
}

/* this function is used to display the clocks and menu, and then ask the user if anything needs to be changed. */
void ChangetoClock() {
    int userHour;
    int userMinute;
    int userSecond;
    int userAnswer;
    string exitAnswer;

    /* it asks for the initial time that the user wants to input into the clocks */
    cout << "What time do you want to display on the clocks?" << endl;
    cout << "Answer as follows: HH MM SS (i.e. 14 05 10)." << endl;

    cin >> userHour >> userMinute >> userSecond;
    cout << endl;

    /* the program checks to make sure the input was valid */
    if (userHour > 23 || userMinute > 59 || userSecond > 59) {
        cout << "Invalid input." << endl << endl;
        ChangetoClock();
    }
    else {
        userHour = userHour;
    }

    /* the program uses the clock and menu to ask the user if any changes need to be made to the clocks,
    * this loop will continue until the used answers that they want to exit to just show the clocks
    */
    while (exitAnswer != "y" or exitAnswer != "Y") {
        Clock(userHour, userMinute, userSecond);
        cout << endl;
        Menu();
        cout << endl;

        cin >> userAnswer;
        /* adds either a hour, minute, second, or shows 'invalid input' and continues until exit */
        if (userAnswer == 1) {
            userHour = userHour + 1;
            continue;
        }
        else if (userAnswer == 2) {
            userMinute = userMinute + 1;
            continue;
        }
        else if (userAnswer == 3) {
            userSecond = userSecond + 1;
            continue;
        }
        else if (userAnswer == 4) {
            /* double checks if the user wants to exit */
            cout << '\n' << "Do you want to exit the program? (y or n)" << endl;
            cin >> exitAnswer;
            
            /* breaks the loop and the user exits to clocks */
            if (exitAnswer == "y" or exitAnswer == "Y") {
                break;
            }
            else if (exitAnswer == "n" or exitAnswer == "N") {
                continue;
            }
            else {
                cout << '\n' << "Invalid answer." << endl << endl;
                continue;
            }
        }
        else {
            cout << '\n' << "Invalid answer." << endl << endl;
            continue;
        }
    }
    /* once the user exits the program, the clocks will display by themselves */
    cout << endl;
    Clock(userHour, userMinute, userSecond);
    cout << endl;
}

int main() {
    ChangetoClock();
    return 0;
}
int main() {
    ChangetoClock();
    return 0;
}
