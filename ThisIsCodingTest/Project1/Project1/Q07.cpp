// ������ Ư�� ������ ������ ���� ����� �� �ִ� �ʻ��.
// Ư�� ����: ���� ĳ���� ������ N�� ��, 
// �ڸ����� �������� N�� ������ ������ ���� �κ��� �� �ڸ��� �հ� ������ �� �ڸ��� ���� ������ ��Ȳ
// ���� N�� �־����� �� �ʻ�� ��� �������� �ƴ��� �˷� �ִ� ���α׷� �ۼ�

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int left=0, right = 0;
	int half = s.size() * 0.5f;
	for (int i = 0; i < s.size(); i++) {
		if (i < half)
			left += (s[i] - 48);
		else
			right += (s[i] - 48);
	}

	if (left == right)
		cout << "LUCKY" << "\n";
	else
		cout << "READY" << "\n";
}
