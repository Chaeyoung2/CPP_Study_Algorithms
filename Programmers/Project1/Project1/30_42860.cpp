#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;

    int size = name.size();
    int updown = 0, leftright = size - 1;

    vector<char> v(size);
    int i = 0;
    for (auto& s : name) {
        v[i++] = s;
    }

    // left-right
    for (int start_idx = 0; start_idx < size; start_idx++) {
        updown += min(abs('A' - v[start_idx]), abs('Z' - v[start_idx]) + 1);

        int end_idx = start_idx + 1;
        while (end_idx < size && v[end_idx] == 'A') {
            end_idx++;
        }
        leftright = min(leftright, 2 * start_idx + (size - end_idx));
        leftright = min(leftright, 2 * (size - end_idx) + start_idx);
    }

    answer = leftright + updown;
    return answer;
}