// Q27. ���ĵ� �迭���� Ư�� �� ���� ���ϱ�.
// n�� ������ ������ ������������ ���ĵǾ� ����
// �̶� �������� x�� �����ϴ� Ƚ��.
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


