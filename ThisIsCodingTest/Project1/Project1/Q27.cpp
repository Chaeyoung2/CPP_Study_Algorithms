// Q27. ���ĵ� �迭���� Ư�� �� ���� ���ϱ�.
// n�� ������ ������ ������������ ���ĵǾ� ����
// �̶� �������� x�� �����ϴ� Ƚ��.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int b, e, mid;
	b = 0;
	mid = n / 2;
	e = n - 1;
	int result = -1;
 	while (e != b + 1) {
		if (v[mid] == x) {
			int b_temp = mid;
			int e_temp = mid;
			while (v[b_temp] == x) {
				b_temp--;
			}
			while (v[e_temp] == x) {
				e_temp++;
			}
			result = e_temp - b_temp - 1;
			break;
  		}
		else if (binary_search(&v[b], &v[mid], x)) {
			e = mid;
		}
		else {
			b = mid;
		}
		mid = (b + e) / 2;
	}
	cout << result << "\n";
}


