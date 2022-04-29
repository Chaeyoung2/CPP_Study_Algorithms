// 점수가 특정 조건을 만족할 때만 사용할 수 있는 필살기.
// 특정 조건: 현재 캐릭터 점수가 N일 때, 
// 자릿수를 기준으로 N을 반으로 나누어 왼쪽 부분의 각 자릿수 합과 오른쪽 각 자릿수 합이 동일한 상황
// 점수 N이 주어졌을 때 필살기 사용 가능인지 아닌지 알려 주는 프로그램 작성

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int left=0, right = 0;
	int half = s.size() * 0.5f;
	for (int i = 0; i < s.size(); i++) {
		if (i < half)
			left += (s[i] - 48);
		else
			right += (s[i] - 48);
	}

	if (left == right)
		cout << "LUCKY" << "\n";
	else
		cout << "READY" << "\n";
}
