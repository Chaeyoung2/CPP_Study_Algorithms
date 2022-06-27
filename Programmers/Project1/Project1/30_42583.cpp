// ���α׷��ӽ� ����� Kit - �ٸ��� ������ Ʈ��
// (6/27 - O)

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> trucks;
    for (const int& i : truck_weights) {
        trucks.push(i);
    }

    vector<int> on_time;
    int time = 0, bridge_weight = 0;
    queue<int> onbridge;
    while (true) {
        // ���� �� �ٸ��� ���� Ʈ���� �ִ°�?
        if (!onbridge.empty() && on_time[0] >= bridge_length) {
            bridge_weight -= onbridge.front();
            onbridge.pop();
            on_time.erase(on_time.begin());
        }

        // Ʈ�� �Ѱ��� �ٸ��� ������ �� �ִ°�?
        if (!trucks.empty()) {
            int f = trucks.front();
            if (bridge_weight + f <= weight) {
                bridge_weight += f; // ���� �����Ƿ� ����!
                onbridge.push(f);
                on_time.push_back(0);
                trucks.pop();
            }
        }
        // �� Ʈ������ �ٸ��� �ִ� �ð� ����������
        for (auto& i : on_time) {
            i++;
        }
        time++;
        if (onbridge.empty()) break;
    }
    answer = time;
    return answer;
}

// �� �ڵ庸�� 10�� ������ �ڵ�
//#include <iostream>
//#include<algorithm>
//#include <functional>         // greater ��� ���� �ʿ�  
//#include <vector>
//#include<queue>
//using namespace std;
//
//int solution(int bridge_length, int weight, vector<int> truck_weights) {
//    int answer = 0;
//    int count = 0;
//    int Time = 0;
//    int Truck_weight = 0;
//    queue<pair<int, int>> truck_move;
//
//    while (true)
//    {
//        if (weight >= Truck_weight + truck_weights.at(count))
//        {
//            truck_move.push(make_pair(truck_weights.at(count), bridge_length + 1 + Time));
//            Truck_weight += truck_weights.at(count);
//            count++;
//        }
//
//        if (count >= truck_weights.size())
//        {
//            answer = truck_move.back().second;
//            break;
//        }
//        else
//        {
//            Time++;
//            if (truck_move.front().second == Time + 1)
//            {
//                Truck_weight -= truck_move.front().first;
//                truck_move.pop();
//            }
//        }
//
//    }
//
//    return answer;
//}

int main() {
    vector<int> v = { 10};
    solution(100, 100, v);
}