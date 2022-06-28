// ���α׷��ӽ� ����� kit - ��ũ ��Ʈ�ѷ�
// (6/28 - ��)
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    int jobs_size = jobs.size();
    multimap<int, int> wait_m; // doing �Ǳ� ��ٸ��� �۾���
    for (const auto& v : jobs) {
        wait_m.insert({ v[0], v[1] }); // 0 ��û����, 1 �ҿ�ð�
    }
    
    int time = 0, doing_time = 0;
    pair<int, int> job_doing = {-1, -1}; // first ��û����, second �� �ҿ�ð�
    int sum = 0; 
    int donejobs_cnt = 0;
    while (true) {
        // ���� ���� �۾��� ���ٸ�
        if (job_doing.first < 0) { 
            // ���� do �� �� �ִ� �۾��� �߿���, �ҿ� �ð��� ���� ���� �� ã��
            pair<int, int> min = { 0, 1e9 }; // ��û����, second �� �ҿ�ð�
            auto u_b = wait_m.upper_bound(time);
            auto l_b = wait_m.begin();
            if (u_b != l_b) { // �۾��� �� �ִ°� ������
                for (; l_b != u_b; l_b++) {
                    if (l_b->second <= min.second) {
                        min = *l_b;
                    }
                }
                job_doing = min;
            }
        }
        // ���� ���� �۾��� �ִٸ�
        if (job_doing.first >= 0) {
            if (doing_time >= job_doing.second) { // ������ �� ������
                 // wait_m���� �ش� �۾��� ã�� erase
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
            else { // ����
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