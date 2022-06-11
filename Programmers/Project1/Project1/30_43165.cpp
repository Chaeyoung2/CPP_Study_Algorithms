// [프로그래머스 코테 고득점 Kit] BFS/DFS - 타겟 넘버
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
        // 매개 변수로 들어가는 cnt를 cnt++로 넣어 줬는데, 이렇게 하면 안 된다.
		// 이 줄에서의 cnt는 solution 지역에서의 cnt이기 때문에, 
		// cnt++는 solution 지역에서의 cnt가 증가될 뿐, 매개변수로 들어가는 cnt에는 아무런 영향을 주지 않는다. 
	dfs(numbers, -numbers[0], target, cnt + 1);
	dfs(numbers, +numbers[0], target, cnt + 1);
	answer = result;
    return answer;
}

int main() {
    vector<int> v = { 1,1,1,1,1 };
    solution(v, 3);
}