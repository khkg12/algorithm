#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int idx = 0, time = 0;
    
    while(idx < jobs.size() || !pq.empty()){
        cout << time << " ";
        if(idx < jobs.size() && time >= jobs[idx][0]){ // time이 해당 인덱스에 해당되는 시작시간보다 클때, 즉 일을 해결했을때 새롭게 일이 추가
            pq.push(make_pair(jobs[idx][1], jobs[idx][0]));
            idx++;
            continue;
        }
        
        if(!pq.empty()){
            time += pq.top().first;
            answer += time - pq.top().second;
            pq.pop();
        }
        
        else{
            time = jobs[idx][0];
        }
    }
    
    return answer / jobs.size();
}