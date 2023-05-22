#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    sort(arrayA.begin(), arrayA.end(), less<>());
    sort(arrayB.begin(), arrayB.end(), less<>());
    
    int size = arrayA.size();        
    
    int a = arrayA[0];
    int b = arrayB[0];
    
    vector<int> a_num;
    vector<int> b_num;
    
    a_num.push_back(a);
    b_num.push_back(b);
    for(int i = 2; i <= sqrt(a); i++){
        if(a % i == 0){
            a_num.push_back(i);
            if(i != a / i) a_num.push_back(a / i); // a가 25이고 i가 5일경우 2개가 들어가면 안되므로 5 != 25 / 5 조건으로 방지
        }
    }
    
    for(int i = 2; i <= sqrt(b); i++){
        if(b % i == 0){
            b_num.push_back(i);
            if(i != b / i) b_num.push_back(b / i);
        }
    }
    
    int MaxA = 0, MaxB = 0;
    for(int i = 0; i < a_num.size(); i++){
        int aa = a_num[i];
        bool flag = false;
        for(int j = 0; j < size; j++){
            if(arrayA[j] % aa != 0 || arrayB[j] % aa == 0){
                flag = true;
                break;                
            }            
        }
        if(flag == false) MaxA = max(MaxA, aa);
    }
    
    for(int i = 0; i < b_num.size(); i++){
        int bb = b_num[i];
        bool flag = false;
        for(int j = 0; j < size; j++){
            if(arrayB[j] % bb != 0 || arrayA[j] % bb == 0){
                flag = true;
                break;                
            }
        }
        if(flag == false) MaxB = max(MaxB, bb);
    }            
    
    answer = max(MaxA, MaxB);
    return answer;
}