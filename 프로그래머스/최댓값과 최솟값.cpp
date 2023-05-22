#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <climits>
#include <iostream>

using namespace std;

string solution(string s) {
int min = INT_MAX;
int max = INT_MIN;
string answer = "";
istringstream iss(s);
char separator = ' ';
string str_buf;
while(getline(iss, str_buf, separator)){
int i = stoi(str_buf);
cout << i << " ";
if(max < i) max = i;
if(min > i) min = i;
}  
 answer += to_string(min);
answer += " ";
answer += to_string(max);
return answer;
}
