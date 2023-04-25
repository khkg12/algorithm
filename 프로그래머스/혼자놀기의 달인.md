#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> cards) {
    vector<int> answer;
    int Max_num = -1;
    bool check[101] = {false,};
    for(int i = 0; i < cards.size(); i++) cards[i]--; 
    
    for(int i = 0; i < cards.size(); i++){ // 카드 수 8개라면 8개의 모든 선택지 선택
        set<int> s;
        int idx = i;        
        int size = -1;
        while(s.size() != size){ // set에 원소들 설정
            size = s.size();
            s.insert(idx);             
            idx = cards[idx];                            
        }
        if(check[i] == false) answer.push_back((int)s.size()); // 아직 사용되지 않은, 즉 선택되지않은 인덱스라면
        for(auto ss : s){ // 만약 1,4,7,8이 그룹으로 속해진다면 4를 선택하든 7을 선택하든 이미 같은 그룹이므로 선택되지못하게 bool로 체크
            check[ss] = true;
        }        
    }
    sort(answer.begin(), answer.end(), greater<>());
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    if(answer.size()==1) return 0;
    return answer[0]*answer[1];
}