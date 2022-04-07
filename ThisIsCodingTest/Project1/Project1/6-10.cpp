// 6-10. 위에서 아래로
#include <iostream>
using namespace std;

int arr[501];
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		arr[i] = val;
	}

	for (int i = 0; i < n; i++) {
		int max_index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[max_index] < arr[j]) {
				max_index = j;
			}
		}
		int temp;
		temp = arr[i];
		arr[i] = arr[max_index];
		arr[max_index] = temp;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}
