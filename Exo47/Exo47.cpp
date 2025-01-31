#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
const string clientsFileName = "clients.txt";

struct stClientInfo {
	string accountNumber;
	short pinCode;
	string name;
	string phoneNumber;
	float accountBalance;
};

stClientInfo readNewClient() {
	stClientInfo clientInfo;
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

string convertRecordToLine(stClientInfo clientInfo, string delim) {
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


void AddNewClient()
{
	stClientInfo clientInfo;
	clientInfo = readNewClient();
	addClientToFile(clientsFileName,convertRecordToLine(clientInfo, "#//#"));
}


void addClients(){
	char AddMore = 'Y';
	do
	{
		system("cls");
		cout << "Adding New Client:\n\n";
		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
			cin >> AddMore;
	} while (toupper(AddMore) == 'Y');


}


int main()
{
	addClients();
	return 0;
}
