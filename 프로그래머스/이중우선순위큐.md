#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(int i = 0; i < operations.size(); i++){
        string cmd = operations[i].substr(0,1);
        int num = stoi(operations[i].substr(2));
        if(cmd == "I"){
            answer.push_back(num);
            sort(answer.begin(), answer.end(), greater<>());            
        }
        else{
            if(!answer.empty() && num == 1) answer.erase(answer.begin());
            else if(!answer.empty() && num == -1) answer.pop_back();
        }
    }    
    if(answer.size() == 0) return {0,0};
    else return {answer[0], answer[answer.size()-1]};
};