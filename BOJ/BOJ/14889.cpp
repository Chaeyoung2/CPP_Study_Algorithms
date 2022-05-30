// BOJ 14889: ��ŸƮ�� ��ũ
// n�� �� n/2�� ���� ��ŸƮ��, ��ũ������ ������.
// Sij�� i�� ����� j�� ����� ���� ���� �� �ɷ�ġ
// i��, j���� ���� ���� ���ϸ� ���� �������� �ɷ�ġ�� Sij�� Sji

// 5/30 - X  // �� Ʋ�Ȱ� �̰� �� ���� �� �ڵ�

#include <iostream>
#include <vector>
using namespace std;

int n;
int stats[21][21];
bool visited[21];
int result = 1e9;

// idx�� ������ start ������ �̰�, cnt�� ���� ���
void dfs(int idx, int cnt) {

	if (cnt == n / 2) {
		vector<int> link, start;
		for (int i = 0; i < n; i++) {
			if (visited[i] == true) // ���� �������� ��ŸƮ������
				start.push_back(i);
			else
				link.push_back(i);
		}

		// �� ���� �ɷ�ġ ��
		int s_sum = 0, l_sum = 0;
		for (int i = 0; i < start.size(); i++) {
			for (int j = i + 1; j < start.size(); j++) {
				s_sum += stats[start[i]][start[j]] + stats[start[j]][start[i]];
				l_sum += stats[link[i]][link[j]] + stats[link[j]][link[i]];
			}
		}

		result = min(result, abs(s_sum - l_sum));
		return;
	}

	for (int i = idx + 1; i < n; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			dfs(i, cnt + 1); // ��Ʈ��ŷ
			visited[i] = false;
		}
	}

}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> stats[i][j];
		}
	}
	dfs(0, 0);

	cout << result << "\n";
}

