// 7-5. ��ǰ ã��
// ��ǰ n��, �մ��� ���ϴ� ��ǰ ���� m��
// ��ǰ�� ��� �ִ��� Ȯ���ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
	// �Է�
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


