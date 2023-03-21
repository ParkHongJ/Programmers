#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
       
    int iLast = people.size() - 1;
    
    int iBoatSize = 0;
    int iBegin = 0;
    int iTemp = 0;
    int iFailCount = 0;
    while (iBegin < iLast)
    {
        //보트에 실패하면
        if (people[iBegin] + people[iLast] > limit)
        {
            iLast--;
            iFailCount++;
        }
        else
        {
            //보트 성공
            iBoatSize++;

            iLast--;
            iBegin++;
            if (iLast == iBegin)
            {
                iBoatSize++;
                break;
            }


        }
    }

    /*if ((people.size() % 2) != 0)
    {
        iBoatSize++;
    }*/
    /*else if ((isBoatSize != people.size() / 2) && (iFailCount > 0))
    {
        iBoatSize++;
    }*/

    iBoatSize += iFailCount;
    return  iBoatSize;
}

int main()
{
    vector<int> people = { 70, 80, 50 };
    cout << solution(people, 100) << endl;
    return 0;
}