// 프로그래머스 고득점 kit - 입국 심사
#include <string>
#include <vector>

using namespace std;

long long binary_search(vector<int>& times, int n, long long start, long long end) {
    long long answer = 0;
    long long mid = -1;
    while (start != end -1) {
        mid = (end + start)/2;
        long long imm_sum = 0; // mid 시간 동안 times의 심사원들이 각각 몇 명이나 검사할 수 있는지
        for (auto& i : times) {
            imm_sum += (mid / i);
        }
        if (imm_sum >= n) {
            end = mid;
            answer = mid;
        }
        else {
            start = mid;
        }
    }
    return answer;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;

    answer = binary_search(times, n, times[0], times[times.size() - 1] * n);

    return answer;
}

int main() {
    vector<int> v{ 6, 8, 10 };
    solution(10, v);
}
