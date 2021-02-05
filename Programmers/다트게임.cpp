//
//  다트게임.cpp
//  Programmers
//
//  Created by 임수정 on 2021/02/04.
//
//https://programmers.co.kr/learn/courses/30/lessons/17682
//https://sio2whocode.tistory.com/81

#include <string>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int beforeScore = 0;
    int score = 0;
    int bonus;
    for(int i = 0 ; i < dartResult.size() ; i++){
        //숫자일때
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            if(dartResult[i] == '1' && dartResult[i+1] == '0'){
                score = 10;
                i++;
            }else{
                score = dartResult[i]-'0';
            }
        }
        //보너스
        else if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T'){
            switch (dartResult[i]){
                case 'S':
                    bonus = 1;
                    break;
                case 'D':
                    bonus = 2;
                    break;
                case 'T':
                    bonus = 3;
                    break;
                default:
                    break;
            }
            int s = score;
            while(bonus-- > 1){
                score *= s;
            }
            //보너스가 마지막일 때
            if((dartResult[i+1] >= '0' && dartResult[i+1] <= '9') || i==dartResult.size()-1){
                answer += score;
                beforeScore = score;
            }
        }
        //옵션
        else{
            if(dartResult[i] == '*'){
                score = score*2;
                answer += beforeScore + score;
                beforeScore = score;
            }else if(dartResult[i] == '#'){
                score *= -1;
                answer += score;
                beforeScore = score;
            }
        }
    }
    
    return answer;
}
