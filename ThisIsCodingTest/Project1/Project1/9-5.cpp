// 9-5. ����
// (5/11 �� ���� �𸣰ڴµ� ����) 
// (5/14 �� ���ϱ� �׳��� ���صǴµ� �̰� �ϱ��ؾ� �ȴ�..)

// ���� C���� �ִ��� ���� ���÷� �޽����� ���� ��, 
// �޴� ������ ������ �� �� ���̸� ��� �޽����� �޴� ������ �ɸ��� �ð���?

// ���� ���� n, ��� ���� m, �޽��� ������ c

// �Է� : 3 2 1 1 2 4 1 3 2

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
		v[x].push_back({ y, z }); // x���� y�� ���� ����� z
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


