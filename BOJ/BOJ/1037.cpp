// BOJ 1037: ���
// ��� A�� N�� ����� �Ƿ���, N�� A�� ����̰� A�� 1�� N�� �ƴϾ�� �Ѵ�.
// � �� N�� ����� ��� �־��� ��, N�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

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

