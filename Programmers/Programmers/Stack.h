#pragma once
template <typename T>
class CStack
{
public:
	CStack();
	~CStack();

public:
	void Pop();
	void Push(T data);
	void Push(T&& data);
	T top();
	int Size();

private:
	int m_iSize;
	int m_iTop;
	class Node* m_pNode;
};

