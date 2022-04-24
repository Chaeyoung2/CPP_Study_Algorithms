#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
vector<vector<int>> vec;
bool visited_d[1001];
bool visited_b[1001];

void dfs(int start) {
	if (visited_d[start] == true) return;
	visited_d[start] = true;
	cout << start << " ";
	for (int i = 0; i < vec[start].size(); i++) {
		dfs(vec[start][i]);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited_b[start] = true;

	while (!q.empty()) {
		int f = q.front();
		cout << f << " ";
		q.pop();
		for (int i = 0; i < vec[f].size(); i++) {
			if (visited_b[vec[f][i]] == false) {
				q.push(vec[f][i]);
				visited_b[vec[f][i]] = true;
			}
		}
	}

}

int main()
{

	cin >> n >> m >> v;

	vec.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int val1;
		int val2;
		cin >> val1 >> val2;
		vec[val1].push_back(val2);
		vec[val2].push_back(val1);
	}

	for (int i = 1; i < n + 1; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	dfs(v);
	cout << "\n";
	bfs(v);

}
