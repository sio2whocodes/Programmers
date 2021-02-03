//
//  press_keypad.cpp
//  Programmers
//
//  Created by 임수정 on 2021/02/01.
//

#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

map<int, vector<int>> position;
void positioning(){
    int cnt = 1;
    for(int r = 1 ; r <= 4 ; r++){
        for(int c = 1 ; c <= 3 ; c++){
            position[cnt++] = vector<int>{r,c};
        }
    }
    position[0] = vector<int>{4,2};
}
string solution(vector<int> numbers, string hand) {
    positioning();
    int currentL = 10;
    int currentR = 12;
    int distanceR, distanceL;
    string answer = "";
    for(int i = 0 ; i < numbers.size() ; i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            currentL = numbers[i];
        }else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            currentR = numbers[i];
        }else{
            distanceR = abs(position[currentR][0]-position[numbers[i]][0])+
                abs(position[currentR][1]-position[numbers[i]][1]);
            distanceL = abs(position[currentL][0]-position[numbers[i]][0])+
                abs(position[currentL][1]-position[numbers[i]][1]);
            if(distanceR > distanceL){
                answer += "L";
                currentL = numbers[i];
            }else if(distanceR < distanceL){
                answer += "R";
                currentR = numbers[i];
            }else{
                if(hand == "left"){
                    answer += "L";
                    currentL = numbers[i];
                }else{
                    answer += "R";
                    currentR = numbers[i];
                }
            }
        }
    }
    return answer;
}
