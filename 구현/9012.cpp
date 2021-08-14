#include <iostream>
#include <vector>
#include <string>



using namespace std;

//int main() {
//
//	int n;
//	
//	cin >> n;
//	vector<string> v;
//	for (int i = 0; i < n; i++) {
//		string vps;
//		cin >> vps;
//		v.push_back(vps);
//	}
//
//	for (int i = 0; i < n; i++) {
//		while (true) {
//			v[i].erase(std::find(v[i].begin(), v[i].end(), "()"));
//			if(v[i].size() == 1){
//				cout << "No" << endl;
//				break;
//			}
//			else if(v[i].size() == 0) {
//				cout << "YES" << endl;
//				break;
//			}
//				
//		}
//	}
//}

int main() {

	int n;
	int cnt = 0;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string vps;
		cin >> vps;
		v.push_back(vps);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i].at(j) == '(') {
				cnt += 1;
			}
			else {
				cnt -= 1;
			}

			if (cnt < 0) {
				cout << "NO" << endl;
				break;
			}
		}
		if (cnt == 0) {
			cout << "YES" << endl;
		}
	}
}