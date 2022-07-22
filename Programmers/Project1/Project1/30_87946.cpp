// ���α׷��ӽ� ����� kit - ���� Ž�� - �Ƿε�
// (7/22 - ��) �ð� �ȿ� �� Ǯ�

#include <string>
#include <vector>

using namespace std;

bool visited[9];
int max_cnt;
void dfs(int cur, int pirodo, vector<vector<int>>& ds, int size, int cnt) {
    if (pirodo < ds[cur][0]) { // �Ƿε��� �ּ� �Ƿε����� ����, ���� �Ұ�
        return;
    }

    // ���� ����
    pirodo -= ds[cur][1];
    visited[cur] = true;


    for (int i = 0; i < size; i++) {
        if (visited[i] == true) continue;
        dfs(i, pirodo, ds, size, cnt + 1);
    }

    // �� �� �� �ִ� ���� ����
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