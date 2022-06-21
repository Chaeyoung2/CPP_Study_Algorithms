// 프로그래머스 고득점 Kit - 완전 탐색 - 소수 찾기
// 6/20 - △

#include <string>
#include <vector>
#include <set>
#include <algorithm>


// 0, 1, 3
// 01, 03, 10, 13, 30, 31
// 013, 031, 103, 130, 310, 301

using namespace std;

set<int> s;

bool isPrime(int num) {
    int cnt = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            cnt++;
        }
    }
    if (cnt == 1)
        return true;
    else
        return false;
}

void recurs(vector<int>& v, int size, int cnt, string& st) {
    if (cnt >= size) return;
    st.push_back(v[cnt++]);
    s.insert(stoi(st));
    recurs(v, size, cnt, st);
}

int solution(string numbers) {
    int answer = 0;
    int len = numbers.length();
    vector<int> v(len);
    for (int i = 0; i < len; i++) {
        v[i] = numbers[i];
    }

    sort(v.begin(), v.end());

    do {
        string st = "";
        recurs(v, len, 0, st); // 0
    } while (next_permutation(v.begin(), v.end()));
    
    set<int>::iterator i_b = s.begin();
    set<int>::iterator i_e = s.end();

    for (; i_b != i_e; i_b++) {
        if (isPrime((*i_b))) answer++;
    }

    return answer;
}

int main() {
    string s = "17";
    solution(s);
}