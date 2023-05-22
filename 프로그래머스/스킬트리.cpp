#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> trees) {
int answer = 0;
int size = trees.size();

    for(int i = 0; i < size; i++){
        string s = trees[i];
        int s_size = s.size();
        string str;
        for(int j = 0; j < s_size; j++){
            if(skill.find(s[j]) != string::npos){ // skill의 값이 s에 존재하면
                str.push_back(s[j]);
            }
        }
        bool check = true;
        for(int j = 0; j < str.size(); j++){
            if(skill[j] != str[j]){
                check = false;
                break;
            }
        }
        if(check == true) answer++;
    }

    return answer;

}
