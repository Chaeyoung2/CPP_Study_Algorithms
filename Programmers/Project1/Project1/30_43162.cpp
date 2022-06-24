// 프로그래머스 고득점 kit - 네트워크
// 6/24 - O

#include <string>
#include <vector>

using namespace std;
bool visited[201];
int answer = 0;
void dfs(vector<vector<int>>& v, int size, int start, int& cnt){
    if (start >= size) return;
    if (visited[start] == true) return;
    visited[start] = true;
    for (int i = 0; i < size; i++) {
        if (v[start][i] == 1) {
            dfs(v, size, i, cnt);
        }
    }
    cnt++;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        dfs(computers, n, i, cnt);
        if (cnt > 0) {
            answer++;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> v;

    //v.push_back({ 1,0, 0, 1 });
    //v.push_back({ 0, 1, 1, 0 });
    //v.push_back({ 0, 1, 1, 0 });
    //v.push_back({ 1,1, 0, 1 });

    //v.push_back({ 1,0, 0 });
    //v.push_back({ 0, 1, 0 });
    //v.push_back({ 0, 0, 1 });

    v.push_back({ 1, 1, 0 });
    v.push_back({ 1, 1, 0 });
    v.push_back({ 0, 0, 1 });


    //v.push_back({ 1, 1, 0 });
    //v.push_back({ 1, 1, 1 });
    //v.push_back({ 0, 1, 1 });

    //v.push_back({ 1, 0, 1, 1, 0, 0 });
    //v.push_back({ 0, 1, 0, 0, 1, 1 });
    //v.push_back({ 1, 0, 1, 1, 1, 1 });
    //v.push_back({ 1, 0, 1, 1, 1, 1 });
    //v.push_back({ 0, 1, 1, 1, 1, 1 });
    //v.push_back({ 0, 1, 1, 1, 1, 1 });

    solution(3, v);
}

