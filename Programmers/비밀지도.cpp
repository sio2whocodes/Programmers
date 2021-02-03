//
//  비밀지도.cpp
//  Programmers
//
//  Created by 임수정 on 2021/02/03.
//  https://programmers.co.kr/learn/courses/30/lessons/17681
//  https://sio2whocode.tistory.com/79

#include <string>
#include <vector>
using namespace std;
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0 ; i < n ; i++){
        arr1[i] = arr1[i]|arr2[i];
        string row = "";
        for(int j = 0 ; j < n ; j++){
            row = (arr1[i] % 2 == 0 ? " " : "#")+ row;
            arr1[i] = arr1[i] >> 1;
        }
        answer.push_back(row);
    }
    
    return answer;
}
