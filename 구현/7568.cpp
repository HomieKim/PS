#include <iostream>
#include <vector>

using namespace std;

struct Person
{
	int weight;
	int height;
	int rank;
}typedef person;

bool setRank(person per1, person per2) {
	if (per1.weight < per2.weight && per1.height < per2.height) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int n; 
	cin >> n;
	vector<person> list(n);
	for (int i = 0; i < n; i++) {
		int w, h;
		cin >> w >> h;
		list[i].weight = w;
		list[i].height = h;
		
	}

	
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (setRank(list[i], list[j])) {
				cnt++;
			}
		}
		cout << cnt << " ";
	}

}