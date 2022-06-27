// 프로그래머스 고득점 kit - 단어 변환
// (6/27 - O)
#include <string>
#include <vector>
#include<queue>

using namespace std;

// 풀이 1. dfs
int visited[51];
int begin_len;
int words_size;
int min_cnt;

void dfs(string begin, string target, vector<string>& words, int& cnt) {
    if (begin == target) {
        min_cnt = min(min_cnt, cnt);
        for (int i = 0; i < words_size; i++) {
            if (words[i] == begin) {
                visited[i] = false;
            }
        }
        cnt--;
        return;
    }
    for (int i = 0; i < begin_len; i++) { // 앞 글자부터 하나씩 바꿔보기
        int convert_cnt = 0;
        char ori = begin[i];
        while (true) {
            begin[i] = 'a' + (convert_cnt++);
            if (begin[i] == ori) {
                continue;
            }
            if (begin[i] > 'z') {
                begin[i] = ori;
                break;
            }
            for (int j = 0; j < words_size; j++) {
                if (words[j] == begin && visited[j] == false) {
                    begin = words[j];
                    visited[j] = true;
                    cnt++;
                    dfs(begin, target, words, cnt);
                }
            }
        }
    }
    for (int i = 0; i < words_size; i++) { // 들어갔다 나왓으면 다시 visted false 처리
        if (words[i] == begin) {
            visited[i] = false;
            cnt--;
        }
    }
}


int solution(string begin, string target, vector<string> words) {
	int answer = 0;

	// words 안에 target이 있는지 확인
	bool isin = false;
	for (auto& i : words) {
		if (i == target) isin = true;
	}
	// 있으면
	if (isin) {
		// begin=hit
		// target=cog
		begin_len = begin.length();
		words_size = words.size();
		string b = begin;
		min_cnt = 1e9;
		int cnt = 0;
		dfs(b, target, words, cnt);
		answer = min_cnt;
	}
	// 없으면
	else {
		answer = 0;
	}
	return answer;
}

// 풀이 2. bfs
//int solution(string begin, string target, vector<string> words) {
//    int answer = 0;
//    //방문여부
//    int c[50] = { 0, };
//    queue<pair<string, int>> q;
//    int str_s = begin.size();
//    int count = 0;
//    //1. target이 있는지확인한다.
//    for (int i = 0; i < words.size(); i++) {
//        //타깃이 있다면 
//        if (words[i] == target) {
//            count++;
//            break;
//        }
//    }
//    if (count == 0)return 0;
//
//    //2. bfs방식으로 검색
//    q.push({ begin,0 });
//
//    while (!q.empty()) {
//        auto w = q.front();
//        q.pop();
//        //타깃인경우
//        if (w.first == target) {
//            answer = w.second;
//            break;
//        }
//
//        for (int i = 0; i < words.size(); i++) {
//            int cnt = 0;
//            //자기 자신인경우 넘어가기
//            if (words[i] == w.first)continue;
//            //방문한경우 넘어가기
//            if (c[i] == 1)continue;
//            //한글자만 바꿀수 있으므로 cnt==2 이상이여야만 큐에넣을수잇다.
//            for (int j = 0; j < str_s; j++) {
//                if (words[i][j] == w.first[j]) {
//                    cnt++;
//                }
//            }
//
//            if (cnt == str_s - 1) {
//                //q에 넣어주고 체크했다고 저장하기
//                q.push({ words[i],w.second + 1 });
//                c[i] = 1;
//            }
//        }
//    }
//
//    return answer;
//}

int main() {
    vector<string> v{ "hot", "dot", "dog", "lot", "log", "cog" };
    solution("hit", "cog", v);
}