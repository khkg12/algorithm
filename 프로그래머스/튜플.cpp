#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
return a.second > b.second;
}

vector<int> solution(string s) {
vector<int> answer;
map<int, int> map;
string str;
for(char ch : s){
if(isdigit(ch)) str += ch;
else if(!str.empty()){
answer.push_back(stoi(str));
str = "";
}
}

    for(int i = 0; i < answer.size(); i++){
        map[answer[i]]++;
    }
    answer.clear();

    vector<pair<int, int>> pv(map.begin(), map.end());
    sort(pv.begin(), pv.end(), cmp);
    for(int i = 0; i < pv.size(); i++) answer.push_back(pv[i].first);

return answer;
}
