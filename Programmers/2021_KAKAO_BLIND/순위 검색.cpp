//
//  순위 검색 찐.cpp
//  Programmers
//
//  Created by 임수정 on 2021/12/11.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;
unordered_map<string, vector<int>> infoMap;
string token;

void getInfoMap(vector<vector<string>> infoTokens){
    for(vector<string> aInfo : infoTokens){
        // 한 사람에 대한 정보
        int score = stoi(aInfo[4]);
        infoMap["----"].push_back(score);
        infoMap[aInfo[0] + aInfo[1] + aInfo[2] + aInfo[3]].push_back(score);
        
        // - 개수별 문자열 순열 구하기
        for(int k = 1 ; k <= 3 ; k++){
            vector<int> permu(4-k, 0);
            for(int i = 0 ; i < k ; i++){
                permu.push_back(1);
            }
            
            do {
                // 하나의 문자열 완성
                string infoCase = "";
                for(int i = 0 ; i < 4 ; i++){
                    if(permu[i] == 1){
                        infoCase += aInfo[i];
                    }else{
                        infoCase += '-';
                    }
                }
                infoMap[infoCase].push_back(score);
            } while(next_permutation(permu.begin(), permu.end()));
        }
    }
}

vector<vector<string>> getInfoVector(vector<string> info){
    vector<vector<string>> result(info.size());
    for(int i = 0 ; i < info.size() ; i++){
        //한명 정보 정리
        istringstream iss(info.at(i));
        while(getline(iss, token, ' ')){
            result[i].push_back(token);
        }
    }
    return result;
}

vector<vector<string>> getQueryVector(vector<string> query){
    vector<vector<string>> result(query.size());
    for(int i = 0 ; i < query.size() ; i++){
        //쿼리 하나 정보 정리
        istringstream iss(query.at(i));
        while(getline(iss, token, ' '))
            result[i].push_back(token);
    }
    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> realInfo = getInfoVector(info);
    vector<vector<string>> realQuery = getQueryVector(query);
    getInfoMap(realInfo);
    
    for(auto &m : infoMap){
        sort(m.second.begin(), m.second.end());
    }
        
    for(vector<string> q : realQuery){
        int minScore = stoi(q[7]);
        vector<int> candi = infoMap[q[0]+q[2]+q[4]+q[6]];
        int startIdx = int(lower_bound(candi.begin(), candi.end(), minScore) - candi.begin());
        answer.push_back(int(candi.size()) - startIdx);
    }
    
    
    return answer;
}

int main(){
    
}
