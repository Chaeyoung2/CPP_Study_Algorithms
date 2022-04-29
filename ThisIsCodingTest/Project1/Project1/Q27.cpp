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

	int b, e, mid;
	b = 0;
	mid = n / 2;
	e = n - 1;
	int result = -1;
 	while (e != b + 1) {
		if (v[mid] == x) {
			int b_temp = mid;
			int e_temp = mid;
			while (v[b_temp] == x) {
				b_temp--;
			}
			while (v[e_temp] == x) {
				e_temp++;
			}
			result = e_temp - b_temp - 1;
			break;
  		}
		else if (binary_search(&v[b], &v[mid], x)) {
			e = mid;
		}
		else {
			b = mid;
		}
		mid = (b + e) / 2;
	}
	cout << result << "\n";
}


