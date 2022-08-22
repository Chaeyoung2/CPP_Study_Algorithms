// [���α׷��ӽ� ���� ����� Kit] DFS/BFS - ���� �� �ִܰŸ�
#include<vector>
#include<queue>
using namespace std;


int cnt[101][101];
bool visited[101][101];
int solution(vector<vector<int> > maps)
{
    int m = maps.size();// ���� ����
    int n = maps[0].size(); // ���� ����
    int answer = -1;

    queue<pair<int, int>> q;

    q.push({ 0,0 }); // x,y 

    cnt[0][0] = 1;
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        // x,y�� (n-1, m-1)�̶�� Ż��
        if (x == n-1 && y == m - 1) {
            break;
        }

        
        // �����¿찡 �� ���� ���� �ʰ� 1�̶�� push
        if (y - 1 > 0 && maps[y - 1][x] == 1 && visited[y - 1][x] == false) {
            q.push({ x, y - 1 });
            cnt[y - 1][x] = cnt[y][x] + 1;
            visited[y - 1][x] = true;
        }
        if (y + 1 < m && maps[y + 1][x] == 1 && visited[y + 1][x] == false) {
            q.push({ x, y + 1});
            cnt[y + 1][x] = cnt[y][x] + 1;
            visited[y + 1][x] = true;
        }
        if (x - 1 > 0 && maps[y][x - 1] == 1 && visited[y][x-1] == false) {
            q.push({ x - 1, y });
            cnt[y][x - 1] = cnt[y][x] + 1;
            visited[y][x - 1] = true;
        }
        if (x + 1 < n && maps[y][x + 1] == 1 && visited[y][x+1] == false) {
            q.push({ x + 1, y });
            cnt[y][x + 1] = cnt[y][x] + 1;
            visited[y][x+1] = true;
        }
        

    }
    if (cnt[m - 1][n - 1] == 0)
        return -1;
    return cnt[m - 1][n - 1];
}
int main() {
    // solution({ {1, 0, 1, 1, 1}, { 1, 0, 1, 0, 1 }, { 1, 0, 1, 1, 1 }, { 1, 1, 1, 0, 1 }, { 0, 0, 0, 0, 1 }});
    // solution({ {1, 0, 1, 1, 1} ,{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 0},{0, 0, 0, 0, 1} });

    solution({ {1,1,1,1, 1 } });

    // 1000
    // 1111
    // 1101
    // 0001
    // 0001 // n=4, m=5������ �� �������� ��ġ�� 4(m-1)�� 3(n-1)���� [m-1][n-1]�� ��ġ

}

