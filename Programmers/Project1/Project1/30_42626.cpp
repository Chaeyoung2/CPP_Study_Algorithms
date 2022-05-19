// [���α׷��ӽ� ���� ����� Kit] �� - �� �ʰ�

// ���� ������ ���ں� = ���� ���� ���� ������ ���ں� + (�ι�°�� ���� ���� ������ ���ں� * 2)
// ��� ������ ���ں��� k �̻����� ����� ���� ����� �ϴ� �ּ� Ƚ��


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

