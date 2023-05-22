#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool check(string p){
stack<char> s;
if(p == "") return true;
for(int i = 0; i < p.size(); i++){
if(p[i] == '('){
s.push('(');
}
else if(p[i] == ')' && !s.empty()){
s.pop();
}  
 }
if(s.empty()) return true;
else return false;
}

string dfs(string p){
string u = "", v = "";
int a=0, b=0;  
 if(check(p)) return p;
else{
for(int i = 0; i < p.size(); i++){
if(p[i] == '('){
u += p[i];
a++;
}
else if(p[i] == ')'){
u += p[i];
b++;
}  
 if(a == b){
v = p.substr(i + 1);  
 break;
}
}
cout << u << " ";
cout << check(u) << " ";
if(check(u)){ // 올바른 문자열이라면
u += dfs(v);
cout << u << " ";
return u;
}
else{
string ans;
ans.push_back('(');  
 ans += dfs(v);
ans.push_back(')');
u.erase(0,1);
int a = u.size()-1;
u.erase(a, 1);
for(int i = 0; i < u.size(); i++){
if(u[i] == '(') u[i] = ')';
else if(u[i] == ')') u[i] = '(';
}  
 ans += u;  
 return ans;
}
}  
}

string solution(string p) {
string answer = dfs(p);  
 return answer;
}
