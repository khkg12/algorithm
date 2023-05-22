#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string a, string b){
    string str = a + b;
    string str2 = b + a;
    int first = stoi(str);
    int second = stoi(str2);    
    return first > second;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    for(int i = 0; i < numbers.size(); i++){
        string s = to_string(numbers[i]);
        str.push_back(s);
    }
    
    sort(str.begin(), str.end(), greater<>());
    sort(str.begin(), str.end(), cmp);
    for(int i = 0; i < str.size(); i++){        
        answer += str[i];
    }
    if(str[0] == "0") return "0";
    return answer;
}