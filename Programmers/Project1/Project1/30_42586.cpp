// �� �������� �� ���� ����� �����Ǵ°�
// ������ �Ϸ翡 �� ����, �Ϸ��� ���� �̷����
// ���� ��� ������ 95%�̰� �ӵ��� �Ϸ翡 4�� �۾��� ������ 2�� �ڿ� �̷����

// 

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int sz = progresses.size();
    queue<pair<int, int>> q;
    for (int i = 0; i < sz; i++) {
        q.push({ progresses[i], speeds[i] });
    }

    int day_cnt = 0;
    int out = 0;
    while (!q.empty()) {
		day_cnt++;
		int jindo = q.front().first + (q.front().second * day_cnt);
		if (jindo >= 100) {
			q.pop();
            out++;
			while (!q.empty()) {
				jindo = q.front().first + (q.front().second * day_cnt);
				if (jindo >= 100) {
					q.pop();
					out++;
				}
				else {
					break;
				}
			}
            answer.push_back(out);
            out = 0;
		}

	}


    return answer;
}

int main()
{
    vector<int> p = { 95, 90, 99, 99, 80, 99 };
    vector<int> s = { 1, 1, 1, 1, 1, 1};
    solution(p, s);
}

