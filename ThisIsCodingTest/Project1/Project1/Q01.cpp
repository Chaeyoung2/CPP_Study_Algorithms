// ���谡 N��
// ������ X�� ���谡�� X�� �̻����� ������ ���谡 �׷����� �����ؾ�
// �ִ� �� ���� ���谡 �׷��� ���� �� �ִ°�
// �ִ��� ���ݾ� �ִ�!!! ���� �� �о�!
 
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