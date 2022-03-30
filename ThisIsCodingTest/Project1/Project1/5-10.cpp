// 5-10. 음료수 얼려 먹기

#include <iostream>
using namespace std;

int n, m;
int arr[1000][1000];
bool visited[1000][1000];
int cnt;

void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n)
		return;
	if (visited[x][y] == true || arr[x][y] == 1)
		return;
	visited[x][y] = true;

	dfs(x + 1, y);
	dfs(x, y + 1);
	dfs(x - 1, y);
	dfs(x, y - 1);
	
	return;
}

int main() 
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == false && arr[i][j] == 0) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << "\n";
}

