// N명 이름, 국영수 점수
// 조건에 따라 정렬
// 1. 국어 내림차순 순서
// 2. 국어가 같으면 영어 오름차순
// 3. 국어 영어 같으면 수학 내림차순
// 4. 모두 같으면 이름 사전순 (대문자가 소문자보다 앞)

// input :
// 12 Junkyu 50 60 100 Sangkeun 80 60 50 Sunyoung 80 70 100 Soong 50 60 90 Haebin 50 60 100 Kangsoo 60 80 100 Donghyuk 80 60 100 Sei 70 70 70 Wonseob 70 70 90 Sanghyun 70 70 80 nsj 80 80 80 Taewhan 50 60 90

#include <iostream>
#include <string>
#include <vector>
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

	qsort(&v[0], n, sizeof(student), [](const void* d, const void* s) -> int {
		const student* des = (student*)(d);
		const student* src = (student*)(s);
		if (des->kor < src->kor) return true;
		else if (des->kor > src->kor) return false;
		else {
			if (des->eng > src->eng) return true;
			else if (des->eng < src->eng) return false;
			else {
				if (des->mat < src->mat) return true;
				else if (des->mat > src->mat) return false;
				else {
					int size = min(src->name.size(), des->name.size());
					for (int i = 0; i < des->name.size(); i++) {
						if (des->name[i] > src->name[i]) return true;
						else if (des->name[i] < src->name[i]) return false;
						else continue;
					}
				}
			}
		}
		}
		);

	for (int i = 0; i < n; i++) {
		cout << v[i].name << "\n";
	}
}


