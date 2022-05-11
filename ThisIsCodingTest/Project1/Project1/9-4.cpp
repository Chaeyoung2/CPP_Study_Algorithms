// 9-4. �̷� ����
// (5/11 �� ���� Ǯ����)
// 
// 1-N
// 1�� ��ġ, X�� �湮�� ���� �Ǹ�
// ����� 2�� ȸ��� ����� �̵� ����
// ���η� 1��ŭ�� �ð����� �̵�

// 1-K-X �� �ִ� �Ÿ��� �̵��� ���� �ּ� �ð���?

// �Է� ���� 1: 5 7 1 2 1 3 1 4 2 4 3 4 3 5 4 5 4 5 // ��� ���� 1: 3

#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9

int n, m, x, k;
int d[101][101];
int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		fill(d[i], d[i] + 101, INF);
	}

	for (int i = 0; i < m; i++) {
		int val1, val2;
		cin >> val1 >> val2;
		d[val1][val2] = 1;
		d[val2][val1] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) d[i][j] = 0;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	cin >> x >> k;
	if (d[1][k] + d[k][x] == INF)
		cout << "-1\n";
	else 
		cout << d[1][k] + d[k][x];
}




