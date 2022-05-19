// 한 번호가 다른 번호의 접두어인지?
// (5/18) X 아이디어 힌트 받아서 풀었음. 다시 풀 것
// (5/19) X 이진 탐색 전에 정렬하는거 왜 까먹어~??

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (string& s : phone_book) {
        int st_len = s.length();
        string des = s;
        for (int i = 1; i < st_len; i++) {
            // des의 접두어 찾기
            if (binary_search(phone_book.begin(), phone_book.end(), des.substr(0, i))) {
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
    solution(v);
}