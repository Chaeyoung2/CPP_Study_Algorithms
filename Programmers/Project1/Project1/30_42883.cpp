// 프로그래머스 - 큰 수 만들기
// 6/24 - X

#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int len = number.length();
    int answer_size = len - k;

    stack<int> s;
    for (auto& c : number) {
        while (!s.empty() && k > 0 && c - '0' > s.top()) {
            s.pop();
            k--;
        }
        s.push(c - '0');
    }
    if (s.size() > answer_size) {
        int top = s.top();
        s.pop();
        if (s.top() < top) {
            s.pop();
            s.push(top);
        }
    }

    answer.resize(answer_size);
    for (int i = answer_size - 1; i >= 0; i--) {
        answer[i] = (s.top() + '0');
        s.pop();
    }

    return answer;

}

int main() {
    string s = "654321";
    solution(s, 1);
}