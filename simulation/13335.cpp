#include <iostream>
#include <deque>

using namespace std;

int n,w,l;
int trucks[1001];

// 한칸씩 밀어야된다 ? deque 써서 뒤에거 빼고 앞에 0 채우기
int main(){
    cin>>n>>w>>l; //w: 다리 길이, l: 최대 하중
    for(int i=0; i<n; i++){
        cin>>trucks[i];
    }

    deque<int> dq(w,0); // dq길이는 항상 w로 유지
    int idx=0;
    int total_weight=0;
    int cnt = 0;
    while(true){
        if(idx==n && total_weight==0){ // 트럭을 다 다리로 보내고 다리 무게도 0이면 다 끝난거임
            cout<<cnt;
            break;
        }

        total_weight -= dq[w-1]; dq.pop_back();
        dq.push_front(0);


        if(idx<n && total_weight+trucks[idx]<=l){
            dq[0] = trucks[idx++];
            total_weight += dq[0];
        }
        cnt++;
    }


    return 0;
}