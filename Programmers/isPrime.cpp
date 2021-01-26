//
//  isPrime.cpp
//  Programmers
//
//  Created by 임수정 on 2021/01/26.
//

#include <string>
#include <vector>

using namespace std;

bool isPrime[1000001];
void updateIsPrime(int n,int end){
    for(int i = n*2 ; i <= end ; i += n){
        isPrime[i] = false;
    }
}
int solution(int n) {
    int answer = 0;
    //isPrime 배열 초기화
    for(int i = 2 ; i <= n ; i++ ){
        isPrime[i] = true;
    }
    for(int i = 2 ; i <= n/2 ; i++){
        if(!isPrime[i]){
            continue;
        }else{
            updateIsPrime(i,n);
        }
    }
    for(int i = 2 ; i <= n ; i++){
        if(isPrime[i]){
            answer++;
        }
    }
    return answer;
}
