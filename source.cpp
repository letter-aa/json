#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

//(insert stringX namespace here)

namespace json {
	map<string, string> parse(string str) {
		map<string, string> json;
		string name = "";
		string data = "";
		int fqNamePos = 0;
		int lqNamePos = 0;
		int fqDataPos = 0;
		int lqDataPos = 0;
		bool invalid = false;
        //int pos = str.find('"');
		vector <string> com;
		vector <string> col;
		//int qnum = 0; 
		if ((stringX::numOfStr(str,"{") == 1) && (invalid == false)){
		    stringX::replace_all(str, "{", "");
		} else {
		    cout << "invalid json syntax. missing \"{\" in " << str << ", pos: " << 0 << endl;
		    invalid = true;
		    return json;
		}
		if ((stringX::numOfStr(str,"}") == 1) && (invalid == false)){
		    stringX::replace_all(str, "}", "");
		} else {
		    cout << "invalid json syntax. missing \"{\" in " << str << ", pos: " << str.size() << endl;
		    invalid = true;
		    return json;
		}
		if (str.find(',') != string::npos){
		    stringX::splitString(str,com,",");
		}
		if (((com.size()) != 0) && (invalid == false)){
		    for (string&data : com){
		        //cout << data << endl;
		        if (data.find(':') != string::npos){
		            stringX::splitString(data,col,":");
		        } else {
		            cout << "invalid json syntax. missing \":\" in " << str << ", pos: " << str.find("\"",str.find(data) + 1) + 1 << endl;
		            invalid = true;
		        }
		    }
		} else {
		    if (stringX::numOfStr(str,":") > 1){
		        cout << "invalid json syntax. missing \",\" in " << str << ", pos: " << str.find("\"",str.find(":") + 1) << endl;
		        invalid = true;
		    } else {
		        stringX::splitString(str,col,":");
		    }
		}
		if (((col.size()) != 0) && (invalid == false)){
		    /*
		    for (string&data : col){
		        if (data.find('"') != string::npos){
		            data = data.substr(1,data.size() - 2) + "\0";
		        }
		    }*/
		    string prevData = "";
		    int inc = 1;
		    for (string&data : col){
		        if (inc % 2 == 1){
		            if (data.find('"') != string::npos){
		                if (stringX::numOfStr(data,"\"") == 2){
		                    data = data.substr(1,data.size() - 2) + "\0";
		                } else if (stringX::numOfStr(data,"\"") < 2){
        		           if (stringX::numOfStr(data,"\"") > 0){
        		               if (data[0] != '"'){
        		                cout << "invalid json syntax. missing \" in " << str << ", pos: " << str.find(data) << endl;
            		            invalid = true;
            		            break;
            		            } else if (data[data.size()] != '"') {
            		                cout << "invalid json syntax. missing \" in " << str << ", pos: " << str.find(data) + data.size() << endl;
                		            invalid = true;
                		            break;
            		            }
        		           }
        		        }
    		            prevData = data;
		                inc++;
    		        } else {
    		            cout << "invalid json syntax. missing quotation marks in " << str << ", pos: " << str.find(data) << " and " << str.find(data) + data.size() << endl;
    		            invalid = true;
                		break;
    		        }
		        } else {
		            if (data.find('"') != string::npos){
		                if (stringX::numOfStr(data,"\"") == 2){
		                    data = data.substr(1,data.size() - 2) + "\0";
		                } else if (stringX::numOfStr(data,"\"") < 2){
		                    if (stringX::numOfStr(data,"\"") > 0){
		                        
        		                if (data[0] != '"'){
        		                    cout << "invalid json syntax. missing \" in " << str << ", pos: " << str.find(data) << endl;
            		                invalid = true;
            		                break;
            		            } else if (data[data.size()] != '"') {
            		                cout << "invalid json syntax. missing \" in " << str << ", pos: " << str.find(data) + data.size() << endl;
                		            invalid = true;
                		            break;
            		            }
        		            }
    		            }
		            }
		            json[prevData] = data;
		            inc++;
		        }
		    }
		}
		return json;
	}
}
