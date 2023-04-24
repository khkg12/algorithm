#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>


using namespace std;

bool possi(vector<int> vec,int now){
    for(int i = 0; i < vec.size(); i++)
        // ans에 있던 조합이 이번에 들어온 조합이랑 같은 것인지 확인
        if((vec[i] & now) == vec[i]) //ans에 후보키인 1이 있는 상태에서(학번), 3, 즉11(학번,이름)을 비교할 때 and계산시
            //1이 ans안에 이미 있으므로 11은 후보키에 등록해선 안됨
            return false;

    return true;
}

int solution(vector<vector<string>> relation) {
    int rowSize = (int)relation.size(); 
    int colSize = (int)relation[0].size();
    vector<int> ans;

    // 조합 경우의 수
    /*
     1(0001) - 학번
     2(0010) - 이름
     3(0011) - 이름, 학번
     4(0100) - 전공
     5(0101) - 학번, 전공
     6(0110) - 이름, 전공
     7(0111) - 학번, 이름, 전공
     8(1000) - 학년
     9(1001) - 학번, 학년
     10(1010) - 이름, 학년
     11(1011) - 학번, 이름, 학년
     12(1100) - 이름, 학번
     13(1101) - 학번, 전공, 학년
     14(1110) - 이름, 전공, 학년
     15(1111) - 학번, 이름, 전공, 학년
     */
    
    for(int i = 1; i < (1<<6); i++){ // 1을 왼쪽으로 6비트만큼 이동, 즉 10(1비트)100(2비트)..1000000(6비트이동) 
    // 즉 1부터 64이전까지의 모든 경우의 수 for문        
    }
    
    for(int i = 1; i < (1<<colSize); i++){ // colSize는 속성 종류갯수(학번,이름,전공,학년)이므로 4개의 순열을구하기 위해 속성종류갯수만큼 비트를 이동시킴 -> 10000(=16) 위 확인
        set<string> s; //        

        for(int j = 0; j < rowSize; j++){
            string now = "";

            for(int k = 0; k < colSize; k++){
                  // 선택된 컬럼과 일치한다면
                if(i & (1<<k)) // i가 3이면 0011, 1<<k에서 k가 0이면 1 둘이 and연산으로 첫째자리가 일치하기 때문에 그 값을 now값에 넣어줌
                    now += relation[j][k]; // i가 3이면 100ryan, 200apeech이런식으로 set에 저장이 될건데 이 때 중복되는 값이 있다면 유일성을 보장하지 못해서 후보키가아님, 즉 중복이되지않으면서 
            }            
            s.insert(now);
        }

        // s.size() == rowSize => 중복체크
        if(s.size() == rowSize && possi(ans,i))
            ans.push_back(i);
    }

    return (int)ans.size();
}