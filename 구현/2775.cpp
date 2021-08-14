#include <iostream>
#include <vector>
using namespace std;

int main() {

	int num , k ,n;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> k >> n;
		vector<vector<int>> vec(k+1,vector<int>(n));
		
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			vec[0][j] = cnt;
			cnt++;
		}

		for (int m = 1; m < k+1; m++) {
			int a = 0;
			for (int y = 0; y < n; y++) {
				 vec[m][y]= a+ vec[m-1][y];
				 a += vec[m - 1][y];
			}
		}

		cout << vec[k][n-1] << endl;
	}

	

}