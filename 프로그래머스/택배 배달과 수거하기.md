#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
long long answer = 0;
stack<int> go, back;
for(auto i : deliveries){
go.push(i);
}
for(auto i : pickups){
back.push(i);
}
while(!go.empty() && !go.top()){
go.pop();
}
while(!back.empty() && !back.top()){
back.pop();
}

    while(!(go.empty() && back.empty())){
        answer += max(go.size() * 2, back.size() * 2);
        int box = 0;
        while(!go.empty() && box <= cap){
            if(go.top() + box <= cap){
                box += go.top();
            }
            else{
                go.top() -= (cap - box); // 전부 배달할수 없으니 최대한으로 배달시킴, 예를들어
                                         // 최대 수화물이 4개고 현재 박스가 3개, go.top이 2개 일                                          // 때에 최대 수화물 - 현재박스 갯수 만큼만 배달하고 그 남
                                         // 은 값을 go.top에 둔다는 의미
                break;
            }
            go.pop();
        }
        box = 0;
        while(!back.empty() && box <= cap){
            if(back.top() + box <= cap){
                box += back.top();
            }
            else{
                back.top() -= (cap - box);
                break;
            }
            back.pop();
        }
    }

    return answer;

}
