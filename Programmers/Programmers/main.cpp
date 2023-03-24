#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
	int answer = 0;
	string Data;
	Data.reserve(ingredient.size());

	for (auto& iter : ingredient)
	{
		Data += to_string(iter);
	}
	
	int i = 0;
	int j = 8;
	
	while (true)
	{
		string str = Data.substr(i, i + j);

		int num = str.find("1231");

		if (num != -1)
		{
			Data.erase(Data.begin() + num, Data.begin() + num + 4);

			answer++;
			i = 0;
			j = i + 8;
		}
		else
		{
			i++;
			j++;
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
	vector<int> test = { 1, 2, 3, 1, 
		2, 3, 1, 1, 1, 
		1, 2, 3, 1, 
		2, 3, 1, 
		1, 1, 1, 1, 1, 2, 3, 3, 
		1, 2, 3, 1, 
		3, 3, 3, 2, 
		1, 2, 3, 1 };
	cout << solution(test) << endl;
    return 0;
}