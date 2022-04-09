// 8-8. ȿ������ ȭ�� ����
// n���� ȭ�� ������ m���� ���� �� �ּ����� ȭ�� ������ ����Ѵ�.

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;
int main() 
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		arr.push_back(val);
	}

	vector<int> dp(m + 1, 20000);
	dp[0] = 0;

	for (int i = 0; i < n; i++) { // ȭ�� �ϳ��ϳ� ������� m���� ���� dp Ȯ��
		for (int j = arr[i]; j < m + 1; j++) {
			if (dp[j - arr[i]] != 20000) { // (m�� - ȭ��) ���� ���� ���̺� �����Ѵٸ� m�� ���� �� �ִٴ� ��
				dp[j] = __min(dp[j], dp[j - arr[i]] + 1); // dp[ȭ�� ����]�� dp[m�� - ȭ��] + 1 �߿��� ���� �ɷ� 
			}
		}
	}

	if (dp[m] != 20000) {
		cout << dp[m] << '\n';
	}
	else {
		cout << -1 << '\n';
	}
}



