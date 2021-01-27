//
//  ternary.cpp
//  Programmers
//
//  Created by 임수정 on 2021/01/27.
//

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v = vector<int>();
    while(n!=0){
        v.push_back(n%3);
        n /= 3;
    }
    int mul = 1;
    while(!v.empty()){
        answer += v.back()*mul;
        v.pop_back();
        mul*= 3;
    }
    return answer;
}
