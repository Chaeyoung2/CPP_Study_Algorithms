#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    
    map<string, int> genre_cnt;// � �帣�� ���� ���� play �Ǿ����� ã��
    int size = genres.size();
    for (int i = 0; i < size; i++) {
        genre_cnt[genres[i]] += plays[i];
    }    
    string max_g = max_element(genre_cnt.begin(), genre_cnt.end(), [](const pair<string,int>& l, const pair<string,int>& r) {
        return l.second < r.second;
        })->first;
    

    // ���� play �� �帣���� �� �� �̱�
    map<int, int> m; // first:���� ��ȣ, second:play Ƚ��
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