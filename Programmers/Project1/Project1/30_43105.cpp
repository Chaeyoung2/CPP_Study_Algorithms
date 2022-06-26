// 프로그래머스 고득점 kit - 정수 삼각형
// (6/26 - O)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = 0; i < 501; i++) {
        fill(dp[i], dp[i] + 501, -1);
    }

    dp[0][0] = triangle[0][0];

    int i_size = triangle.size();
    for (int i = 1; i < i_size; i++) {
        int j_size = triangle[i].size();
        for (int j = 0; j < j_size; j++) {
            if(j - 1 >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + triangle[i][j]);
        }
    }
    
    answer = *max_element(dp[i_size - 1], dp[i_size - 1] + triangle[i_size - 1].size());

    return answer;
}

int main()
{
    vector<vector<int>> v;
    v.push_back({ 7 });
    v.push_back({ 3,8 });
    v.push_back({ 8,1,0 });
    v.push_back({ 2,7,4,4 });
    v.push_back({ 4,5,2,6,5 });

    solution(v);
}