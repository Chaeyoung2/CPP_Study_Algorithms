// 9-4. �̷� ����
// (5/11 �� ���� Ǯ����)
// (5/14 �˰��� ���̵��� ������ �� ���� Ǯ����)
// (5/16 �ֱٿ� ��� Ǯ��� �׷��� �ϱ��. �׳� Ǯ����)

// 1-N
// 1�� ��ġ, X�� �湮�� ���� �Ǹ�
// ����� 2�� ȸ��� ����� �̵� ����
// ���η� 1��ŭ�� �ð����� �̵�

// 1-K-X �� �ִ� �Ÿ��� �̵��� ���� �ּ� �ð���?

// �Է� ���� 1: 5 7 1 2 1 3 1 4 2 4 3 4 3 5 4 5 4 5 // ��� ���� 1: 3
// �Է� : 4 2 1 3 2 4 3 4 // ��� : -1

#include <iostream>
#define INF 1e9
using namespace std;

int graph[101][101];
int n, m;

void floyd() {
	for (int k = 1; k < n + 1; k++) {
		for (int a = 1; a < n + 1; a++) {
			for (int b = 1; b < n + 1; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int val1, val2;
		cin >> val1 >> val2;
		graph[val1][val2] = 1;
		graph[val2][val1] = 1;
	}

	int x, k;
	cin >> x >> k;

	floyd();

	int dist = graph[1][k] + graph[k][x];
	if (dist >= INF)
		cout << -1 << "\n";
	else
		cout << dist << "\n";
}


