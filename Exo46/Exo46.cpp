#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};



vector<string> splitString(string &clientRecord, string delim) {
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

int main()
{
	string clientRecord = "A150#//#1234#//#Fathi Karima#//#09-6654087#//#5270.000000";
	cout << "Line record is : \n" << clientRecord;
	cout << "\n\nThe following is the extracted client record.\n\n";
	stClient client = convertLineToRecord(clientRecord, "#//#");
	cout << "Account Number    : " << client.AccountNumber << endl;
	cout << "Pin Code          : " << client.PinCode << endl;
	cout << "Name              : " << client.Name << endl;
	cout << "Phone             : " << client.Phone << endl;
	cout << "Account Balance   : " << client.AccountBalance << endl;
	return 0;
   
}

