// [���α׷��ӽ� ���� ����� Kit] BFS/DFS - Ÿ�� �ѹ�
#include <string>
#include <vector>

using namespace std;
int result = 0;
void dfs(vector<int>& v, int sum, int target, int cnt) {
    if (cnt == v.size()) {
        if (sum == target) {
            result++;
        }
        return;
    }
    dfs(v, sum - v[cnt], target, cnt + 1);
    dfs(v, sum + v[cnt], target, cnt + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int cnt = 0;
        // �Ű� ������ ���� cnt�� cnt++�� �־� ��µ�, �̷��� �ϸ� �� �ȴ�.
		// �� �ٿ����� cnt�� solution ���������� cnt�̱� ������, 
		// cnt++�� solution ���������� cnt�� ������ ��, �Ű������� ���� cnt���� �ƹ��� ������ ���� �ʴ´�. 
	dfs(numbers, -numbers[0], target, cnt + 1);
	dfs(numbers, +numbers[0], target, cnt + 1);
	answer = result;
    return answer;
}

int main() {
    vector<int> v = { 1,1,1,1,1 };
    solution(v, 3);
}