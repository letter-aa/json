#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

//(insert stringX namespace here)


namespace json {
	map<string, string> parse(string str) {
		map<string, string> json;
		stringX::replace_all(str, "{", "");
		stringX::replace_all(str, "}", "");
		string name = "";
		string data = "";
		int fqNamePos = 0;
		int lqNamePos = 0;
		int fqDataPos = 0;
		int lqDataPos = 0;
		bool invalid = false;
		//		int pos = str.find('"');
		vector <string> com;
		vector <string> col;
		//int qnum = 0;
		if (str.find(',') != string::npos) {
			stringX::splitString(str, com, ",");
		}
		if ((com.size()) != 0) {
			for (string& data : com) {
				//cout << data << endl;
				if (data.find(':') != string::npos) {
					stringX::splitString(data, col, ":");
				}
				else {
					cout << "invalid json syntax. missing \":\"." << endl;
					invalid = true;
				}
			}
		}
		else {
			if (stringX::numOfStr(str, ":") > 1) {
				cout << "invalid syntax. missing \",\".";
			}
			else {
				stringX::splitString(data, col, ":");
			}
		}
		if (((col.size()) != 0) && (invalid == false)) {
			for (string& data : col) {
				if (data.find('"') != string::npos) {
					data = data.substr(1, data.size() - 2) + "\0";
				}
			}
			string prevData = "";
			int inc = 1;
			for (string& data : col) {
				if (inc % 2 == 1) {
					prevData = data;
					inc++;
				}
				else {
					json[prevData] = data;
					inc++;
				}
			}
		}
		return json;
	}
}
