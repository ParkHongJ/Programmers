#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<vector<int>> lines) {
	int answer = 0;

	set<vector<int>> test;//��ø�� ������ ����
	
	for (int i = 0; i < lines.size(); i++)
	{
		for (int j = 0; j < lines.size(); j++)
		{
			if (lines[i] == lines[j])
			{
				continue;
			}

			//������ ���ƴ�
			if (lines[i][0] <= lines[j][0] &&
				lines[i][1] > lines[j][0])
			{
				int x = lines[j][0];
				int y = 0;

				if (lines[i][1] <= lines[j][1])
				{
					y = lines[i][1];
				}
				else
				{
					y = lines[j][1];
				}
				vector<int> Points = { x,y };
				test.insert(Points);
			}
		}
	}

	int iX = 0;
	int iY = 0;
	for (auto& iter : test)
	{
		for (auto& iter2 : test)
		{
			if (iter == iter2)
			{
				continue;
			}

			//�ǰɷȴ�
			if (iter[0] <= iter2[0] &&
				iter[1] > iter2[0])
			{
				int x = iter2[0];
				int y = 0;

				if (iter[1] <= iter2[1])
				{
					y = iter[1];
				}
				else
				{
					y = iter2[1];
				}
			}
		}
	}

	return answer;
}

//typedef char ElementType;
//typedef struct tagLCRSNode
//{
//	struct tagLCRSNode* LeftChild;
//	struct tagLCRSNode* RightSibling;
//	
//	ElementType Data;
//}LCRSNode;
//
//LCRSNode* LCRS_CreateNode(ElementType NewData)
//{
//	LCRSNode* NewNode = new LCRSNode;
//	NewNode->LeftChild = nullptr;
//	NewNode->RightSibling = nullptr;
//	NewNode->Data = NewData;
//
//	return NewNode;
//}
//void LCRS_DestroyNode(LCRSNode* Node)
//{
//	delete Node;
//}
//void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child)
//{
//	//�θ��� �����ڽ��� ���ٸ� �ٷ� �ڽ����� ����Ѵ�.
//	if (Parent->LeftChild == nullptr)
//	{
//		Parent->LeftChild = Child;
//	}
//	else
//	{
//		//���� �ڽ��� �ִٸ�
//		LCRSNode* TempNode = Parent->LeftChild;
//
//		//������ �ڽ��� ���Ž��
//		while (TempNode->RightSibling != nullptr)
//		{
//			TempNode = TempNode->RightSibling;
//		}
//		TempNode->RightSibling = Child;
//	}
//}
//
//void LCRS_PrintTree(LCRSNode* Node, int Depth)
//{
//	// �鿩����
//	int i = 0;
//	for (i = 0; i < Depth - 1; i++)
//	{
//		cout << "   ";
//	}
//	if (Depth > 0)  // �ڽĳ�� ���� ǥ��
//	{
//		cout << "+--";
//	}
//
//	cout << Node->Data << endl;
//
//	if (Node->LeftChild != nullptr)
//	{
//		LCRS_PrintTree(Node->LeftChild, Depth + 1);
//	}
//	if (Node->RightSibling != nullptr)
//	{
//		LCRS_PrintTree(Node->RightSibling, Depth);
//	}
//}
//class Person {
//public:
//	static int a;
//	int m_identity = 0;
//public:
//	Person(int identity) {
//		this->m_identity = identity;
//		cout << m_identity << "����" << endl; 
//	}
//	Person(const Person& p) { 
//		m_identity = p.m_identity; 
//		cout << m_identity << "�������" << endl;
//	}
//	~Person() { cout << m_identity << "�Ҹ�" << endl; }
//	Person& operator=(const Person& pp)
//	{
//		cout << "����" << endl;
//		return *this;
//	}
//};
//int Person::a = 0;
int main()
{
	vector<vector<int>> test = { {0, 5} ,{3, 9},{1, 10}};
	cout << solution(test) << endl;
    return 0;
}