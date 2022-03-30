// 5-11. πÃ∑Œ ≈ª√‚
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[200][200];
bool visited[200][200];

int bfs(int start_x, int start_y) {

	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	visited[start_x][start_y] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		if (!(x  < 0 || x> n || y + 1 < 0 || y + 1 > m)) {
			if (visited[x][y + 1] == false && arr[x][y + 1] > 0) {
				q.push({ x, y + 1 });
				visited[x][y + 1] = true;
				arr[x][y + 1] += arr[x][y];
				continue;
			}
		}

		if (!(x + 1 < 0 || x + 1 > n || y < 0 || y > m)) {
			if (visited[x + 1][y] == false && arr[x + 1][y] > 0) {
				q.push({ x + 1, y });
				visited[x + 1][y] = true;
				arr[x + 1][y] += arr[x][y];
				continue;
			}
		}

		if (!(x - 1 < 0 || x - 1 > n || y < 0 || y > m)) {
			if (visited[x - 1][y] == false && arr[x - 1][y] > 0) {
				q.push({ x - 1, y });
				visited[x - 1][y] = true;
				arr[x - 1][y] += arr[x][y];
				continue;
			}
		}


		if (!(x  < 0 || x  > n || y - 1 < 0 || y - 1 > m)) {
			if (visited[x][y - 1] == false && arr[x][y - 1] == 1) {
				q.push({ x , y - 1 });
				visited[x][y - 1] = true;
				arr[x][y - 1] += arr[x][y];
				continue;
			}
		}
	}
	return arr[n - 1][m - 1];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &arr[i][j]);
		}
	}

	

	cout << bfs(0, 0) << "\n";

}
