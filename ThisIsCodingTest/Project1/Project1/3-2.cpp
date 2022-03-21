// 3-2. 큰 수의 법칙
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
// 배열의 크기 n, 숫자가 더해지는 횟수 m, 연속해서 더해질 수 없는 횟수 k
int arr[1000] = {};
int main()
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 2 4 5 4 6 // 6 6 6 5, 6 6 6 5 // n = 5, m = 8, k = 3
	// 3 4 3 4 3 // 4 4 4, 4 4 4, 4 // n = 5, m = 7, k = 2

	sort(arr, &arr[n]);
	int max_first = arr[n - 1];
	int max_second = arr[n - 2];

	int max_first_cnt = int(m / (k + 1)) * k + (m % (k + 1));
	int max_second_cnt = m - max_first_cnt; // 이걸 생각 못 해서 답지를 봤네..
	
	int result = 0;
	for (int i = 0; i < max_first_cnt; i++) {
		result += max_first;
	}
	for (int i = 0; i < max_second_cnt; i++) {
		result += max_second;
	}

	cout << result << "\n";
}
