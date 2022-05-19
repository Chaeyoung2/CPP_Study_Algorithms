// [프로그래머스 코테 고득점 Kit] 힙 - 더 맵게

// 섞은 음식의 스코빌 = 가장 맵지 않은 음식의 스코빌 + (두번째로 맵지 않은 음식의 스코빌 * 2)
// 모든 음식의 스코빌을 k 이상으로 만들기 위해 섞어야 하는 최소 횟수


#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (const int& i : scoville) {
        pq.push(i);
    }

    int mix_cnt = 0;

    while (true) {
        int des = pq.top();
        pq.pop();
        int src = pq.top();
        pq.pop();
        int mix_result = des + (src * 2);
        pq.push(mix_result);
        mix_cnt++;

        if (pq.top() >= K) {
            answer = mix_cnt;
            break;
        }
        if (pq.size() == 1 && pq.top() < K) {
            answer = -1;
            break;
        }
    }


    

    return answer;
}

int main() {
    vector<int> v = { 1,2,3,9,10,12 };
    solution(v, 7);
}

