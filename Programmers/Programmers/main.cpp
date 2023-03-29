#include <iostream>
#include <vector>
#include <conio.h>
#pragma warning(disable :4996)
using namespace std;

int N, M;
int main()
{
    freopen("input.txt", "r", stdin);

    vector<int> arr;
    cin >> N;
    cin >> M;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a; 
        arr.push_back(a);
    }

    int iCount = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (arr[i] > M)
        {
            continue;
        }

        while (arr[i] <= M)
        {
            M -= arr[i];
            iCount++;
        }
    }


    getch();
    return 0;
}