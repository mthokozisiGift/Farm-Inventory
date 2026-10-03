#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

class Purchase {
private:


public:

	void boughtProduct(){
		

		string itemN, itemQ, itemFound, cont;
        cont = "Y";

		while (cont == "Y") {
            
            string fileName = "Stock.txt"; // file with username,password
            ifstream inFile(fileName);
            string fileName2 = "Pucharsed.txt";
            ofstream outfile(fileName, ios::app);

            cout << "Enter Product: " << endl;
            cin >> itemN;
            cout << "How many do you want? " << endl;
            cin >> itemQ;

            string line;
            while (getline(inFile, line)) {
                stringstream ss(line);
                string itemID, itemName, itemPrice, quantity;
                int total, totalItems;
                // Read data in the text file
                getline(ss, itemID, ',');
                getline(ss, itemName, ',');
                getline(ss, itemPrice, ',');
                getline(ss, quantity, ',');

                if (itemName == itemN) {

                    if (quantity != "0") {
                        total = stoi(itemPrice) * stoi(itemQ);
                        totalItems = stoi(quantity) - stoi(itemQ);
                        quantity = to_string(totalItems);
                        outfile << itemID + "," + itemName + "," + itemPrice + "," + quantity;
                    }

                    cout << "Puchased: "<< line << endl;
                    itemFound = "Y";
                }

                if (itemFound.empty()) {
                    cout << "Item out of Stock." << endl;
                    cout << "Continue Shopping? Y/N" << endl;
                    cin >> cont;
                }
                else {
                    cout << "Continue Shopping? Y/N" << endl;
                    cin >> cont;
                }
            }
            
            inFile.close();
		}   
	}
};