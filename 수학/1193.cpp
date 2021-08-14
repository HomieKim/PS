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
풀이 ㅈ 극혐
좋은 풀이는 아닌듯 하다
규칙을 찾아야함 대각선으로 커졌다 작아졌다 하니까 대각선을 한 그룹 이라 생각
1 그룹은 증감 없이 1/1로 고정 하고 짝수 그룹과 홀수 그룹으로 나눠 생각
그림 상 짝수 그룹은 아래로 증감 홀수 그룹은 위로 증감
그래서 짝수일때 1/group 홀수 일때 group/1로 기본값 설정하고 
한 그룹이 다음 그룹으로 넘어갈때 까지 짝수일때 left++ right-- 홀수일때 반대의 규칙을 가진다
그럼 얼마큼 증감 할거냐가 관건
몇 번째 수냐? = cnt, 즉 cnt에서 이전그룹의 의 개수를 다 빼주면됨 예를들어cnt = 14의 경우 5그룹이면 이전그룹(1,2,3,4)은 10개 겠지?
그럼 14-10= 4번을 반복문으로 증감해주면 좌표가 나오겠지
개 노가다 풀이


*/