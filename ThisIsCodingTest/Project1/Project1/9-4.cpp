// 9-4. 미래 도시
// (5/11 답 보고 풀었음)
// (5/14 알고리즘 아이디어에서 막혀서 답 보고 풀었음)
// (5/16 최근에 계속 풀었어서 그런가 암기됨. 그냥 풀었음)

// 1-N
// 1에 위치, X에 방문해 물건 판매
// 연결된 2개 회사는 양방향 이동 가능
// 도로로 1만큼의 시간으로 이동

// 1-K-X 을 최단 거리로 이동할 때의 최소 시간은?

// 입력 예시 1: 5 7 1 2 1 3 1 4 2 4 3 4 3 5 4 5 4 5 // 출력 예시 1: 3
// 입력 : 4 2 1 3 2 4 3 4 // 출력 : -1

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


