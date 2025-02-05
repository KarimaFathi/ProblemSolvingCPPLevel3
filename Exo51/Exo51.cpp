#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
const string fileN = "clients.txt";


struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0;
	bool isMarkedToUpdate = false;
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

bool isAccountNumberExists(vector<stClient> vStClient, stClient& clientToFind, string accountNumber) {
	for (stClient& client : vStClient) {
		if (client.AccountNumber == accountNumber) {
			clientToFind = client;
			return true;
		}
	}
	return false;
}


void printClientRecord(stClient client) {
	cout << "\nThe following are the client details: \n";
	cout << "Account Number    : " << client.AccountNumber << endl;
	cout << "Pin Code          : " << client.PinCode << endl;
	cout << "Name              : " << client.Name << endl;
	cout << "Phone             : " << client.Phone << endl;
	cout << "Account Balance   : " << client.AccountBalance << endl;
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

void markClientForUpdateByAccountNum(vector<stClient>& vStClient, string accountNumber) {
	for (stClient& client : vStClient) {
		if (client.AccountNumber == accountNumber) {
			client.isMarkedToUpdate = true;
		}
	}
}
void getClientUpdatedInfo(vector<stClient>& vStClient) {

	for (stClient& client : vStClient) {
		if (client.isMarkedToUpdate == true) {
			cout << "\nPlease enter the new pin code ?";
			cin >> client.PinCode;
			cout << "Please enter the new name ?";
			cin.ignore(); //cin >> leaves a newline character (\n) in the input buffer, which causes the subsequent getline(cin, client.Name) to read an empty string.
			getline(cin, client.Name);
			cout << "Please enter the new phone number ?";
			cin >> client.Phone;
			cout << "Please enter the new account balance ?";
			cin >> client.AccountBalance;
		}
	}

}

void saveVectorToFile(string fileName, vector<stClient> vStClient) {
	fstream myFile;
	string line;
	myFile.open(fileName, ios::out); //overwrite
	if (myFile.is_open()) {
		for (stClient& client : vStClient) {
				line = convertRecordToStringWithDelim(client, "#//#");
				myFile << line << endl;
		}
		myFile.close();
	}
}


void updateClientInfo(vector<stClient>  &vStClient, string accountNumber) {
	stClient client;
	char answer = 'n';
	if (isAccountNumberExists(vStClient, client, accountNumber) == true) {
		printClientRecord(client);
		cout << endl << "Are you sure you want to update this client ? (y/n)\n";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			markClientForUpdateByAccountNum(vStClient, accountNumber);
			getClientUpdatedInfo(vStClient);
			saveVectorToFile(fileN, vStClient);
			//refresh clients
			/*vStClient = loadFileContentToVector(fileName);*/
			cout << "\nClient Updated Successfully.\n";
		}
	}
	else {
		cout << "\nClient with account number (" << accountNumber << ") not found !\n";
	}
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



int main()
{
	vector<stClient> vStClient = loadFileContentToVector("clients.txt");
	string accountNumber = readAccountNumber();
	updateClientInfo(vStClient, accountNumber);
	return 0;
}







