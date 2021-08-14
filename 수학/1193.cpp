#include <iostream>

using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	int left;
	int right;
	int group = 1;
	int chk = 0;

	if (cnt == 1) {
		left = 1;
		right = 1;
	}
	else {
		while (true) {

			chk += group;
			if (cnt - chk <= 0) {
				break;
			}
			group++;
		}
		if (group % 2 == 0) {
			left = 1;
			right = group;
		}
		else {
			left = group;
			right = 1;
		}

		for (int i = 1; i < cnt - (chk - group); i++) {
			if (group % 2 == 0) {
				left++;
				right--;
			}
			else {
				left--;
				right++;
			}
		}
	}
	
	cout << left << "/" << right << endl;

}

/*
Ǯ�� �� ����
���� Ǯ�̴� �ƴѵ� �ϴ�
��Ģ�� ã�ƾ��� �밢������ Ŀ���� �۾����� �ϴϱ� �밢���� �� �׷� �̶� ����
1 �׷��� ���� ���� 1/1�� ���� �ϰ� ¦�� �׷�� Ȧ�� �׷����� ���� ����
�׸� �� ¦�� �׷��� �Ʒ��� ���� Ȧ�� �׷��� ���� ����
�׷��� ¦���϶� 1/group Ȧ�� �϶� group/1�� �⺻�� �����ϰ� 
�� �׷��� ���� �׷����� �Ѿ�� ���� ¦���϶� left++ right-- Ȧ���϶� �ݴ��� ��Ģ�� ������
�׷� ��ŭ ���� �Ұųİ� ����
�� ��° ����? = cnt, �� cnt���� �����׷��� �� ������ �� ���ָ�� �������cnt = 14�� ��� 5�׷��̸� �����׷�(1,2,3,4)�� 10�� ����?
�׷� 14-10= 4���� �ݺ������� �������ָ� ��ǥ�� ��������
�� �밡�� Ǯ��


*/