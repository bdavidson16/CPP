#include "pch.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

void writeToFile(map<string, int> frequencyMap) {
    ofstream outFS;
    outFS.open("frequency.dat"); //creates and opens file/checks if file opened
    if (!outFS.is_open()) {
        cout << "Could not open file frequency.dat." << endl;
    }
    //writes map into file
    for (const auto& pair : frequencyMap) {
        outFS << pair.first << " " << pair.second << endl;
    }
    //checks if map was written into file
    if (!outFS.fail()) {
        cout << "File created and written to." << endl;
    } else {
        cout << "Failed to write to frequency.dat." << endl;
    }
    outFS.close(); //closes file
}

int main() {
    ifstream inFS;
    string itemName, userProduct;
    int menuOption, wordFreq;
    map<string, int> inventory;

    cout << "Opening file CS210_Project_Three_Input_File.txt." << endl;
    inFS.open("CS210_Project_Three_Input_File.txt"); // opens input file
    if (!inFS.is_open()) { // checks if file was found and opened
        cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
        return 1;
    }

    while (!inFS.fail()) {//reads each product in file and creates a map to show the frequency
        try {
            getline(inFS, itemName);
            if (inventory.count(itemName) == 1) {//if item already exists in map, then frequency is increased
                inventory.at(itemName) += 1;
            }
            else {
                inventory.emplace(itemName, 1); //else item is created
            }
        }
        catch (ios_base::failure& excpt) { //catches error in case input cannot be read
            cout << excpt.what() << endl;
            cout << "Cannot read file." << endl;
        }
    }
    if (!inFS.eof()) {
        cout << "Error reading file." << endl; //throws error if the file is not completely read
    }
    else {
        cout << "File read." << endl; //else tells user that file is completely and closes file
    }
    inFS.close();
    cout << "Closing file CS210_Project_Three_Input_File.txt." << endl << endl;

    writeToFile(inventory); //writes map to new file for backup

    cout << "Please choose menu option #1, 2, 3, or 4." << endl;
    cin >> menuOption; // user chooses menu option
    while (menuOption != 4) {
        if (menuOption == 1) {//outputs the frequency of the product
            cout << "Enter product name: ";
            cin >> userProduct;
            if (inventory.count(userProduct) == 1) {
                cout << inventory.at(userProduct) << endl;
            }
            else {
                cout << "Product not found." << endl;
            }
        }
        else if (menuOption == 2) {
            for (const auto& pair : inventory) { //outputs map to show frequency of each product
                cout << pair.first << " " << pair.second << endl;
            }
        }
        else if (menuOption == 3) {
            for (const auto& pair : inventory) { //outputs map using '*' in place of numbers for frequency
                wordFreq = inventory.at(pair.first);
                cout << pair.first << " " << setfill('*') << setw(wordFreq) << '\n';
            }
        }
        cout << endl << "Please choose menu option #1, 2, 3, or 4." << endl;
        cin >> menuOption;
    }
    if (menuOption == 4) {
        cout << "Program has ended." << endl;
    }
    return 0;
}



