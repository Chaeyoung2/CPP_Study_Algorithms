// 6-11. ������ ���� ������ �л� ����ϱ�
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
int main() {
	cin >> n;
	vector<vector<string>> v(101);
	for (int i = 0; i < n; i++) {
		string s;
		int score;
		cin >> s >> score;
		v[score].push_back(s);
	}
	for (int i = 0; i < 101; i++) {
		for (auto& i : v[i]) {
			cout << i << " ";
		}
	}
}

