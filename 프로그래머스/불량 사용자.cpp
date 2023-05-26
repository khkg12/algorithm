#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

bool check(string id, string ban){
    for(int i = 0; i < id.size(); i++){
        if(ban[i] != '*'){
            if(id[i] != ban[i]) return false;
        }
    }
    return true;
}

int solution(vector<string> id, vector<string> ban) {
    int answer = 0;
    set<string> s;
    
    sort(id.begin(), id.end());
    do{
        vector<string> tmp;
        string Id = "";
        for(int i = 0; i < ban.size(); i++){
            if(id[i].size() == ban[i].size()){ // 글자수가 같으면
                if(check(id[i], ban[i])){ // 금지 아이디조건에 해당한다면
                    tmp.push_back(id[i]);
                }                    
            }
            
            if(tmp.size() == ban.size()){ // next_permutation으로 돌린값이 모든 금지조건에 해당하는 아이디의 배열을 찾아냈다면
                sort(tmp.begin(), tmp.end()); // 중복값제거를 위한 순서정렬
                for(auto a : tmp){
                    Id += a;
                }
                s.insert(Id);
            }
            
        }
        
    }while(next_permutation(id.begin(), id.end()));
    
    return s.size();
}