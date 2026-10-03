#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

class UpdateStock {
private:


public:

	void updateStock(string itemN, string quantity) {
		string fileName = "Stock.txt";
		ofstream outfile(fileName, ios::app);
		string line;
		while (outfile.is_open()) {



		}
	}
};