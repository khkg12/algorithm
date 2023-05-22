#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
int answer = 0;
deque<string> q;
bool check;
int idx;
for(int i = 0; i < cities.size(); i++){ // 대문자 변환
for(int j = 0; j < cities[i].size(); j++){
if(('a' <= cities[i][j]) && (cities[i][j] <= 'z')){
cities[i][j] -= 32;
}
}
}

    if(cacheSize == 0) answer += 5 * cities.size();
    else{
        for(int i = 0; i < cities.size(); i++){
            check = false;
            for(idx = 0; idx < q.size(); idx++){
                if(q[idx] == cities[i]) {
                    check = true;
                    break;
                }
            }
            q.push_back(cities[i]);
            if(check == true){
                answer++;
                q.erase(q.begin() + idx);
            }
            else{
                if(q.size() > cacheSize){
                    q.pop_front();
                }
                answer+=5;
            }
        }
    }

    return answer;

}
