#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
vector<int> answer;
deque<int> q;
deque<int> sq;
for(int i : progresses) q.push_back(i);
for(int i : speeds) sq.push_back(i);

    while(!q.empty()){
        int size = q.size();
        int app = 0;
        for(int i = 0; i < size; i++){
            if(q.front() >= 100) {
                q.pop_front();
                sq.pop_front();
                app++;
            }
        }
        if(app > 0) answer.push_back(app);
        for(int i = 0; i < q.size(); i++){
            q[i] += sq[i];
            cout << q[i] << " ";
        }
    }
    return answer;

}
