//
//  stringtoint.cpp
//  Programmers
//
//  Created by 임수정 on 2021/02/07.
//
//https://sio2whocode.tistory.com/73
//https://programmers.co.kr/learn/courses/30/lessons/12925

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool isMinus = false;
    int i = 0;
    if(s[0] == '-'){
        isMinus = true;
        i++;
    }else if(s[0] == '+'){
        i++;
    }
    for(; i < s.length() ; i++){
        answer *= 10;
        answer += s[i]-'0';
    }
    if(isMinus){
        answer *= -1;
    }
    return answer;
}
