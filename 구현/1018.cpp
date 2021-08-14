#include <iostream>
#include <vector>

using namespace std;
struct matrix
{
	char arr2d[8][8];
	int Bcount;
	int Wcount;
	int min;
}typedef mat;

mat get88mat(int a, int b, char** arr) {
	mat tmp;
	int copy = b;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tmp.arr2d[i][j] = arr[a][b];
			b++;
		}
		b = copy;
		a++;
	}
	return tmp;
}
char bw[8][8] = {
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};
char wb[8][8] = {
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};
int setCount(mat a) {
	int bcnt = 0;
	int wcnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (a.arr2d[i][j] != bw[i][j]) {
				bcnt++;
			}
			if (a.arr2d[i][j] != wb[i][j]) {
				wcnt++;
			}
		}
	}
	int rst;
	a.Bcount = bcnt;
	a.Wcount = wcnt;
	if (bcnt > wcnt) {
		rst = wcnt;
	}
	else {
		rst = bcnt;
	}
	return rst;
}
int main() {

	int n, m;
	cin >> n >> m;
	vector<mat> vec;
	// 2차원 배열 동적할당
	char** ary = new char* [n];         
	for (int i = 0; i < n; ++i) {
		ary[i] = new char[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ary[i][j];
		}
	}
	
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			mat tmp = get88mat(i, j, ary);
			vec.push_back(tmp);
		}
	}
	int rst = 99999999;
	for (int i = 0; i < vec.size(); i++) {
		vec[i].min = setCount(vec[i]);
		if (rst > vec[i].min) {
			rst = vec[i].min;
		}
	}
	cout << rst << endl;
	
}