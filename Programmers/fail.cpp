//
//  fail.cpp
//  Programmers
//
//  Created by 임수정 on 2021/02/03.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(pair<int,double> a, pair<int,double> b){
    if(a.second > b.second){
        return true;
    }else if(a.second == b.second){
        return a.first < b.first;
    }else{
        return false;
    }
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,double>> rateOfFail;
    for(int j = 1 ; j <= N ; j++){
        int fail = 0;
        int ch = 0;
        for(int i = 0 ; i < stages.size() ; i++){
            if(stages[i] > j){
                ch++;
            }else if(stages[i] == j){
                fail++;
                ch++;
            }
        }
        double failure = ch==0 ? 0 : double(double(fail)/ch) ;
        rateOfFail.push_back(make_pair(j,failure));
    }
    sort(rateOfFail.begin(), rateOfFail.end(), cmp);
    for(int i = 0 ; i < N ; i++){
        answer.push_back(rateOfFail[i].first);
    }
    return answer;
}
