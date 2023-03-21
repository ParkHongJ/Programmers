#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> common) {
    int iSize = common.size();

    int iTemp = 0;
    for (int i = 0; i < iSize - 1; i++)
    {
        int j = i + 1;
        int result = common[j] - common[i];

        //공차를 찾았다면
        if (result == iTemp)
        {
            //등차라면
            if ((common[i] + result) == common[j])
            {
                return common.back() + result;
            }
        }
        else
        {
            //등비라면
            if (((common[i] * result) == common[j]) && (result != 0))
            {
                return common.back() * result;
            }
            else if (((common[i] * -result) == common[j]) && (result != 0))
            {
                return common.back() * -result;
            }

            if ((i != 0) && (iTemp != result))
            {
                int result2 = common[j] / common[i];
                if (((common[i] * result2) == common[j]) && (result2 != 0))
                {
                    return common.back() * result2;
                }
            }
            else
            {
                iTemp = result;
            }
        }
    }
}
int main()
{
    vector<int> common = { -10,-30,-50,-70 };
    vector<int> common2 = { 1,-2,4,-8 };
    cout << solution(common2) << endl;
    return 0;
}