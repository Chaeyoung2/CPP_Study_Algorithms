#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    
    map<string, int> genre_cnt;// 어떤 장르가 가장 많이 play 되었는지 찾기
    int size = genres.size();
    for (int i = 0; i < size; i++) {
        genre_cnt[genres[i]] += plays[i];
    }    
    string max_g = max_element(genre_cnt.begin(), genre_cnt.end(), [](const pair<string,int>& l, const pair<string,int>& r) {
        return l.second < r.second;
        })->first;
    

    // 많이 play 된 장르에서 두 곡 뽑기
    map<int, int> m; // first:고유 번호, second:play 횟수
    for (int i = 0; i < size; i++) {
        if (genres[i] == max_g) {
            m[i] = plays[i];
        }
    }

    return answer;
}

int main() {
    solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });
}