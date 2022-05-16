// 9-5. 전보
// (5/11 답 봐도 모르겠는데 뭐지) 
// (5/14 답 보니까 그나마 이해되는데 이거 암기해야 된다..)
// (5/16 접근은 어떻게 하긴 했는데 틀림)

// 도시 C에서 최대한 많은 도시로 메시지를 보낼 때, 
// 받는 도시의 개수는 총 몇 개이며 모두 메시지를 받는 데까지 걸리는 시간은?

// 도시 개수 n, 통로 개수 m, 메시지 보내는 c

// 입력 : 3 2 1 1 2 4 1 3 2  // 출력 : 2 4 

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[30001];
int d[30001];
void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;

	// 첫 노드에 대한 처리
	pq.push({ 0, start }); 
	d[start] = 0;

	while (!pq.empty()) {

		int top = pq.top().second;
		int top_cost = -pq.top().first;
		pq.pop();
		if (top_cost > d[top]) continue; // 이미 처리되었다면
		for (int i = 0; i < graph[top].size(); i++) {
			int next = graph[top][i].first;
			int next_cost = graph[top][i].second;
			if(d[next] > d[top] + next_cost)
				d[next] = d[top] + next_cost;
			pq.push({ -next_cost, next });
		}
	}

}

int main()
{
	for (int i = 0; i < 30001; i++) {
		d[i] = INF;
	}

	int n, m, c;
	cin >> n >> m >> c;
	for (int i = 0; i < m; i++) {
		int val1, val2, cost;
		cin >> val1 >> val2 >> cost;
		graph[val1].push_back({ val2, cost });
	}

	dijkstra(c);

	int max = 0, cnt = 0;
	for (int i = 1; i < n + 1; i++) {
		
		if (d[i] < INF) {
			cnt++;
			if (max < d[i]) {
				max = d[i];
			}
		}
		
	}

	cout << cnt << " " << max << "\n";
	
}



