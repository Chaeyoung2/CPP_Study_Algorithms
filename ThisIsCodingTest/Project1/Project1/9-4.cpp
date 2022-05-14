// 9-4. 미래 도시
// (5/11 답 보고 풀었음)
// 
// 1-N
// 1에 위치, X에 방문해 물건 판매
// 연결된 2개 회사는 양방향 이동 가능
// 도로로 1만큼의 시간으로 이동

// 1-K-X 을 최단 거리로 이동할 때의 최소 시간은?

// 입력 예시 1: 5 7 1 2 1 3 1 4 2 4 3 4 3 5 4 5 4 5 // 출력 예시 1: 3
#include <iostream>
using namespace std;
#define INF 1e9

int n, m, x, k;
int d[101][101];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			d[i][j] = INF;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) d[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int val1, val2;
		cin >> val1 >> val2;
		d[val1][val2] = 1;
		d[val2][val1] = 1;
	}

	cin >> x >> k;

	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				d[a][b] = min(d[a][b], d[a][k] + d[k][b]);
			}
		}
	}

	int dist = d[1][k] + d[k][x];
	if (dist >= 1e9) {
		cout << -1 << "\n";
	}
	else
		cout << dist << "\n";
}


