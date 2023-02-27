#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
int answer = 1;
unordered_map<string, int> map;
for(int i = 0; i < clothes.size(); i++){
map[clothes[i][1]]++;
}
vector<pair<string, int>> pv(map.begin(), map.end());
for(int i = 0; i < pv.size(); i++){
answer \*= pv[i].second + 1;
}
return answer-1;
}
