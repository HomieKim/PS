#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	while (str.find("c=") != string::npos) {
		str.replace(str.find("c="), 2, "a");
	}
	while (str.find("c-") != string::npos) {
		str.replace(str.find("c-"), 2, "a");
	}
	while (str.find("dz=") != string::npos) {
		str.replace(str.find("dz="), 3, "a");
	}
	while (str.find("d-") != string::npos) {
		str.replace(str.find("d-"), 2, "a");
	}
	while (str.find("lj") != string::npos) {
		str.replace(str.find("lj"), 2, "a");
	}
	while (str.find("nj") != string::npos) {
		str.replace(str.find("nj"), 2, "a");
	}
	while (str.find("s=") != string::npos) {
		str.replace(str.find("s="), 2, "a");
	}
	while (str.find("z=") != string::npos) {
		str.replace(str.find("z="), 2, "a");
	}
	
	

	cout << str.size() << endl;




}