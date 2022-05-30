// BOJ 14889: 스타트와 링크
// n명 중 n/2명씩 각각 스타트팀, 링크팀으로 나눈다.
// Sij는 i번 사람과 j번 사람이 같은 팀일 때 능력치
// i번, j번이 같은 팀에 속하면 팀에 더해지는 능력치는 Sij와 Sji

// 5/30 - X  // 걍 틀렸고 이건 답 보고 한 코드

#include <iostream>
#include <vector>
using namespace std;

int n;
int stats[21][21];
bool visited[21];
int result = 1e9;

// idx번 선수를 start 팀으로 뽑고, cnt는 뽑은 명수
void dfs(int idx, int cnt) {

	if (cnt == n / 2) {
		vector<int> link, start;
		for (int i = 0; i < n; i++) {
			if (visited[i] == true) // 뽑은 선수들은 스타트팀으로
				start.push_back(i);
			else
				link.push_back(i);
		}

		// 팀 간의 능력치 차
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
			dfs(i, cnt + 1); // 백트래킹
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

