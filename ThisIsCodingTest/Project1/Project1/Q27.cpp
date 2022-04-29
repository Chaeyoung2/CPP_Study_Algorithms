// Q27. 정렬된 배열에서 특정 수 개수 구하기.
// n개 원소의 수열이 오름차순으로 정렬되어 있음
// 이때 수열에서 x가 등장하는 횟수.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int>::iterator u_index = upper_bound(v.begin(), v.end(), x);
	vector<int>::iterator l_index = lower_bound(v.begin(), v.end(), x);

	if (u_index == l_index) {
		cout << -1 << "\n";
	}
	else
		cout << u_index - l_index << "\n";
}


