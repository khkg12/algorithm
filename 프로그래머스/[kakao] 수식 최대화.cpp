#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<char> sign;
vector<long long> v;

void func(string s){
    string tmp = "";
    for(int i = 0; i < s.size(); i++){        
        if(s[i] >= '0' && s[i] <= '9') tmp.push_back(s[i]);
        else{
            sign.push_back(s[i]);
            v.push_back(stoll(tmp));
            tmp = "";
        }
    }
    v.push_back(stoll(tmp));
}

long long solution(string expression) {
    long long answer = 0;
    func(expression);    
    vector<char> str;
    bool check1 = false, check2 = false, check3 = false; 
    for(int i = 0; i < expression.size(); i++){
        if(expression[i] == '*' && check1 == false) str.push_back('*'), check1 = true;
        else if(expression[i] == '+' && check2 == false) str.push_back('+'), check2 = true;
        else if(expression[i] == '-' && check3 == false) str.push_back('-'), check3 = true;
    }
    
    sort(str.begin(), str.end());
    
    do{
        vector<char> sign_tmp = sign;
        vector<long long> v_tmp = v;        
        for(int i = 0; i < str.size(); i++){
            for(int j = 0; j < sign_tmp.size(); j++){
                if(str[i] == sign_tmp[j]){
                    if(str[i] == '+') v_tmp[j] = v_tmp[j] + v_tmp[j+1];
                    else if(str[i] == '-') v_tmp[j] = v_tmp[j] - v_tmp[j+1];
                    else if(str[i] == '*') v_tmp[j] = v_tmp[j] * v_tmp[j+1];
                    v_tmp.erase(v_tmp.begin() + j + 1);
                    sign_tmp.erase(sign_tmp.begin() + j);
                    j--; // 위에서 하나를 지우기 때문에 j--를 해줘야 다시채워진 값을 점검
                }
            }
        }
        if(answer < abs(v_tmp[0])) answer = abs(v_tmp[0]);
        
    }while(next_permutation(str.begin(), str.end()));
    
    return answer;
}