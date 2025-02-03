#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
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

void printTableHeader(short counter) {
	char col1[] = "Account Number";
	char col2[] = "Pin Code";
	char col3[] = "Client Name";
	char col4[] = "Phone";
	char col5[] = "Balance";

	cout << "\t\t\t\t\t Client List (" << counter << ") Client(s).\n";
	cout << "_________________________________________________________________________________________________\n\n";

	// Use 'left' to align text to the left in each column
	cout << "| " << left << setw(16) << col1
		<< "| " << left << setw(11) << col2
		<< "| " << left << setw(40) << col3
		<< "| " << left << setw(12) << col4
		<< "| " << left << setw(10) << col5 << endl;

	cout << "_________________________________________________________________________________________________\n\n";
}


void printClientData(vector<stClient> vStClient) {
	for (const stClient& data : vStClient) {
		// Apply 'left' to align text to the left in each column
		cout << "| " << left << setw(16) << data.AccountNumber
			<< "| " << left << setw(11) << data.PinCode
			<< "| " << left << setw(40) << data.Name
			<< "| " << left << setw(12) << data.Phone
			<< "| " << left << setw(10) << data.AccountBalance << endl;
	}
	cout << "_________________________________________________________________________________________________\n";
}


int main()
{
	vector<stClient> vStClient = readFileContent("clients.txt");
	printTableHeader(vStClient.size());
	printClientData(vStClient);
}

