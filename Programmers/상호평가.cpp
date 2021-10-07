//
//  상호평가.cpp
//  Programmers
//
//  Created by 임수정 on 2021/10/07.
//

#include <string>
#include <vector>

using namespace std;

char getGrade(double avg){
    int dec = avg/10;
    switch (dec) {
        case 9: return 'A';
        case 8: return 'B';
        case 7: return 'C';
        case 6: case 5: return 'D';
        default: return 'F';
    }
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    size_t n = scores.size();
    
    for(int c = 0 ; c < n ; c++){
        //한 학생의 점수 구하기
        int sum = 0;
        double avg;
        bool isUnique = true;
        int min = scores[0][c];
        int max = scores[0][c];
        int self = scores[c][c];
        
        for(int r = 0 ; r < n ; r++){
            sum += scores[r][c];
            //본인이 준 점수와 같은 점수를 준 학생이 있는지 확인
            if(r != c && self == scores[r][c])
                isUnique = false;
            //최고점와 최저점 갱신
            if(min > scores[r][c])
                min = scores[r][c];
            if(max < scores[r][c])
                max = scores[r][c];
        }
        
        //본인이 본인에게 준 점수가 유일한 최고점or최저점일때
        if ((min == self || max == self) && isUnique) {
            sum -= self;
            avg = sum/(n-1);
        } else {
            avg = sum/n;
        }
        
        answer += getGrade(avg);
    }
    
    return answer;
}
