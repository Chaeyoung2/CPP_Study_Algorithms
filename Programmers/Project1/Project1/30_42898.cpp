// 프로그래머스 고득점kit 동적계획법 - 등굣길
// (7/11 - ?) 채점이 안됨
#include <string>
#include <vector>

using namespace std;


int dp[101][101];

void go(int x, int y, vector<vector<int>>& p) {
    if (x == 1 && y == 1) return;
    for (const vector<int>& v : p) {
        if (v[0] == x && v[1] == y) return;
    }
    dp[x][y] = min(dp[x][y], dp[x-1][y] + 1);
    dp[x][y] = min(dp[x][y], dp[x][y-1] + 1);
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            dp[i][j] = 1e9;
        }
    }
    dp[1][1] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            go(i, j, puddles);
        }
    }

    answer = dp[m][n] - 1;

    return answer;
}

int main() {
    vector<vector<int>> v = { {2,2} };
    solution(4, 3, v);
}