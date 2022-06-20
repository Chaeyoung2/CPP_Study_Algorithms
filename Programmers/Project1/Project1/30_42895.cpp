// [프로그래머스 코테 고득점 Kit] dynamic programming - n으로 표현
#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int make(int N, int p){//i=2일때 NN = N * 10 + N, i=3일때 NNN = N * 100 + N * 10 + N, i=4일때 NNNN..
    int value = 0;
    for (int i = 1; i <= p; i++) {
        value += N * pow(10, i - 1);
    }
    return value;
}

int solution(int N, int number) {
    int answer = 0;

    if (N == number) return 1;

    vector<unordered_set<int>> box(9);
    
    box[1].insert(N); // N1에는 N 하나만
    for (int i = 2; i < 9; i++) { //i3
        box[i].insert(make(N, i)); 
        for (int j = 1; j < i; j++) { //j=1,1<3,i-j==2 // j=2,2<3,i-j==1 //
            for (auto& num_first : box[j]) {
                for (auto& num_second : box[i - j]) {
                    box[i].insert(num_first + num_second);
                    box[i].insert(num_first - num_second);
                    box[i].insert(num_first * num_second);
                    if(num_second != 0)
                        box[i].insert(num_first / num_second);
                    box[i].insert(num_second + num_first);
                    box[i].insert(num_second - num_first);
                    box[i].insert(num_second * num_first);
                    if (num_first != 0)
                        box[i].insert(num_first / num_first);
                }
            }
        }
        if (box[i].end() != box[i].find(number)) {
            answer = i;
            return answer;
        }
    }

    return -1;
}

int main() {
    solution(5, 12);
}