//
//  main.cpp
//  Programmers
//
//  Created by 임수정 on 2021/01/25.
//
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for(int i = 0 ; i < new_id.length() ; i++){
        if(new_id[i] >= 65 && new_id[i] <= 90){
            answer += tolower(new_id[i]);
            continue;
        }
        if((new_id[i] >= 48 && new_id[i] <= 57)||(new_id[i] >= 96 && new_id[i] <= 122) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            answer += new_id[i];
        }
    }
    int cnt = 0;
    for(int i = 0 ; i < answer.length() ; i++){
        if(answer[i] == '.'){
            cnt++;
        }else{
            if(cnt > 1){
                answer.erase(i-cnt,cnt-1);
                i = i-(cnt-1);
                cnt = 0;
            }
            else if(cnt == 1){
                cnt = 0;
            }
        }
    }

    while(answer.front() == '.'){
        answer.erase(answer.begin());
    }
    while(answer.back() == '.'){
        answer.pop_back();
    }
    
    while(answer.length() > 15){
        answer.pop_back();
    }
    if(answer.back() == '.'){
        answer.pop_back();
    }
    while(answer.length() <= 2){
        if(answer.length() == 0){
            answer = "a";
        }
        answer += answer.back();
    }
    
    return answer;
}
