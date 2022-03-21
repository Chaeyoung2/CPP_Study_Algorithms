// 6-4. �� �迭�� ���� ��ü
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> v_a;
vector<int> v_b;

void change() {
	// ** ���� ���ҳ� ū ���Ҹ� �˾Ƴ� �� sorting!!
	sort(v_a.begin(), v_a.end());
	sort(v_b.begin(), v_b.end(), greater<>());
	for (int i = 0; i < k; i++) {
		if(v_a[i] < v_b[i]) // ** ���� Ʋ���� ����
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
