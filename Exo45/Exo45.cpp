#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClientInfo {
	string accountNumber;
	short pinCode;
	string name;
	string phoneNumber;
	float accountBalance;
};

stClientInfo readClientInfo(stClientInfo &clientInfo) {
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


//method 1
// vector<string> readPersonRecords(vector<string> &vPersonInfo) {
//	 int accountNumber = 0;
//	 short pinCode = 0;
//	 string name = "";
//	 int phoneNumber = 0;
//	 float accountBalance = 0;
//	cout << "Please enter your account number ? ";
//	cin >> accountNumber;
//	vPersonInfo.push_back(to_string(accountNumber));
//	cout << "Please enter your pin code ? ";
//	cin >> pinCode;
//	vPersonInfo.push_back(to_string(pinCode));
//	cout << "Please enter your name ? ";
//	cin >> name;
//	vPersonInfo.push_back(name);
//	cout << "Please enter your phone number ? ";
//	cin >> phoneNumber;
//	vPersonInfo.push_back(to_string(phoneNumber));
//	cout << "Please enter your account balance ? ";
//	cin >> accountBalance;
//	vPersonInfo.push_back(to_string(accountBalance));
//	return vPersonInfo;
//}
//
//
//string convertRecordToStringWithDelim(vector<string>  vPersonInfo, string delim) {
//	string s1 = "";
//	for (string &info : vPersonInfo) {
//		s1 += info + delim;
//	}
//	for (short i = 0; i < delim.length(); i++) {
//		s1.pop_back();
//	}
//	return s1;
//}





int main()
{
	stClientInfo clientInfo;
	readClientInfo(clientInfo);
	cout << endl << "Client record for saving is: " << endl;
	cout << endl << convertRecordToStringWithDelim(clientInfo, "#//#");




	/*vector<string>  vPersonInfo;
	readPersonRecords(vPersonInfo);
	cout << endl << "Client record for saving is: " << endl;
	cout << endl << convertRecordToStringWithDelim(vPersonInfo, "#//#");*/


}

