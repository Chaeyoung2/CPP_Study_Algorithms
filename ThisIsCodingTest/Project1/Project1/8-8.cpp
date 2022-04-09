// 8-8. 효율적인 화폐 구성
// n개의 화폐 종류로 m원을 만들 때 최소한의 화폐 개수를 출력한다.

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

	for (int i = 0; i < n; i++) { // 화폐 하나하나 순서대로 m원에 빼서 dp 확인
		for (int j = arr[i]; j < m + 1; j++) {
			if (dp[j - arr[i]] != 20000) { // (m원 - 화폐) 값이 디피 테이블에 존재한다면 m을 만들 수 있다는 뜻
				dp[j] = __min(dp[j], dp[j - arr[i]] + 1); // dp[화폐 종류]와 dp[m원 - 화폐] + 1 중에서 작은 걸로 
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



