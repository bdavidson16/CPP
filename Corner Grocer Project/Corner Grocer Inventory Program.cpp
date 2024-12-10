#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Product {
private:
  map<string, int> productInventory;

public:
  void setProductInventory(string productName, int itemQuantity) { // adds product to map w/frequency
    productInventory.emplace(productName, itemQuantity);
  }
  void productMap(ifstream &inFS);
  void printProductQuantity(string productName) { // searchs map for user input and outputs associated frequency
    if (productInventory.count(productName) == 1) {
      cout << "Product Frequency: " << productInventory.at(productName) << endl << endl;
    } else {
      cout << "Product not found." << endl << endl;
    }
  }
  void printProductInventory() {
    for (const auto &pair : productInventory) { // outputs map to show frequency of each product
      cout << pair.first << " " << pair.second << endl;
    }
  }
  void printProductHistogram() {
    for (const auto &pair : productInventory) { // outputs map using '*' in place of numbers for frequency
      int wordFreq = productInventory.at(pair.first);
      cout << pair.first << " " << setfill('*') << setw(wordFreq + 1) << '\n';
    }
  }
  void writeToFile();
};

void Product::productMap(ifstream &inFS) {
  string itemName;
  while (!inFS.fail()) { // reads each product in file and creates a map to show the frequency
    try {
      getline(inFS, itemName);
      if (productInventory.count(itemName) == 1) { // if item already exists in map, then frequency is increased
        productInventory.at(itemName) += 1;
      } else {
        setProductInventory(itemName, 1); // else item is created
      }
    } catch (ios_base::failure &excpt) { // catches error in case input cannot be read
      cout << excpt.what() << endl;
      cout << "Cannot read file." << endl;
    }
  }
  if (!inFS.eof()) {
    cout << "Error reading file." << endl; // throws error if the file is not completely read
  } else {
    cout << "File read." << endl; // else tells user that file is completely and closes file
  }
}

void Product::writeToFile() {
  ofstream outFS;
  outFS.open("frequency.dat"); // creates and opens file/checks if file opened
  if (!outFS.is_open()) {
    cout << "Could not open file frequency.dat." << endl;
  }
  // writes map into file
  for (const auto &pair : productInventory) { // outputs map using '*' in place of numbers for frequency
    outFS << pair.first << " " << pair.second << endl;
  }
  // checks if map was written into file
  if (!outFS.fail()) {
    cout << "File created and written to." << endl << endl;
  } else {
    cout << "Failed to write to frequency.dat." << endl;
  }
  outFS.close(); // closes file
}

void menuDisplay() {
  cout << "Please choose menu option #1, 2, 3, or 4." << endl
       << "1. Print frequency of one item in inventory." << endl
       << "2. Print entire list of item frequency." << endl
       << "3. Print frequency histogram of entire list." << endl
       << "4. End program." << endl
       << endl;
}

int main() {
  ifstream inFS;
  string userProduct;
  int menuOption;

  cout << "Opening file Inventory_File.txt." << endl;
  inFS.open("Inventory_File.txt"); // opens input file
  if (!inFS.is_open()) { // checks if file was found and opened
    cout << "Could not open file Inventory_File.txt." << endl;
    return 1;
  }

  Product newProduct;
  newProduct.productMap(inFS); // creates new object and map

  inFS.close(); // closes file
  cout << "Closing file Inventory_File.txt." << endl << endl;

  newProduct.writeToFile(); // calls function to write map to file

  menuDisplay();
  cin >> menuOption; // user chooses menu option
  while (menuOption != 4) {
    if (menuOption == 1) { // outputs the frequency of the product
      cout << '\n' << "Enter product name: ";
      cin >> userProduct;
      newProduct.printProductQuantity(userProduct);
      cout << '\n';
    } else if (menuOption == 2) { // outputs the frequency map
      cout << '\n';
      newProduct.printProductInventory();
      cout << '\n';
    } else if (menuOption == 3) { // outputs the frequency histogram using asterisks
      cout << '\n';
      newProduct.printProductHistogram();
      cout << '\n';
    } else {
      cout << '\n' << "Invalid option..." << endl;
    }
    menuDisplay();
    cin >> menuOption;
  }
  if (menuOption == 4) {
    cout << endl << "Program has ended." << endl;
  }
  return 0;
}
