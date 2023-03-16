#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> v;
    set<int> num;
    for(int i = 0; i < numbers.size(); i++){
        v.push_back(numbers[i]);
    }
    sort(v.begin(), v.end());
    
    do{
        string tmp = "";
        for(int i = 0; i < v.size(); i++){
            tmp.push_back(v[i]);
            num.insert(stoi(tmp));
        }
    } while(next_permutation(v.begin(), v.end()));
    
    for(int i : num){  // set은 인덱스를 사용할 수 없다, 따라서 이런식으로 순회가능      
        if(isPrime(i)) answer++;
    }
    
    
    return answer;
}