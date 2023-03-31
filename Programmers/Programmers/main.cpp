#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>
#pragma warning(disable :4996)
using namespace std;

int N, M;
int main()
{
    freopen("input.txt", "r", stdin);

    vector<int> arr;
    vector<int> arr2;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a; 
        arr.push_back(a);
    }
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        arr2.push_back(a);
    }

    sort(arr.rbegin(), arr.rend());

    vector<int> Temp = arr2;
    sort(Temp.begin(), Temp.end());
    //A의 가장큰수는 B의 가장 작은수와 곱해져야함.

    int iResult = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            int k = Temp[i];

            while(j < arr2.size())
            {
                if (k == arr2[j])
                {
                    iResult += arr2[j] * arr[i];
                    arr2.erase(arr2.begin() + j);
                    break;
                }
                else
                {
                    j++;
                    continue;
                }
            }
            break;
        }
    }

    cout << iResult << endl;
    getch();
    return 0;
}