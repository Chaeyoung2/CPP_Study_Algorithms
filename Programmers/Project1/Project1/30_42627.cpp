// 프로그래머스 고득점 kit - 디스크 컨트롤러
// (6/28 - △)
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    int jobs_size = jobs.size();
    multimap<int, int> wait_m; // doing 되기 기다리는 작업들
    for (const auto& v : jobs) {
        wait_m.insert({ v[0], v[1] }); // 0 요청시점, 1 소요시간
    }
    
    int time = 0, doing_time = 0;
    pair<int, int> job_doing = {-1, -1}; // first 요청시점, second 총 소요시간
    int sum = 0; 
    int donejobs_cnt = 0;
    while (true) {
        // 진행 중인 작업이 없다면
        if (job_doing.first < 0) { 
            // 현재 do 할 수 있는 작업들 중에서, 소요 시간이 가장 작은 것 찾기
            pair<int, int> min = { 0, 1e9 }; // 요청시점, second 총 소요시간
            auto u_b = wait_m.upper_bound(time);
            auto l_b = wait_m.begin();
            if (u_b != l_b) { // 작업할 수 있는게 있으면
                for (; l_b != u_b; l_b++) {
                    if (l_b->second <= min.second) {
                        min = *l_b;
                    }
                }
                job_doing = min;
            }
        }
        // 진행 중인 작업이 있다면
        if (job_doing.first >= 0) {
            if (doing_time >= job_doing.second) { // 진행이 다 끝나면
                 // wait_m에서 해당 작업을 찾고 erase
                auto u_b = wait_m.upper_bound(job_doing.first);
                auto l_b = wait_m.lower_bound(job_doing.first);
                for (; l_b != u_b; l_b++) {
                    if (l_b->second == job_doing.second) {
                        wait_m.erase(l_b);
                        break;
                    }
                }
                sum += (time - job_doing.first);
                job_doing = { -1, -1 };
                doing_time = 0;
                donejobs_cnt++;
                if (donejobs_cnt >= jobs_size) {
                    break;
                }
                if (wait_m.empty()) {
                    break;
                }
                continue;
            }
            else { // 진행
                doing_time++;
            }
        }
        time++;
    }

    answer = (sum / donejobs_cnt);

    return answer;
}
int main()
{
    vector<vector<int>> v{ {0,9}, {0,4}, {0,5}, {0,7}, {0,3} };
    solution(v);
}