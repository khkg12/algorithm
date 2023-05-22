#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
int answer = 0;
int sum = 0; // 다리를 지나고있는 트럭의 총 무게
int idx = 0; // 내보낼 차량 순서

    queue<int> q;
    while(1){
        int truck = truck_weights[idx];
        if(idx == truck_weights.size()){ // 차가 마지막 차량일때
            answer += bridge_length;
            break;
        }

        answer++;

        if(q.size() == bridge_length){ // 맨 앞의 차가 다리를 다 건넜다는 의미
            sum -= q.front();
            q.pop();
        }

        if(truck + sum <= weight){ // 다리를 건널 수 있다면
            sum += truck;
            q.push(truck);
            idx++;
        }
        else{
            q.push(0);
        }
    }
    return answer;

}
