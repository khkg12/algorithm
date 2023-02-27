#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
int answer = 0;
deque<pair<int, int>> q;
for(int i = 0; i < priorities.size(); i++){
q.push_back({priorities[i], i});
}

    while(1){
        bool check = false;
        for(int i = 1; i < q.size(); i++){
            if(q.front().first < q[i].first) {
                check = true; // 중요도가 더 높은 문서가 존재
                break;
            }
        }
        if(check == true){
            pair<int,int> tmp = {q.front().first, q.front().second};
            q.pop_front();
            q.push_back(tmp);
            cout << q.front().second << " 트루";
        }
        else{
            if(q.front().second == location){
                answer++;
                break;
            }
            q.pop_front();
            answer++;
            cout << q.front().second << " ";
        }

    }
    return answer;

}
