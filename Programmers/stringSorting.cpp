//
//  stringSorting.cpp
//  Programmers
//
//  Created by 임수정 on 2021/01/30.
//

#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int m;
bool mycompare(string s1, string s2){
    if(s1[m] == s2[m]){
        return s1.compare(s2) < 0 ;
    }else{
        return s1[m]<s2[m];
    }
}
vector<string> solution(vector<string> strings, int n) {
    m = n;
    vector<string> answer = strings;
    sort(answer.begin(), answer.end(), mycompare);
    return answer;
}
