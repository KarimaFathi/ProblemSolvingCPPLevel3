#include <iostream>
#include <string>
#include <vector>
using namespace std;


//method 1
 vector<string> readPersonRecords(vector<string> &vPersonInfo) {
	 int accountNumber = 0;
	 short pinCode = 0;
	 string name = "";
	 int phoneNumber = 0;
	 float accountBalance = 0;
	cout << "Please enter your account number ? ";
	cin >> accountNumber;
	vPersonInfo.push_back(to_string(accountNumber));
	cout << "Please enter your pin code ? ";
	cin >> pinCode;
	vPersonInfo.push_back(to_string(pinCode));
	cout << "Please enter your name ? ";
	cin >> name;
	vPersonInfo.push_back(name);
	cout << "Please enter your phone number ? ";
	cin >> phoneNumber;
	vPersonInfo.push_back(to_string(phoneNumber));
	cout << "Please enter your account balance ? ";
	cin >> accountBalance;
	vPersonInfo.push_back(to_string(accountBalance));
	return vPersonInfo;
}


string convertRecordToStringWithDelim(vector<string>  vPersonInfo, string delim) {
	string s1 = "";
	for (string &info : vPersonInfo) {
		s1 += info + delim;
	}
	for (short i = 0; i < delim.length(); i++) {
		s1.pop_back();
	}
	return s1;
}


int main()
{
	vector<string>  vPersonInfo;
	readPersonRecords(vPersonInfo);
	cout << endl << "Client record for saving is: " << endl;
	cout << endl << convertRecordToStringWithDelim(vPersonInfo, "#//#");


}

