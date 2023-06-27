#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

class contact
{
private:
    char fName[50], lName[50], address[50], email[50];
    long long phNo;

public:
    // function to collect the data

    void createContact()
    {
        cout << "Enter your first name: ";
        cin >> fName;

        cout << "Enter your last name: ";
        cin >> lName;

        cout << "Enter your phone number: ";
        cin >> phNo;

        cout << "Enter address: ";
        cin >> address;

        cout << "Enter eamil: ";
        cin >> email;
    }
    // function to show the data
    void showContact()
    {
        cout << "Name: " << fName << " " << lName << endl;
        cout << "Phone: " << phNo << endl;
        cout << "Address: " << address << endl;
        cout << "Email: " << email << endl;
    }
    // function that will save these data in a file
    void writeOnFile()
    {
        char ch;
        // output file is stream
        // we use ofstream whenever we want to write something in a file
        ofstream f1;
        f1.open("CMS.dat", ios::binary | ios::app);

        do
        {
            createContact();
            f1.write(reinterpret_cast<char *>(this), sizeof(*this));
            cout << "Do you have next data?(Y/N)";
            cin >> ch;
        }while (ch=='Y');

        cout << "Contact has been successfully created...";
        f1.close();
        
    }
};