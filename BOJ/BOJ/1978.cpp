// BOJ 1978: �Ҽ� ã��
// �־��� N���� �� �߿��� �Ҽ��� ������ ���
#include <iostream>
#include <vector>
using namespace std;

bool isDec(int num) {
	bool result = true;
	if (num == 1) return false;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) return false;
	}
	return result;
}

int main()
{
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int cnt = 0;
	for (const int& i : v) {
		if (isDec(i)) {
			cnt++;
		}
	}
	cout << cnt << "\n";
}

