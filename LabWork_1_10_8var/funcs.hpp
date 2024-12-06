#pragma once

namespace forward_list
{
    struct Node
    {
        int data;
        Node* next;
    };
    void Make(Node*& head);
    void PushBack(Node* head, int x);
    void RemoveByIndex(Node* head, int index);
    void Remove(Node* head, int x);
    void Clear(Node* head);
    void Print(Node* head);
    void CopyByIndex(Node* head, int index);
    void Copy(Node* head, int x);
    Node* FindIndex(Node* head, int index);
    Node* FindQuantity(Node* head, int quantity);
    Node* SortedInsert(Node* newnode, Node* sorted);
    Node* InsertionSort(Node* head);
    void Change(Node* head, int n);
}

bool is_suitable(int x);
bool find_eight(int x);