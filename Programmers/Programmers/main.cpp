#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;

    //���������� �ε���
    set<int> BoomIndex;

    int iMaxSize = board.size() * board.size();
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            //���ڶ��.
            if (board[i][j] == 1)
			{
				BoomIndex.insert(i * board[i].size() + j);

                //������ �ִٸ�.
                if (j - 1 >= 0)
                {
                    BoomIndex.insert(i * board[i].size() + (j - 1));
                    
                    //�»�
                    if (i - 1 >= 0)
                    {
                        BoomIndex.insert((i - 1) * board[i].size() + (j - 1));
                    }
                    //����
                    if (i + 1 < board.size())
                    {
                        BoomIndex.insert((i + 1) * board[i].size() + (j - 1));
                    }
                }
                //������
                if (j + 1 < board[i].size())
                {
                    BoomIndex.insert(i * board[i].size() + (j + 1));
                    //���
                    if (i - 1 >= 0)
                    {
                        BoomIndex.insert((i - 1) * board[i].size() + (j + 1));
                    }
                    //����
                    if (i + 1 < board.size())
                    {
                        BoomIndex.insert((i + 1) * board[i].size() + (j + 1));
                    }
                }
                //��
                if (i - 1 >= 0)
                {
                    BoomIndex.insert((i - 1) * board[i].size() + j);
                }
                //��
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