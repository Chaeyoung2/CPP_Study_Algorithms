// BOJ 1037: 약수
// 양수 A가 N의 약수가 되려면, N은 A의 배수이고 A가 1과 N이 아니어야 한다.
// 어떤 수 N의 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(0);

	int div_cnt = 0;
	cin >> div_cnt;
	
	priority_queue<int, vector<int>> pq;
	priority_queue<int, vector<int>, std::greater<int>> pq_greater;

	for (int i = 0; i < div_cnt; i++) {
		int key;
		cin >> key;
		pq.push(key);
		pq_greater.push(key);
	}
	int min = pq.top();
	int max = pq_greater.top();

	int result = min * max;
	cout << result << "\n";
}

