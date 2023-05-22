#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    int tSize = topping.size();
    map<int, int> c1, c2; // topping type, count
    
    // 안자른상태
    for(int i=0; i<tSize; i++){
        map<int,int>::iterator it = c1.find(topping[i]);        
        if(it != c1.end()) // 값이 이미 존재한다면
            (it->second)++;            
        else
            c1.insert(make_pair(topping[i], 1));
    }
    
    // 자른 범위를 한칸씩 늘리면서 공평여부 check
    for(int i = tSize - 1; i > 0; i--){
        map<int, int>::iterator it = c1.find(topping[i]);
        if(it->second == 1){ // 토핑의 개수가 1이라면 삭제되고
            c1.erase(topping[i]);
        }
        else{ // 1개가 아니라면 1개제거
            c1[topping[i]]--;            
        }
        it = c2.find(topping[i]);
        if(it != c2.end()){ // 만일 토핑이 이미 있다면 1을 더해주고
            c2[topping[i]]++;
        }
        else{ // 처음들어오는 토핑이라면 1을 넣어줌
            c2[topping[i]] = 1;
        }
        if(c1.size() == c2.size()) answer++;
    }
    
    return answer;
}