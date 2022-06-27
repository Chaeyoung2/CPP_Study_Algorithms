// ���α׷��ӽ� ����� kit - �ܾ� ��ȯ
// (6/27 - O)
#include <string>
#include <vector>
#include<queue>

using namespace std;

// Ǯ�� 1. dfs
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
    for (int i = 0; i < begin_len; i++) { // �� ���ں��� �ϳ��� �ٲ㺸��
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
    for (int i = 0; i < words_size; i++) { // ���� �������� �ٽ� visted false ó��
        if (words[i] == begin) {
            visited[i] = false;
            cnt--;
        }
    }
}


int solution(string begin, string target, vector<string> words) {
	int answer = 0;

	// words �ȿ� target�� �ִ��� Ȯ��
	bool isin = false;
	for (auto& i : words) {
		if (i == target) isin = true;
	}
	// ������
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
	// ������
	else {
		answer = 0;
	}
	return answer;
}

// Ǯ�� 2. bfs
//int solution(string begin, string target, vector<string> words) {
//    int answer = 0;
//    //�湮����
//    int c[50] = { 0, };
//    queue<pair<string, int>> q;
//    int str_s = begin.size();
//    int count = 0;
//    //1. target�� �ִ���Ȯ���Ѵ�.
//    for (int i = 0; i < words.size(); i++) {
//        //Ÿ���� �ִٸ� 
//        if (words[i] == target) {
//            count++;
//            break;
//        }
//    }
//    if (count == 0)return 0;
//
//    //2. bfs������� �˻�
//    q.push({ begin,0 });
//
//    while (!q.empty()) {
//        auto w = q.front();
//        q.pop();
//        //Ÿ���ΰ��
//        if (w.first == target) {
//            answer = w.second;
//            break;
//        }
//
//        for (int i = 0; i < words.size(); i++) {
//            int cnt = 0;
//            //�ڱ� �ڽ��ΰ�� �Ѿ��
//            if (words[i] == w.first)continue;
//            //�湮�Ѱ�� �Ѿ��
//            if (c[i] == 1)continue;
//            //�ѱ��ڸ� �ٲܼ� �����Ƿ� cnt==2 �̻��̿��߸� ť���������մ�.
//            for (int j = 0; j < str_s; j++) {
//                if (words[i][j] == w.first[j]) {
//                    cnt++;
//                }
//            }
//
//            if (cnt == str_s - 1) {
//                //q�� �־��ְ� üũ�ߴٰ� �����ϱ�
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