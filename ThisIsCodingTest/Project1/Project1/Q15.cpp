// 1~n�������� ����, M���� �ܹ��� ����, ��� ���� �� �Ÿ��� 1
// Ư�� ���� X�κ��� ����ؼ� ������ �� �ִ� ��� ���� �� �ִ� �Ÿ��� ��Ȯ�� K�� ��� ������ ��ȣ ���
// ��� ���� X���� ��� ���� X�� ���� �ִ� �Ÿ��� �׻� 0
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
