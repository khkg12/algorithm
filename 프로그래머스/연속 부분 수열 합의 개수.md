#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<int> elements) {
int answer = 0;
vector<int> copy;
set<int> set;
copy = elements;
for(int i = 0; i < copy.size(); i++){
elements.push_back(copy[i]);
}

    for(int i = 0; i < copy.size(); i++){
        int sum = 0;
        int idx = i;
        for(int j = 0; j < copy.size(); j++){
            sum += elements[++idx];
            set.insert(sum);
        }
    }
    answer = set.size();
    return answer;

}
