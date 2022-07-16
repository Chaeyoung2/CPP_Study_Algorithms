// 프로그래머스 고득점kit - dfs/bfs - 여행경로
// (7/16 - X) 


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> route;
int t_size;

bool dfs(vector<vector<string>> tickets, vector<bool> visited, string cur, int use_cnt) {
    route.push_back(cur);
    for (int i = 0; i < t_size; i++) {
        if (tickets[i][0] == cur && visited[i] == false) {
            visited[i] = true;
            if (false == dfs(tickets, visited, tickets[i][1], use_cnt + 1)) {
                visited[i] = false;
            }
            else {
                return true;
            }
        }
    }
    if (use_cnt < t_size) {
        route.pop_back();
        return false;
    }
    else {
        return true;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    t_size = tickets.size();
    vector<bool> visited(t_size, false);
    
    sort(tickets.begin(), tickets.end());

    dfs(tickets, visited, "ICN", 0);
    return route;
}
int main() {
    solution({ { "ICN", "SFO" }, { "ICN", "ATL" }, { "SFO", "ATL" }, { "SFO", "ATL" }, { "ATL", "ICN" }, { "ATL","SFO" }});
    //solution({ { "ICN", "a" }, { "a", "b" }, { "b", "d" }, { "a", "c" }, { "c", "a" } });
}