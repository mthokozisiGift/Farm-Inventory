#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <random>
#include <iomanip>

using namespace std;

class Stock {
private:


public:
	int itemID;
	string itemName;
	string itemDS;
	
	void Welcome(){
		string fileName = "Stock.txt";
		ofstream outfile(fileName, ios::app);
		
		cout << "Welcome to stock taking Page" << endl;
		cout << "----------------------------------------" << endl;
		double itemPrice;
		int itemQuantity;
		cout << "Item Name: " << endl;
		cin >> itemName;
		cout << "Item Price: " << endl;
		cin >> itemPrice;
		cout << "Item Quantity: " << endl;
		cin >> itemQuantity;

		if (outfile.is_open()) {

			static std::mt19937 rng(std::random_device{}());
			static std::uniform_int_distribution<int> dist(1000, 9999);
			itemID = dist(rng);
			
			outfile << "A" << itemID << "," << itemName << "," << fixed << setprecision(2) <<
				itemPrice << "," <<
				itemQuantity << endl;
			outfile.close();
			cout << "-------Item Added-------" << endl;

		}
		else {
			cout << "Error opening a file";
		}


		
	}
};