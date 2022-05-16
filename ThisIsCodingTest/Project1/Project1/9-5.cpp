// 9-5. ����
// (5/11 �� ���� �𸣰ڴµ� ����) 
// (5/14 �� ���ϱ� �׳��� ���صǴµ� �̰� �ϱ��ؾ� �ȴ�..)
// (5/16 ������ ��� �ϱ� �ߴµ� Ʋ��)

// ���� C���� �ִ��� ���� ���÷� �޽����� ���� ��, 
// �޴� ������ ������ �� �� ���̸� ��� �޽����� �޴� ������ �ɸ��� �ð���?

// ���� ���� n, ��� ���� m, �޽��� ������ c

// �Է� : 3 2 1 1 2 4 1 3 2  // ��� : 2 4 

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

	// ù ��忡 ���� ó��
	pq.push({ 0, start }); 
	d[start] = 0;

	while (!pq.empty()) {

		int top = pq.top().second;
		int top_cost = -pq.top().first;
		pq.pop();
		if (top_cost > d[top]) continue; // �̹� ó���Ǿ��ٸ�
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



