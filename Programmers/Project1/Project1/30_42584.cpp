// ���α׷��ӽ� ���� ����� Kit - ����/ť - �ֽ� ����
// (7/18) X �� �ٽ� Ǯ��..

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