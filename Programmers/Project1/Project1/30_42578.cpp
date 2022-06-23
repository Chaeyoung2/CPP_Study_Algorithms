// 프로그래머스 고득점 Kit - 위장
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, string> m;
map<string, int> cnt;
int solution(vector<vector<string>> clothes) {
    int answer = 1;

    // 0:name 1:type
    for (auto& i : clothes) {
        m.insert({ i[0], i[1] });
        cnt.insert({ i[1], 1 });
    }

    for (auto& i : m) {
        cnt[i.second]++;
    }


    for (auto& i : cnt) {
        answer *= i.second;
    }

    answer--;
    return answer;
}

int main() {
    vector<vector<string>> c(3);
    //c[0].push_back("yellowhat");
    //c[0].push_back("headgear");
    //c[1].push_back("bluesunglasses");
    //c[1].push_back("eyewear");
    //c[2].push_back("green_turban");
    //c[2].push_back("headgear");

    c[0].push_back("aa");
    c[0].push_back("A");
    c[1].push_back("bb");
    c[1].push_back("B");
    c[2].push_back("cc");
    c[2].push_back("C");

    //c[0].push_back("yellowhat");
    //c[0].push_back("headgear");
    //c[1].push_back("bluehat");
    //c[1].push_back("headgear");
    //c[2].push_back("green_turban");
    //c[2].push_back("headgear");

    solution(c);
}

