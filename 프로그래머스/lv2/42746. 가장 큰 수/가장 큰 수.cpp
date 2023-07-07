#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string a, string b){
    return stoi(a + b) > stoi(b + a);
}

string solution(vector<int> num) {
    string answer = "";
    vector<string> v; 
    
    for(auto i : num){
        v.push_back(to_string(i));        
    }
    
    sort(v.begin(), v.end(), cmp);     
    
    if(v[0] == "0") return "0";
    
    for(int i = 0; i < v.size(); i++){                    
        answer += v[i];        
    }

    
    return answer;
}