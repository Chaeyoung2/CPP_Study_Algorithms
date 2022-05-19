// �� ��ȣ�� �ٸ� ��ȣ�� ���ξ�����?
// (5/18) X ���̵�� ��Ʈ �޾Ƽ� Ǯ����. �ٽ� Ǯ ��
// (5/19) X ���� Ž�� ���� �����ϴ°� �� ��Ծ�~??

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (string& s : phone_book) {
        int st_len = s.length();
        string des = s;
        for (int i = 1; i < st_len; i++) {
            // des�� ���ξ� ã��
            if (binary_search(phone_book.begin(), phone_book.end(), des.substr(0, i))) {
                return false;
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> v;
    v.push_back("123");
    v.push_back("456");
    v.push_back("789");
    solution(v);
}