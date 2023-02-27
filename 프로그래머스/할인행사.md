#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, int> m;

bool check(map<string, int> map){
for(auto i : m){
if(map.find(i.first) == map.end()) return false; // 사려는 품목이 없다면
else if(map[i.first] < i.second) return false;
}
return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
int answer = 0;  
 map<string, int> m2;

    for(int i = 0; i < want.size(); i++){
        m[want[i]] = number[i];
    }

    for(int i = 0; i <= discount.size()-10; i++){
        for(int j = i; j < i+10; j++){
            m2[discount[j]]++;
        }
        if(check(m2)) answer++;
        m2.clear();
    }

    return answer;

}
