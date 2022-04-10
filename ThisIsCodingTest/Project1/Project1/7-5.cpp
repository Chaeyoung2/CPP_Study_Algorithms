// 7-5. 부품 찾기
// 부품 n개, 손님이 원하는 부품 종류 m개
// 부품이 모두 있는지 확인하는 프로그램

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int binary_search_while(vector<int>& v, int target, int start, int end) {
	while (start < end) {
		int mid = (start + end) * 0.5;
		if (v[mid] == target) {
			return mid;
		}
		else if (v[mid] < target) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
}

int binary_search(vector<int>& v, int target, int start, int end) {
	if (start >= end) return -1;
	int mid = (start + end) * 0.5;
	if (target == v[mid])
		return mid;
	else if (target > v[mid]) {
		return binary_search(v, target, mid + 1, end);
	}
	else {
		return binary_search(v, target, start, mid - 1);
	}
}

int main() {

	vector<int> ns;
	vector<int> ms;


	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		ns.push_back(val);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int val;
		cin >> val;
		ms.push_back(val);
	}

	sort(ns.begin(), ns.end());

	int search_cnt = 0;
	for (int i = 0; i < m; i++) {
		if (-1 != binary_search(ns, ms[i], 0, n-1))
			cout << "yes ";
		else
			cout << "no ";
	}
	cout << '\n';


}


