// 프로그래머스 고득점 kit - 완전 탐색 - 피로도
// (7/22 - △) 시간 안에 못 풀어서

#include <string>
#include <vector>

using namespace std;

bool visited[9];
int max_cnt;
void dfs(int cur, int pirodo, vector<vector<int>>& ds, int size, int cnt) {
    if (pirodo < ds[cur][0]) { // 피로도가 최소 피로도보다 낮음, 진입 불가
        return;
    }

    // 던전 입장
    pirodo -= ds[cur][1];
    visited[cur] = true;


    for (int i = 0; i < size; i++) {
        if (visited[i] == true) continue;
        dfs(i, pirodo, ds, size, cnt + 1);
    }

    // 더 돌 수 있는 던전 없음
    max_cnt = max(max_cnt, cnt);

    visited[cur] = false;
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    int pirodo = k;
    int size = dungeons.size();
    
    for (int i = 0; i < size; i++) {
        dfs(i, pirodo, dungeons, size, 1);
    }
    answer = max_cnt;
    return answer;
}

int main() {
    solution( 80, { {80, 20}, { 50, 40}, { 30, 10} });
}