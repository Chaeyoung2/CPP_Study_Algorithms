// 프로그래머스 고득점 kit - greedy - 구명보트
// (7/2 - X)
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
	deque<int> d;
	for (const auto& i : people) {
		d.push_back(i);
	}
    sort(d.begin(), d.end());
	while (!d.empty()) {
		if (*(d.begin()) + *(d.end() - 1) <= limit) {
			answer++;
			d.pop_back();
			if (d.empty()) 
				break;
			d.pop_front();
		}
		else {
			answer++;
			d.pop_back();
		}

    }
    return answer;
}
int main() {
    vector<int> v{ 70,50, 80,50 };
    solution(v, 100);
}