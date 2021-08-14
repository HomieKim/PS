#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MyStruct
{
	int age;
	string name;
	int idx;
}typedef person;

bool cmp(person a, person b) {
	if (a.age == b.age) {
		return a.idx < b.idx;
	}
	else {
		return a.age < b.age;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	vector<person> vec;
	int inputAge;
	string inputName;
	person tmp;
	for (int i = 0; i < n; i++) {
		cin >> inputAge >> inputName;
		tmp.age = inputAge;
		tmp.name = inputName;
		tmp.idx = i;
		vec.push_back(tmp);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].age << " " << vec[i].name << '\n';
	}


}