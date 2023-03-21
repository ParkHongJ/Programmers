#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;

    //안전지대의 인덱스
    set<int> BoomIndex;

    int iMaxSize = board.size() * board.size();
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            //지뢰라면.
            if (board[i][j] == 1)
			{
				BoomIndex.insert(i * board[i].size() + j);

                //왼쪽이 있다면.
                if (j - 1 >= 0)
                {
                    BoomIndex.insert(i * board[i].size() + (j - 1));
                    
                    //좌상
                    if (i - 1 >= 0)
                    {
                        BoomIndex.insert((i - 1) * board[i].size() + (j - 1));
                    }
                    //좌하
                    if (i + 1 < board.size())
                    {
                        BoomIndex.insert((i + 1) * board[i].size() + (j - 1));
                    }
                }
                //오른쪽
                if (j + 1 < board[i].size())
                {
                    BoomIndex.insert(i * board[i].size() + (j + 1));
                    //우상
                    if (i - 1 >= 0)
                    {
                        BoomIndex.insert((i - 1) * board[i].size() + (j + 1));
                    }
                    //우하
                    if (i + 1 < board.size())
                    {
                        BoomIndex.insert((i + 1) * board[i].size() + (j + 1));
                    }
                }
                //상
                if (i - 1 >= 0)
                {
                    BoomIndex.insert((i - 1) * board[i].size() + j);
                }
                //하
                if (i + 1 < board.size() )
                {
                    BoomIndex.insert((i + 1) * board[i].size() + j);
                }
            }
        }
    }
    return iMaxSize - BoomIndex.size();
}

int main()
{
    vector<vector<int>> common = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    cout << solution(common) << endl;
    return 0;
}