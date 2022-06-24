// [���α׷��ӽ� ���� ����� Kit] �ؽ� - ��ȭ��ȣ ���

// �� ��ȣ�� �ٸ� ��ȣ�� ���ξ�����?
// (5/18) X ���̵�� ��Ʈ �޾Ƽ� Ǯ����. �ٽ� Ǯ ��
// (5/19) X ���� Ž�� ���� �����ϴ°� �� ��Ծ�~??

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> m;

    for (string& s : phone_book) {
        m.insert({ s, 0 });
    }

    for (auto& p : m) {
        int len = p.first.length();
        for (int i = 1; i < len; i++) {
            if (m.find(p.first.substr(0, i)) != m.end()) {
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

    for (string& s : v) {
        s.substr(0, 1);
    }
    solution(v);
}