#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include "Stock.cpp"
#include "Transaction.cpp"

using namespace std;

class ViewStock 
{

private:


public:

    void VS() {
        string fileName = "Stock.txt"; // file with username,password
        ifstream inFile(fileName);

        if (!inFile.is_open()) {
            cerr << "Error opening file!" << endl;
        }

        string itemFound, isearch;
        cout << "Search item: by Item Id, Name, Price" << endl;
        cin >> isearch;

        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string itemID, itemName, itemPrice, quantity;

            // Read username and password separated by comma
            getline(ss, itemID, ',');
            getline(ss, itemName, ',');
            getline(ss, itemPrice, ',');
            getline(ss, quantity, ',');

            if (itemID == isearch || itemName == isearch || itemPrice == isearch) {
                cout << "ITEM ID      : " << itemID << endl;
                cout << "ITEM Name    : " << itemName << endl;
                cout << "ITEM Price   : " << itemPrice << endl;
                cout << "ITEM Quantity: " << quantity << endl;
                cout << "----------------------------------" << endl;
                itemFound = 'Y';
            }

        }

        inFile.close();
        if (itemFound.empty()) {
            cout << "Item not found" << endl;
        }
    }
};

class RemoveItem
{

private:


public:

    void DS() {

        string itemToDelete;
        string fileName = "Stock.txt"; // file with username,password
        ifstream inFile(fileName);
        ofstream tempFile("temp.txt");

        if (!inFile || !tempFile) {
            cerr << "Error opening file!" << endl;
            
        }

        string itemFound, isearch;
        cout << "Enter item to delete: " << endl;
        cin >> itemToDelete;

        bool found = false;
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string itemID, itemName, itemPrice, quantity;

            // Read username and password separated by comma
            getline(ss, itemID, ',');
            getline(ss, itemName, ',');
            getline(ss, itemPrice, ',');
            getline(ss, quantity, ',');

            if (itemToDelete != itemName) {
                tempFile << line << endl;
            }
            else {
                found = true; // Mark that we found and skipped it
            }

        }

        inFile.close();
        tempFile.close();

        // Replace original file with updated one
        remove("Stock.txt");
        rename("temp.txt", "Stock.txt");

        if (found) {
            cout << "Item deleted successfully." << endl;
        }
        else{
            cout << "Item not found in file." << endl;
        }
    }
};

class HomePage {
private:


public:

    void welcome(string firstName, string lastname, string email) {
        string fname, lname, mail;
        fname = firstName;
        lname = lastname;
        mail = email;
        cout << "Welcome: " << fname << " " << lname << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "1. View Stock || 2. Add Item || 3. Remove Item " << endl;
        int opt = 0;
        cin >> opt;
        if (opt == 1) {
            
            cout << "-----------------------------------------------------" << endl;
            cout << "*******************View Stock************************" << endl;
            cout << "-----------------------------------------------------" << endl;

            ViewStock viewStock;
            viewStock.VS();

        }
        else if (opt == 2) {
            Stock stock;
            stock.Welcome();
        }
        else if (opt == 3) {
            RemoveItem removeItem;
            removeItem.DS();
        }
    }
};

class LoginScreen
{
private:
    string usernam, passcode;
public:

    void loginScreen() {

    }
   
   void loginScreen(string usernam, string passcode) {
       // to be continued
       HomePage hpage;
       string un, pc;
       string fileName = "EmployeeDetails.txt"; // file with username,password
       ifstream inFile(fileName);

       cout << "....Checking File......." << endl;
       if (!inFile.is_open()) {
           cerr << "Error opening file!" << endl;
       }
       else {
           cout << "....File Found......." << endl;
       }

       string line;
       while (getline(inFile, line)) {
           stringstream ss(line);
           string username, firstname, lastname, emailA, password;

           // Read username and password separated by comma
           getline(ss, username, ',');
           getline(ss, firstname, ',');
           getline(ss, lastname, ',');
           getline(ss, emailA, ',');
           getline(ss, password);

           cout << "....Checking User......." << endl;
           un = usernam;
           pc = passcode;

              if (un == username && pc == password) {
                   hpage.welcome(firstname,lastname,emailA);
                   inFile.close();
              }
              else {
                  cout << "...............User not found.............." << endl;
              }
      
       }

       inFile.close();

   }
};
 
class RegisterUser
{
private:
    string username, firstname, lastname, emailA ,passcode;
public:

    void registerEmployee() {
        cout << "Enter Username: " << endl;
        cin >> username;
        cout << "Enter Firtst Name: " << endl;
        cin >> firstname;
        cout << "Enter Last Name: " << endl;
        cin >> lastname;
        cout << "Enter email address: " << endl;
        cin >> emailA; 
        cout << "Enter secret passcode: " << endl;
        cin >> passcode;

        string fileName = "EmployeeDetails.txt";
        ofstream outfile(fileName, ios::app);
   
        if (outfile.is_open()) {
            outfile << username << "," << firstname << "," << lastname << "," << emailA << "," << passcode << endl;
            outfile.close();
            cout << "Employee successfuly registered!!!" << endl;
        }
        else {
            cout << "Error opening a file";
        }

    }

};


int main()
{
    LoginScreen logUser;
    RegisterUser reguser;
    
    
    string cont = "Y";
    while (cont == "Y") {
        cout << "1. LOGIN | 2. REGISTER | 3. MAKE A PURCHASE" << endl;
        int opt = 0;
        cin >> opt;

        if (opt == 1) {
            string user;
            string pcode;
            cout << "Enter username: " << endl;
            cin >> user;
            cout << "Enter password: " << endl;
            cin >> pcode;

            //Login
            logUser.loginScreen(user, pcode);
            cout << "Continue? Y/N";
            cin >> cont;
        }
        else if (opt == 2) {
            // Register
            reguser.registerEmployee();
            cout << "Continue? Y/N";
            cin >> cont;
        }
        else if (opt == 3){
            //Purchases
            Purchase p;
            p.boughtProduct();
            cout << "Continue? Y/N";
            cin >> cont;
        }
        else {
            cout << "Invalid Option :(";
            cout << "Continue? Y/N";
            cin >> cont;
        }
    }
}


