// 3.1 거스름돈
#include <iostream>
using namespace std;
// 손님에게 거슬러 줄 돈이 N원
// 거슬러 주어야 할 동전의 최소 개수 X
// N원은 항상 10의 배수

int n, x;
int arr[4] = { 500, 100, 50, 10 };
int main()
{
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		cnt += n / arr[i];
		n %= arr[i];
	}
	cout << cnt << "\n";
}


