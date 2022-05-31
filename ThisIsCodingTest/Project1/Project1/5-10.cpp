// 5-10. 음료수 얼려 먹기
// 4 5 00110 00011 11111 00000
// 15 14 00000111100000 11111101111110 11011101101110 11011101100000 11011111111111 11011111111100 11000000011111 01111111111111 00000000011111 01111111111000 00011111111000 00000001111000 11111111110011 11100011111111 11100011111111
// 3/30 - O
// 4/20 - △ (36번줄~)
// 5/31 - O

#include <iostream>
#include <string>
using namespace std;

int arr[1001][1001];
bool visited[1001][1001];
int n, m;

bool dfs(int row, int col){
	if (row < 0 || row >= n || col < 0 || col >= m) return false;
	if (arr[row][col] == 1) return false;
	if (visited[row][col] == true) return false;
	visited[row][col] = true;

	dfs(row - 1, col);
	dfs(row + 1, col);
	dfs(row, col - 1);
	dfs(row, col + 1);

	return true;
}

int main() {
	cin >> n >> m;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int size = s.size();
		for (int j = 0; j < size; j++) {
			arr[i][j] = (s[j] - '0');
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (true == dfs(i, j)) {
				cnt++;
			}
		}
	}

	cout << cnt << "\n";
}
