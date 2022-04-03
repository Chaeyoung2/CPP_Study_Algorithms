// 8-6. ���� ����
// �ٽ� Ǯ�� (4/3 �ٽ� Ǯ������ Ʋ��, ** Ȯ��)

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int dp[100];
int n;
vector<int> arr;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	// dynamic programming (bottom up)
	dp[0] = arr[0];
	// dp[1] = arr[1]; // ** Ʋ�Ⱦ�!!!!!!!!!!!!!
	dp[1] = max(arr[0], arr[1]);

	for (int i = 2; i < n; i++) {
		if (dp[i - 1] < dp[i - 2] + arr[i]) {
			dp[i] = dp[i - 2] + arr[i];
		}
		else {
			dp[i] = dp[i - 1];
		}
	}
	
	cout << dp[n - 1] << "\n";
}

