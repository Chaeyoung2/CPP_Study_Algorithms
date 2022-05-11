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




