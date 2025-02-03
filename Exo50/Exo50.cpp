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


vector<stClient> loadFileContentToVector(string fileName) {
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

bool isAccountNumberExists(stClient &clientToFind, string accountNumber) {
	vector<stClient> vStClient = loadFileContentToVector("clients.txt");
	bool isExists = false;
	for (stClient& client : vStClient) {
		if (client.AccountNumber == accountNumber) {
			clientToFind = client;
			isExists = true;
			return isExists;
		}
	}
	return isExists;
}

string convertRecordToStringWithDelim(stClient clientInfo, string delim) {
	string clientRecord = "";
	clientRecord += clientInfo.AccountNumber + delim;
	clientRecord += clientInfo.PinCode + delim;
	clientRecord += clientInfo.Name + delim;
	clientRecord += clientInfo.Phone + delim;
	clientRecord += to_string(clientInfo.AccountBalance);
	return clientRecord;
}

void saveVectorToFile(string fileName, vector<stClient> vStClient) {
	fstream myFile;
	string line;
	myFile.open(fileName, ios::out);
	if (myFile.is_open()) {
		for (stClient& client : vStClient) {
			line = convertRecordToStringWithDelim(client, "#//#");
			myFile << line << endl;
		}
		myFile.close();
	}
}

void deleteClientFromFile(string fileName, string accountNumber) {
	vector<stClient> vStClient = loadFileContentToVector(fileName);
	for (vector<stClient>::iterator client = vStClient.begin(); client != vStClient.end(); client++) {
		 if (isAccountNumberExists(*client, accountNumber) == true) {
			 vStClient.erase(client);
			 break;
		 }
	}
	saveVectorToFile(fileName, vStClient);	
}



int main()
{
	string accountNumber = readAccountNumber();
	stClient client;
	char userAnswer;
	if (isAccountNumberExists(client, accountNumber) == true) {
		cout << "\nThe following are the client details: \n";
		cout << "Account Number    : " << client.AccountNumber << endl;
		cout << "Pin Code          : " << client.PinCode << endl;
		cout << "Name              : " << client.Name << endl;
		cout << "Phone             : " << client.Phone << endl;
		cout << "Account Balance   : " << client.AccountBalance << endl;
       
		cout << endl << "Are you sure you want to delete this client ? (y/n)\n";
		cin >> userAnswer;
		if (userAnswer == 'y' || userAnswer == 'Y') {
			deleteClientFromFile("clients.txt", accountNumber);
			cout << "Client Deleted Successfully.\n";
		}
	}
	else {
		cout << "\nClient with account number (" << accountNumber << ") not found !\n";
	}
	return 0;
}

