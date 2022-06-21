// 프로그래머스 고득점 Kit - 프린터
// 6/21 - O

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    // vector[location] = priority
    // pq에 우선순위들을 쭉 넣는다.
    int size = priorities.size();
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    int loc = 0;
    for (const int& i : priorities) {
        q.push({ i, loc++ });
        pq.push(i);
    }

    int cnt = 0;
    while (true) {
        int max = pq.top();

        pair<int,int> pi = q.front();
        if (pi.first == max) {
            cnt++;
            pq.pop();
            if (pi.second == location) {
                answer = cnt;
                break;
            }
        }
        else {
            q.push(pi);
        }
        q.pop();
    }

    return answer;
}

int main()
{
    vector<int> v{ 2,1,3,2 };
    solution(v, 2);
}

