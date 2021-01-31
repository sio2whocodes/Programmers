//
//  collatz.cpp
//  Programmers
//
//  Created by 임수정 on 2021/01/31.
//

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long n = num;
    int answer = 0;
    int cnt = 0;
    while(n!=1){
        if(cnt > 500){
            return -1;
        }
        if(n%2 == 0){
            n /= 2;
        }else{
            n = n*3 +1;
        }
        cnt++;
    }
    answer = cnt;
    return answer;
}
