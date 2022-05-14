// 9-5. 전보
// (5/11 답 봐도 모르겠는데 뭐지) 
// (5/14 답 보니까 그나마 이해되는데 이거 암기해야 된다..)

// 도시 C에서 최대한 많은 도시로 메시지를 보낼 때, 
// 받는 도시의 개수는 총 몇 개이며 모두 메시지를 받는 데까지 걸리는 시간은?

// 도시 개수 n, 통로 개수 m, 메시지 보내는 c

// 입력 : 3 2 1 1 2 4 1 3 2

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n, m, c;
vector<pair<int, int>> v[30001];
int d[30001];

void dijkstra(int s) {
	priority_queue<pair<int, int>> pq;

	d[s] = 0;
	pq.push({0, s});

	while (!pq.empty()) {
		int top = pq.top().second;
		int top_dist = -pq.top().first;
		pq.pop();
		if (top_dist > d[top]) continue;
		for (int i = 0; i < v[top].size(); i++) {
			int now = v[top][i].first;
			int now_dist = v[top][i].second;
			if (d[now] > top_dist + now_dist)
				d[now] = top_dist + now_dist;
			pq.push({-now_dist, now});
		}
	}
}


int main()
{
	cin >> n >> m >> c;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back({ y, z }); // x에서 y로 가는 비용은 z
	}

	for (int i = 0; i <= 30001; i++) {
		d[i] = 1e9;
	}

	dijkstra(c);

	int cnt = 0 , time = 0;
	for (int i = 1; i < n; i++) {
		if (d[i] != 1e9) {
			cnt++;
			time = max(time, d[i]);
		}
	}

	cout << cnt << " " << time << "\n";
}


