#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

bool priFunc(ll n){
int sqrt_n = sqrt(n);
int count = 0;
if(n == 1) return false;
for(int i = 2; i <= sqrt_n; i++){
if(n % i == 0) count++;
}
if(count > 0) return false;
else return true;
}

int solution(int n, int k) {
int answer = 0;
string s = "";
while(n){
s += (to_string)(n % k);  
 n /= k;
}
reverse(s.begin(), s.end());

    string priNum = "";
    vector<string> v;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0' && !priNum.empty()) {
            if(priFunc((stoll)(priNum))) v.push_back(priNum);
            priNum = "";
        }
        else if(s[i] != '0'){
            priNum.push_back(s[i]);
        }
    }

    if(!priNum.empty()) v.push_back(priNum);

    if(v.size() == 1){
        if(priFunc((stoll)(v[0]))) return 1;
        else return 0;
    }
    else{
        for(int i = 0; i < v.size(); i++){
            if(priFunc((stoll)(v[i]))) answer++;
        }
    return answer;
    }

}
