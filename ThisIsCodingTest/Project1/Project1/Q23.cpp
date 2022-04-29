// N�� �̸�, ������ ����
// ���ǿ� ���� ����
// 1. ���� �������� ����
// 2. ��� ������ ���� ��������
// 3. ���� ���� ������ ���� ��������
// 4. ��� ������ �̸� ������ (�빮�ڰ� �ҹ��ں��� ��)

// input :
// 12 Junkyu 50 60 100 Sangkeun 80 60 50 Sunyoung 80 70 100 Soong 50 60 90 Haebin 50 60 100 Kangsoo 60 80 100 Donghyuk 80 60 100 Sei 70 70 70 Wonseob 70 70 90 Sanghyun 70 70 80 nsj 80 80 80 Taewhan 50 60 90

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class student {
public:
	string name;
	int kor;
	int eng;
	int mat;
};


int n;
vector<student> v;


int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		student s;
		cin >> s.name;
		cin >> s.kor;
		cin >> s.eng;
		cin >> s.mat;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), [](student& des, student& src) -> bool {
		if (des.kor == src.kor && des.eng == src.eng && des.mat == src.mat) {
			return des.name < src.name;
		}
		else if (des.kor == src.kor && des.eng == src.eng) {
			return des.mat > src.mat;
		}
		else if (des.kor == src.kor) {
			return des.eng < src.eng;
		}
		else {
			return des.kor > src.kor;
		}
		}
		);

	for (int i = 0; i < n; i++) {
		cout << v[i].name << "\n";
	}
}


