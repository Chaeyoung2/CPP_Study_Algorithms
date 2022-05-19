// 각 배포마다 몇 개의 기능이 배포되는가
// 배포는 하루에 한 번만, 하루의 끝에 이루어짐
// 예를 들어 진도율 95%이고 속도가 하루에 4인 작업은 배포가 2일 뒤에 이루어짐

// 

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int sz = progresses.size();
    queue<pair<int, int>> q;
    for (int i = 0; i < sz; i++) {
        q.push({ progresses[i], speeds[i] });
    }

    int day_cnt = 0;
    int out = 0;
    while (!q.empty()) {
		day_cnt++;
		int jindo = q.front().first + (q.front().second * day_cnt);
		if (jindo >= 100) {
			q.pop();
            out++;
			while (!q.empty()) {
				jindo = q.front().first + (q.front().second * day_cnt);
				if (jindo >= 100) {
					q.pop();
					out++;
				}
				else {
					break;
				}
			}
            answer.push_back(out);
            out = 0;
		}

	}


    return answer;
}

int main()
{
    vector<int> p = { 95, 90, 99, 99, 80, 99 };
    vector<int> s = { 1, 1, 1, 1, 1, 1};
    solution(p, s);
}

