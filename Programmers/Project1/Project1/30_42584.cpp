// 프로그래머스 코테 고득점 Kit - 스택/큐 - 주식 가격
// (7/18) X 걍 다시 풀어..

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {

    stack<int> s;
    int size = prices.size();
    vector<int> answer(size, 0);

    for (int i = 0; i < size; i++) {
        while (!s.empty()) {
            if (prices[i] < prices[s.top()]) {
                answer[s.top()] = i - s.top();
                s.pop();
            }
            else {
                break;
            }
        }
        s.push(i);
    }

    while (!s.empty()) {
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }

    return answer;
}

int main() {
    solution({ 1,2,3,2,1 });
}