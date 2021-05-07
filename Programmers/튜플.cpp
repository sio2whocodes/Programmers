//
//  튜플.cpp
//  Programmers
//
//  Created by 임수정 on 2021/05/04.
//
//https://sio2whocode.tistory.com/113
//https://programmers.co.kr/learn/courses/30/lessons/64065?language=cpp

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a.size() < b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<int> in;
    vector<vector<int>> large;
    int num = 0;
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '{'){
            in.clear();
        }else if (s[i] == '}'){
            in.push_back(num);
            num = 0;
            large.push_back(in);
            i++;
        }else if(s[i] == ','){
            in.push_back(num);
            num = 0;
        }else{
            num = num*10 + s[i]-'0';
        }
    }
    sort(large.begin(), large.end(), cmp);
    for(int i = 0 ; i < large.size() ; i++){
        for(int j = 0 ; j < large[i].size() ; j++){
            int n = large[i][j];
            if(find(answer.begin(), answer.end(), n) == answer.end()){
                answer.push_back(n);
            }
        }
    }
    return answer;
}
