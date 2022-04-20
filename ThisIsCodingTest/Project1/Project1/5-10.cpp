// 5-10. 음료수 얼려 먹기
// 3/30 - O
// 4/20 - △ (36번줄~)
#include <iostream>
using namespace std;
int n, m;
int arr[1001][1001];
int result = 0;

bool dfs(int h, int w) {
	if (arr[h][w] == 1) return false;
	arr[h][w] = 1;

	if (h - 1 >= 0)
		dfs(h - 1, w);

	if(w + 1 < m) 
		dfs(h, w + 1);

	if(h + 1 < n)
		dfs(h + 1, w);

	if(w - 1 >= 0) 
		dfs(h, w - 1);

	return true;

}

int main()
{
	// setting
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &arr[i][j]);
		}
	}

	// solution
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(dfs(i, j))
				result++;
		}
	}

	cout << result << "\n";
}

