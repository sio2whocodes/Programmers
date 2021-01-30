//
//  caesarCipher.cpp
//  Programmers
//
//  Created by 임수정 on 2021/01/30.
//

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == ' '){
            answer += ' ';
        }else if(s[i] >= 'A' && s[i] <= 'Z'){
            answer += 'A'+(s[i]+n-'A')%26;
        }else{
            answer += 'a'+(s[i]+n-'a')%26;
        }
    }
    return answer;
}
