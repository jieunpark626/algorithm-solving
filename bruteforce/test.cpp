#include <iostream>
#include <vector>

using namespace std;

int n, k;
int arr[10]; // 입력 숫자
vector<int> groups[10]; // 각 그룹에 담긴 숫자들

void printGroups() {
    for (int i = 0; i < k; i++) {
        cout << "Group " << i + 1 << ": ";
        for (int num : groups[i]) cout << num << " ";
        cout << endl;
    }
    cout << "----------------" << endl;
}

void solve(int idx) {
    // 모든 숫자를 다 배치했을 때
    if (idx == n) {
        // 모든 그룹이 적어도 하나의 숫자를 가지고 있는지 확인 (선택 사항)
        for (int i = 0; i < k; i++) {
            if (groups[i].empty()) return;
        }
        printGroups();
        return;
    }

    // 현재 숫자(arr[idx])를 k개의 그룹 중 하나에 배치
    for (int i = 0; i < k; i++) {
        groups[i].push_back(arr[idx]); // i번째 그룹에 추가
        solve(idx + 1);                // 다음 숫자로 진행
        groups[i].pop_back();          // 백트래킹: 원상복구

        // 중복 계산을 피하기 위한 최적화: 
        // 빈 그룹에 처음 숫자를 넣었다면, 다음 빈 그룹에 또 넣는 것은 무의미함
        if (groups[i].empty()) break;
    }
}

int main() {
    n = 3; k = 2;
    arr[0] = 1; arr[1] = 2; arr[2] = 3;

    solve(0);
    return 0;
}