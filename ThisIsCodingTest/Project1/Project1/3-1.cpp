// 3.1 �Ž�����
#include <iostream>
using namespace std;
// �մԿ��� �Ž��� �� ���� N��
// �Ž��� �־�� �� ������ �ּ� ���� X
// N���� �׻� 10�� ���

int n, x;
int arr[4] = { 500, 100, 50, 10 };
int main()
{
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		cnt += n / arr[i];
		n %= arr[i];
	}
	cout << cnt << "\n";
}


