// 7-5. 부품 찾기
// 부품 n개, 손님이 원하는 부품 종류 m개
// 부품이 모두 있는지 확인하는 프로그램

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
	// 입력
	cin >> n;
	vector<int> ns(n);
	for (int i = 0; i < n; i++) {
		cin >> ns[i];
	}
	cin >> m;
	vector<int> ms(m);
	for (int i = 0; i < m; i++) {
		cin >> ms[i];
	}

	sort(ns.begin(), ns.end());
	sort(ms.begin(), ms.end());

	for (int& m : ms) {
		if (binary_search(ns.begin(), ns.end(), m)) {
			cout << "yes";
		}
		else {
			cout << "no";
		}
		cout << " ";
	}
}


