#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    int size = citations.size();
    sort(citations.begin(), citations.end());
    
    for(int i = 1; i <= size; i++){
        int cnt = 0;
        for(int j = 0; j < size; j++){            
            if(i <= citations[j]){
                cnt++;
            }
        }        
        if(cnt >= i && size - cnt <= i){ // 인용되지 않은 논문의 개수가 i, 즉 h이하여야함
            answer = max(answer, i);
        }
        cout << cnt << " ";
    }
    
    return answer;
}