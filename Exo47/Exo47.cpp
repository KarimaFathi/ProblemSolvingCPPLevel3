#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct stClientInfo {
	string accountNumber;
	short pinCode;
	string name;
	string phoneNumber;
	float accountBalance;
};

stClientInfo readNewClient(stClientInfo& clientInfo) {
	cout << "Please enter your account number ? ";
	cin >> clientInfo.accountNumber;
	cout << "Please enter your pin code ? ";
	cin >> clientInfo.pinCode;
	cin.ignore();
	cout << "Please enter your name ? ";
	getline(cin, clientInfo.name);
	cout << "Please enter your phone number ? ";
	cin >> clientInfo.phoneNumber;
	cout << "Please enter your account balance ? ";
	cin >> clientInfo.accountBalance;
	return clientInfo;
}

string convertRecordToStringWithDelim(stClientInfo clientInfo, string delim) {
	string clientRecord = "";
	clientRecord += clientInfo.accountNumber + delim;
	clientRecord += to_string(clientInfo.pinCode) + delim;
	clientRecord += clientInfo.name + delim;
	clientRecord += clientInfo.phoneNumber + delim;
	clientRecord += to_string(clientInfo.accountBalance);
	return clientRecord;
}

void addClientToFile(string fileName, string record) {
	fstream MyFile;
	MyFile.open(fileName, ios::app);
	if (MyFile.is_open()) {
		MyFile << record << endl;
		MyFile.close();
	}
}



int main()
{
	stClientInfo clientInfo;
	string record;
	bool isMoreClients = true;
	string userInput;

	while (isMoreClients == true) {
		cout << "Adding new client : \n\n";
		readNewClient(clientInfo);
		record = convertRecordToStringWithDelim(clientInfo, "#//#");
		addClientToFile("myfile.txt", record);
		cout << "\nClient added successfully, do you want to add more clients ? (yes/no)  ";
		cin >> userInput; 
		if (userInput == "yes" || userInput == "YES") {
			isMoreClients = true;
		}
		else isMoreClients = false;
	}
}
