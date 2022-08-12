// [���α׷��ӽ� ���� ����� Kit] ����/ť - �ùٸ� ��ȣ

#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    for (const auto& c : s) {
        st.push(c);
    }

    stack<char> st2;
    while(!st.empty()){
        if (st2.empty()) {
            st2.push(st.top());
        }
        else if (st.top() == '(' && st2.top() == ')') {
            st2.pop();
        }
        else {
            st2.push(st.top());
        }
        st.pop();
    }

    answer = st2.empty();
    return answer;
}

int main() {
    solution("()()");
}