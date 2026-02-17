#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;

int n, ret;

int arr[21][21];
void push(int _arr[21][21])
{
    int temp[21][21];
    memset(temp, 0, sizeof(temp));

    for (int i = 0; i < n; i++)
    {
        int pos = 0;
        for (int j = 0; j < n; j++)
        {
            if (_arr[i][j] == 0) continue;
            if (temp[i][pos] == 0) {
                temp[i][pos] = _arr[i][j];
                //pos++;
            }
            else if (temp[i][pos] == _arr[i][j])
            {
                temp[i][pos] *= 2;
                pos++;
            }
            else {
                pos++;
                temp[i][pos] = _arr[i][j];
            }
        }
    }
    memcpy(_arr, temp, sizeof(temp));

}
void rotate_arr(int _arr[21][21])
{
    int temp[21][21];
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = _arr[n - j - 1][i];
        }
    }

    memcpy(_arr, temp, sizeof(temp));
}

void go(int idx, int _arr[21][21])
{
    if (idx == 5)
    {
        //check
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ret = max(ret, _arr[i][j]);
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int temp[21][21];
        memcpy(temp, _arr, sizeof(temp));
        push(temp);
        go(idx + 1, temp);
        rotate_arr(_arr);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    go(0, arr);
    cout << ret << '\n';
}

