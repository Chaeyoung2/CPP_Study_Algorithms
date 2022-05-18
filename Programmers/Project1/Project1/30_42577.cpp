// 한 번호가 다른 번호의 접두어인지?
// (5/18) X 아이디어 힌트 받아서 풀었음. 다시 풀 것

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    // 119-976, 119-119, 
    // 123-456, 123-789
    // 12-12, 12-12, 12-56, 12-88

    map<string, int> m;
    for (string& s : phone_book) {
        m.insert({ s, 0 });
    }

    for (auto& i : m) {
        string target = i.first;
        int target_len = target.length();
        for (int i = 1; i < target_len; i++) {
            string finding = target.substr(0, i);
            if (m.end() != m.find(finding)) 
                return false;
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
    solution(v);
}