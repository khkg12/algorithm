#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> time) {
    int answer = 0;
    vector<pair<int, int>> v;
    for(int i = 0; i < time.size(); i++){
        string h = time[i][0].substr(0, 2);
        string m = time[i][0].substr(3, 2);
        int t = stoi(h) * 60 + stoi(m);
        h = time[i][1].substr(0, 2);
        m = time[i][1].substr(3, 2);
        int t2 = stoi(h) * 60 + stoi(m);
        v.push_back({t, t2});
    }
    sort(v.begin(), v.end()); // 정렬
    
    int sum = 0;
    vector<pair<int, int>> room; // 현재 사용되고 있는 객실
    
    for(int i = 0; i < v.size(); i++){
        vector<pair<int, int>> temp;
        for(int j = 0; j < room.size(); j++){
            if(v[i].first < room[j].second + 10){ // 시간의 흐름에 따른 방문자의 입실시간보다 사용하고있는 객실중 퇴실시간이 길다면 방을 내어줄수 없으므로 여전히 현재 사용되고 있는 객실 vector인 room에 남아있어야함 temp(나중에 room으로 대체되는) vector에 추가
                temp.push_back(room[j]);                    
            }
        }
        room = temp;
        room.push_back(v[i]);
        int size = room.size();
        answer = max(answer, size); // 따라서 answer은 모든 방문자가 방문할 때마다의 최고 객실 카운터 수
    }
    return answer;
}