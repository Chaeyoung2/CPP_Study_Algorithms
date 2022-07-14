// 프로그래머스 고득점kit 동적계획법 - 등굣길
// (7/11 - X) 틀림
// (7/12 - X)
// (7/14 - O)
#include <string>
#include <vector>

using namespace std;

int dp[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for (int i = 0; i < 101; i++) {
        dp[0][i] = -1;
        dp[i][0] = -1;
    }

    dp[1][1] = 1;

    for (vector<int>& v : puddles) {
        dp[v[1]][v[0]] = -1;
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue; // 시작 좌표
            if (dp[i][j] == -1) continue; // 웅덩이
            if (dp[i][j - 1] == -1 && dp[i - 1][j] == -1) { // 경우4
                dp[i][j] = 0;
            }
            else if (dp[i][j - 1] == -1) { // 경우2
                dp[i][j] = dp[i - 1][j] % 1'000'000'007;
            }
            else if (dp[i - 1][j] == -1) { // 경우3
                dp[i][j] = dp[i][j - 1] % 1'000'000'007;
            } 
            else { // 경우4
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1'000'000'007;
            }
        }
    }
    
    answer = dp[n][m] ;

    return answer;
}
int main() {
    vector<vector<int>> v = { {2,2} };
    solution(4, 3, v);
}