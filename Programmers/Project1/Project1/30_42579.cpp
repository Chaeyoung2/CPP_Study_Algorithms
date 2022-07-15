// 프로그래머스 고득점 kit - 베스트 앨범
// (7/15 - O)

#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// 베스트 앨범에 들어갈 노래의 고유번호를 순서대로 리턴!
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int song_cnt = genres.size();

    // 1. 가장 많이 플레이된 장르는?
    map<string, int> m1;
    for (int i = 0; i < song_cnt; i++) {
        m1[genres[i]] += plays[i];
    }
    int genres_cnt = m1.size();

    int while_cnt = 0;
    while (!m1.empty()) {
        vector < pair<string, int >> v1(m1.begin(), m1.end());
        sort(v1.begin(), v1.end(), [](const pair<string, int>& p1, const pair<string, int>& p2) {
            return p1.second > p2.second;
            });
        string maxplay_genre = v1[0].first;
        m1.erase(maxplay_genre);

        // 2. 가장 많이 플레이된 장르 중에서 가장 많이 플레이된 곡 두 개를 뽑아서 고유번호를 push
        map<int, int> m2; // first 고유번호, second 플레이 횟수
        for (int i = 0; i < song_cnt; i++) {
            if (genres[i] == maxplay_genre) {
                m2[i] = plays[i];
            }
        }
        vector<pair<int, int>> v2(m2.begin(), m2.end());
        sort(v2.begin(), v2.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.second == p2.second) {
                p1.first < p2.first;
            }
            else {
                return p1.second > p2.second;
            }});
        int song_cnt = m2.size();
        for (int i = 0; i < song_cnt; i++) {
            if (i >= 2) break;
            answer.push_back(v2[i].first);
        }
    }



    return answer;
}

int main() {
    solution({ "classic", "pop", "classic", "classic", "pop" },
        { 500, 600, 150, 800, 2500 });
}