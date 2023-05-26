#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;    
    sort(routes.begin(), routes.end());
    int temp = routes[0][1];    
    for(int i = 0; i < routes.size(); i++){
        if(routes[i][0] > temp){
            answer++;
            temp = routes[i][1];
        }
        if(temp >= routes[i][1]) temp = routes[i][1]; // 앞에 차가 -15에 뒤에차가 -16이면
                                                      // -16으로 기준이, 즉 temp가 변해야함
        
    }
    
    return answer;
}