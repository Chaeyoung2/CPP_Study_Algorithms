// [프로그래머스 코테 고득점 Kit] 해시 - 전화번호 목록

// 한 번호가 다른 번호의 접두어인지?
// (5/18) X 아이디어 힌트 받아서 풀었음. 다시 풀 것
// (5/19) X 이진 탐색 전에 정렬하는거 왜 까먹어~??

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> m;

    for (string& s : phone_book) {
        m.insert({ s, 0 });
    }

    for (auto& p : m) {
        int len = p.first.length();
        for (int i = 1; i < len; i++) {
            if (m.find(p.first.substr(0, i)) != m.end()) {
                return false;
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> v;
    v.push_back("123");
    v.push_back("456");
    v.push_back("789");

    for (string& s : v) {
        s.substr(0, 1);
    }
    solution(v);
}