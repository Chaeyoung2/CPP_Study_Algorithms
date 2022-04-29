// 1~n번까지의 도시, M개의 단방향 도로, 모든 도로 간 거리는 1
// 특정 도시 X로부터 출발해서 도달할 수 있는 모든 도시 중 최단 거리가 정확히 K인 모든 도시의 번호 출력
// 출발 도시 X에서 출발 도시 X로 가는 최단 거리는 항상 0
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, x;
vector<vector<int>> v(300'001);
vector<int> result(300'001, 0);
bool visited[300'001]{false};

void bfs(int start) {

	queue<int> q;
	q.push(start);

	visited[start] = true;
	result[start] = 0;
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (int i = 0; i < v[f].size(); i++) {
			if (visited[v[f][i]] == false) {
				q.push(v[f][i]);
				visited[v[f][i]] = true;
				result[v[f][i]] = result[f] + 1;
			}
		}
	}


}

int main()
{
	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; i++) {
		int val1, val2;
		cin >> val1;
		cin >> val2;
		v[val1].push_back(val2);
		v[val2].push_back(val1);
	}
	bfs(x);


	for (int i = 0; i < n + 1; i++) {
		if (result[i] == k)
			cout << i << "\n";
	}
}
