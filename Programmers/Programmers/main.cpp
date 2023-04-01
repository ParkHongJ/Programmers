#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>
#pragma warning(disable :4996)
using namespace std;

int T, M;
int main()
{
    freopen("input.txt", "r", stdin);

    cin >> T;

    int A = 300;
    int B = 60;
    int C = 10;
    
    int iCountA = 0;
    int iCountB = 0;
    int iCountC = 0;
    while (T != 0)
    {
        if (T / A > 0)
        {
            T -= A;
            iCountA++;
            continue;
        }

        if (T / B > 0)
        {
            T -= B;
            iCountB++;
            continue;
        }

        if (T / C > 0)
        {
            T -= C;
            iCountC++;
            continue;
        }

        cout << -1 << endl;
        return 0;
        break;
    }

    cout << iCountA << " " << iCountB << " " << iCountC << endl;
    getch();
    return 0;
}