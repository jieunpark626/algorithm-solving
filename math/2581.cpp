#include <iostream>

using namespace std;

int N,M;
bool isNotPrime[10000+3];

void makePrime(){
    isNotPrime[1] = true;
    for(int i=2; i*i<=M; i++){
        // 소수의 배수는 소수가 아니다.
        if(isNotPrime[i]==false){
            for(int j=i*i; j<=M; j+=i){
                isNotPrime[j] = true;
            }
        }
    }
}

int main(){
    cin>>N>>M;

    makePrime();

    int sum=0, min=100000;
    for(int i=N; i<=M; i++){
        if(isNotPrime[i]==false){
            sum+=i; 
            if(min>i) min=i;
        }
    }

    if(sum==0){
        cout<<-1;
    }else{
        cout<<sum<<"\n"<<min;
    }
    return 0;
}