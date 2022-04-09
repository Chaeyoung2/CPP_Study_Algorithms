// 6-12. 두 배열의 원소 교체

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> va;
vector<int> vb;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n * 2; i++) {
		int val;
		cin >> val;
		if (i < n) {
			va.push_back(val);
		}
		else {
			vb.push_back(val);
		}
	}
	

	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	for (int i = 0; i < k; i++) {
		int temp = va[i];
		va[i] = vb[n - i - 1];
		vb[n - i - 1] = temp;
	}

	int result = 0;
	for (int& i : va) {
		result += i;
	}

	cout << result << "\n";
}
