#include <iostream>
#include <deque>

using namespace std;

int T, n;
string query, strArr;
// string로 바꾸고 parsing 하는 부분 수정하면 될듯
deque<string> parseArr(string strArr) {
	deque<string> tmpDeq = {};
	string tmpStr = "";
	for (auto c : strArr) {
		if (c == '[') {
			continue;
		}
		else if (c == ','  || c == ']') {
			if (tmpStr != "") {
				tmpDeq.push_back(tmpStr);
				tmpStr = "";
			}
		}
		else {
			tmpStr += c;
		}
	}
	return tmpDeq;
}

//deque<string> reverseDeq(deque<string> deq) {
//	deque<string> tmpDeq = {};
//	int deqSize = deq.size();
//	for (int i = deqSize - 1; i >= 0; i--) {
//		tmpDeq.push_back(deq[i]);
//	}
//	return tmpDeq;
//}

void printDeq(deque<string> deq, int reverse) {
	
	int size_ = deq.size();
	if (size_ == 0) {
		cout << "[]" << '\n';
	}
	else {
		cout << '[';
		if (reverse == -1) {
			for (int i = size_ - 1; i >= 0; i--) {
				if (i == 0) {
					cout << deq[i];
				}
				else {
					cout << deq[i] << ',';
				}
			}
		}
		else {
			for (int i = 0; i < size_; i++) {
				if (i == size_ - 1) {
					cout << deq[i];
				}
				else {
					cout << deq[i] << ',';
				}
			}
		}
		cout << ']' << '\n';
	}
	
}


void solve(string query, int n, string strArr) {
	
	deque<string> deq = parseArr(strArr);
	int reverse = 1;
	
	for (char c : query) {
		if (c == 'R') {
			reverse *= -1;
		}
		else {
			if (deq.empty()) {
				cout << "error" << '\n';
				return;
			}
			else {
				if (reverse == -1) {
					deq.pop_back();
				}
				else {
					deq.pop_front();
				}
				
			}
		}
	}

	printDeq(deq, reverse);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> query;
		cin >> n;
		cin >> strArr;
		solve(query, n, strArr);
	}
}