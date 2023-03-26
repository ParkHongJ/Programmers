#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;

    stack<int> Boxes;
    
    for (int i = order.size(); i > 0; i--)
    {
        Boxes.push(i);
    }

    stack<int> TempContainer;
    
    for (int i = 0; i < order.size(); i++)
    {
        while (true)
        {
            if (!TempContainer.empty())
            {
                if (TempContainer.top() == order[i])
                {
                    TempContainer.pop();
                    answer++;
                    break;
                }
            }

            if (Boxes.empty())
            {
                return answer;
            }
            else if (order[i] == Boxes.top())
            {
                Boxes.pop();
                answer++;
                break;
            }
            else
            {
                TempContainer.push(Boxes.top());
                Boxes.pop();
            }
        }
    }

    return answer;
}

int main()
{
    //vector<int> order = { 4,3,1,2,5 };
    vector<int> order = { 2, 1, 6, 7, 5, 8, 4, 9, 3, 10 };
    cout << solution(order) << endl;
    return 0;
}