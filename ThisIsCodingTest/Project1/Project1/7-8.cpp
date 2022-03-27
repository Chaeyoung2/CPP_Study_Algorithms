// 7-8. ������ �� �����

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;


int binary_search(vector<int>& arr, int start, int end) {
	while (start < end) {
		int mid = (start + end) / 2;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if(arr[i] - mid >= 0)
				sum += (arr[i] - mid);
		}
		if (sum < m) { // sum�� m���� �۴ٴ� �� �ʹ� ���� �߶��ٴ� �����ݾ�. mid�� �۾�����.
			end = mid - 1;
		}
		else if (sum > m) { // sum�� m���� ũ�ٴ� �� �ʹ� ���� �߶��ٴ� ��. mid�� Ŀ����.
			start = mid + 1;
		}
		else {
			return mid;
		}
	}
}

int main()
{
	cin >> n >> m;
	int max = 0;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		arr.push_back(val);
		if (max <= val) max = val;
	}
	int result = binary_search(arr, 0, max);

	cout << arr[result] << "\n";
	
}
