#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool SecondCmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

bool FirstCmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    map<string, vector<pair<int, int>>> m2;

    for (int i = 0; i < genres.size(); i++) {
        m[genres[i]] += plays[i];
        m2[genres[i]].push_back({ i, plays[i] });
    }

    vector<pair<string, int>> v(m.begin(), m.end()); // v에 맵값들을 저장하고(정렬을 위한 벡터로 이동)
    sort(v.begin(), v.end(), FirstCmp);


    for (int i = 0; i < v.size(); i++) {
        int cnt = 2;
        sort(m2[v[i].first].begin(), m2[v[i].first].end(), SecondCmp);
        if (m2[v[i].first].size() == 1) cnt = 1;
        for (int j = 0; j < cnt; j++) {
            cout << m2[v[i].first][j].second << " ";
            answer.push_back(m2[v[i].first][j].first);
        }
    }

    return answer;
}