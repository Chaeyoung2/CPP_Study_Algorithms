// 6-4. 두 배열의 원소 교체
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> v_a;
vector<int> v_b;

void change() {
	// ** 작은 원소나 큰 원소를 알아낼 때 sorting!!
	sort(v_a.begin(), v_a.end());
	sort(v_b.begin(), v_b.end(), greater<>());
	for (int i = 0; i < k; i++) {
		if(v_a[i] < v_b[i]) // ** 테케 틀렸을 것임
			swap(v_a[i], v_b[i]);
	}
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		v_a.push_back(value);
	}
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		v_b.push_back(value);
	}

	change();

	int result = 0;
	for (int i = 0; i < n; i++) {
		result += v_a[i];
	}
	cout << result << "\n";
}
