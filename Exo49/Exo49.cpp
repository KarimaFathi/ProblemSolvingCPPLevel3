#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
const string fileName = "clients.txt";

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0;
};

vector<string> splitString(string& clientRecord, string delim) {
	string word = "";
	vector<string> vString;
	short pos;
	while ((pos = clientRecord.find(delim)) != std::string::npos) {
		word = clientRecord.substr(0, pos);
		vString.push_back(word);
		clientRecord.erase(0, pos + delim.length());
	}
	if (clientRecord != "") {
		vString.push_back(clientRecord);
	}
	return vString;

}


stClient convertLineToRecord(string line, string delim) {
	stClient client;
	vector<string> vString;
	vString = splitString(line, "#//#");
	client.AccountNumber = vString[0];
	client.PinCode = vString[1];
	client.Name = vString[2];
	client.Phone = vString[3];
	client.AccountBalance = stod(vString[4]);
	return client;
}


vector<stClient> readFileContent(string fileName) {
	fstream myFile;
	short counter = 0;
	stClient client;
	vector<stClient> vStClient;
	myFile.open(fileName, ios::in);
	if (myFile.is_open()) {
		string line;
		while (getline(myFile, line)) {
			client = convertLineToRecord(line, "#//#");
			vStClient.push_back(client);
			counter++;
		}
		myFile.close();
	}
	return vStClient;
}



string readAccountNumber() {
	string AccountNumber;
	cout << "Please enter the account number : ";
	cin >> AccountNumber;
	return AccountNumber;

}

void isAccountNumberExists(vector<stClient> vStClient,string accountNumber) {
	bool isExists = false;
	for (stClient& client : vStClient) {
		if (client.AccountNumber == accountNumber) {
			isExists = true;
			cout << "\nThe following are the client details: \n";
			cout << "Account Number    : " << client.AccountNumber << endl;
			cout << "Pin Code          : " << client.PinCode << endl;
			cout << "Name              : " << client.Name << endl;
			cout << "Phone             : " << client.Phone << endl;
			cout << "Account Balance   : " << client.AccountBalance << endl;
		}
	}
	if (isExists == false) {
		cout << "\nClient with account number (" << accountNumber << ") not found !\n";
	}
}


int main()
{
	string accountNumber = readAccountNumber();
	vector<stClient> vStClient = readFileContent("clients.txt");
	isAccountNumberExists(vStClient, accountNumber);

}

