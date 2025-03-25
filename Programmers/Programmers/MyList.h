#pragma once
#include <vector>

using namespace std;
class MyNode
{
public:
    MyNode* prev;
    int val;
    MyNode* next;

    MyNode(int val);
    MyNode(MyNode* prev, int val, MyNode* next);
};

/*
    ����� ���� ���Ḯ��Ʈ��. ���� ���� �������� ��� �� ����.

*/
class MyList
{
private:
    MyNode* head = nullptr;
    MyNode* tail = nullptr;

    int _size = 0;

public:
    void MergeSort();
    void QuickSort();
    void BubbleSort();

    void push_front(int val);
    void push_back(int val);

    void pop_back();
    void pop_front();

    int front();    // �� ���� �� ��ȯ.
    int back();        // �� ���� �� ��ȯ.
    int at(int index);
    int insert(int index, int value);
    int erase(int index, int value);
    void clear();    // ����Ʈ ������ ��� ��� ����

    void print();    // ����Ʈ ������ cout���� ���(������ �Լ�)
    size_t size();    // ����Ʈ�� ����ִ� �������� �� ��ȯ.
private:
    void MergeSort(std::vector<int>& array, int start, int end, std::vector<int>& temp);
    void Merge(std::vector<int>& array, int start, int end, std::vector<int>& temp);
    void QuickSort(std::vector<int>& array, int left, int right);
    int Partition(std::vector<int>& array, int left, int right);
};