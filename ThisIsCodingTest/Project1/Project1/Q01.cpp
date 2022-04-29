// 모험가 N명
// 공포도 X인 모험가는 X명 이상으로 구성한 모험가 그룹으로 참여해야
// 최대 몇 개의 모험가 그룹을 만들 수 있는가
// 최대라고 했잖아 최대!!! 문제 잘 읽어!
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<int> v(n);
	vector<int> group;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	int result = 0;

	// 1 2 2 2 3
	for (int i = 0; i < n; i++) {
		group.push_back(v[i]);
		if (v[i] == group.size()) {
			result++;
			group.clear();
		}
	}

	cout << result << "\n";
}