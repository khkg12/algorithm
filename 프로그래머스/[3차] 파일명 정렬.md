#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int findNumIndex(const string& s){ // 값복사를 막기위함
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            return i;
        }
    }
}

int splitNum(string s) {return stoi(s.substr(findNumIndex(s)));}

string splitHead(string s) {    
    string num = s.substr(0, findNumIndex(s));
    transform(num.begin(), num.end(), num.begin(), ::tolower); // 소문자
    return num;
}

bool cmpHead(string a, string b){
    return splitNum(a) < splitNum(b); // 왼쪽이 남아있는 것이므로 내림차순 1, 2 3, 4,5 와 같은형태
}

bool cmpNum(string a, string b){
    return splitHead(a) < splitHead(b);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;        
    stable_sort(files.begin(), files.end(), cmpHead); // 정렬하기 전의 순서를 동일한 우선순위라면 유지
    stable_sort(files.begin(), files.end(), cmpNum);
    
        
    
    return files;
}