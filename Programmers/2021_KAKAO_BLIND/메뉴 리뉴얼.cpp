//
//  메뉴 리뉴얼.cpp
//  Programmers
//
//  Created by 임수정 on 2021/12/08.
//
//https://sio2whocode.tistory.com/157
//https://programmers.co.kr/learn/courses/30/lessons/72411

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int numOfMenu : course){
        map<string, int> crsFreq;
        int maxFreq = 2;
        
        for(string order : orders){
            
            long n = order.length();
            int k = numOfMenu;
            if(n < k) continue;
            
            vector<int> combi(n-k, 0);
            for(int i = 0 ; i < k ; i++)
                combi.push_back(1);
            
            do {
                string setMenu;
                for(int i = 0 ; i < n ; i++){
                    if(combi[i] == 1)
                        setMenu += order[i];
                }
                sort(setMenu.begin(), setMenu.end());
                crsFreq[setMenu] += 1;
                maxFreq = max(crsFreq[setMenu], maxFreq);
            } while (next_permutation(combi.begin(), combi.end()));
        }
        
        
        
        for (pair<string, int> crs : crsFreq){
            if (crs.second == maxFreq)
                answer.push_back(crs.first);
        }
        sort(answer.begin(), answer.end());
    }
    return answer;
}

