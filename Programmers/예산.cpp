//
//  예산.cpp
//  Programmers
//
//  Created by 임수정 on 2021/02/04.
//
//https://programmers.co.kr/learn/courses/30/lessons/12982
//https://sio2whocode.tistory.com/80

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    int cnt = 0;
    while(budget>=0 && cnt <= d.size()){
        budget-=d[cnt++];
    }
    answer = cnt-1;
    return answer;
}
