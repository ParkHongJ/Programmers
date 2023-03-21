#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string Half = "";
    int iSize = 0;
    for (int i = 1; i < food.size(); i++)
    {
        int iHalf = food[i] % 2;

		//음식이 한개라면 버림
		if (food[i] == 1)
		{
			continue;
		}
		else
		{
			//음식은 배치할 수 있지만 홀수인 경우
            if (iHalf != 0)
            {
                food[i] -= 1;
            }
		}

        for (int j = 0; j < food[i] / 2; j++)
        {
            Half += to_string(i);
        }
    }
    answer += Half + "0";
    for (int i = Half.length() - 1; i >= 0; i--)
    {
        answer += Half[i];
    }
    return answer;
}

int main()
{
    vector<int> food = { 1, 7, 1, 2 };
    cout << solution(food) << endl;
    return 0;
}