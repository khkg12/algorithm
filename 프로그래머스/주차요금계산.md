#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
vector<int> answer;
map<string, pair<int,int>> m;
map<string, vector<int>> m2;

    for(int i = 0; i < records.size(); i++){
        m[records[i].substr(6,4)].first += 1; // 홀수인지 짝수인지 파악하기 위함

        string hour = records[i].substr(0,2);
        string minute = records[i].substr(3,2);
        int time = stoi(hour) * 60 + stoi(minute);
        m2[records[i].substr(6,4)].push_back(time);

        if(m[records[i].substr(6,4)].first % 2 == 0 && m[records[i].substr(6,4)].first != 0){ // 짝수라면
            int sum = m2[records[i].substr(6,4)][1] - m2[records[i].substr(6,4)][0];
            m[records[i].substr(6,4)].second += sum;
            m2[records[i].substr(6,4)].clear();
            m[records[i].substr(6,4)].first = 0;
        }
    }


    for(int i = 0; i < records.size(); i++){
        if(m[records[i].substr(6,4)].first == 1){
            int time = 1439 - m2[records[i].substr(6,4)][0];
            m[records[i].substr(6,4)].second += time;
            m[records[i].substr(6,4)].first -= 1;
        }
    }


    for(auto i : m){
        if(i.second.second > fees[0]){
            int sum = fees[1] + ((i.second.second - fees[0]) / fees[2]) * fees[3];
            if((i.second.second - fees[0]) % fees[2] != 0) sum += fees[3];
            answer.push_back(sum);
        }
        else{
            answer.push_back(fees[1]);
        }
    }


    return answer;

}
