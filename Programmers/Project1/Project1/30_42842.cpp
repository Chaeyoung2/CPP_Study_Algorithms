// ���α׷��ӽ� �����kit - ���� Ž�� - ī��
// (7/16 - O) 

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    vector<vector<int>> v;

    // i�� j�� �ٵ����̶� ��������.
    // �׵θ��̹Ƿ� j�� �ּڰ��� y + 2
    int i = 3, j = 3;
    int b = brown, y = yellow;
    while (true) {
        int line = (brown - (j * 2)) / 2;
        int y_cnt = line * (j - 2);
        if (y_cnt == yellow) {
            i = line + 2;
            break;
        }
        j++;
    }
    if (i > j) {
        int temp = j;
        j = i;
        i = temp;
    }

    answer.push_back(j);
    answer.push_back(i);
    return answer;
}

int main()
{
    solution(24, 24);
}
