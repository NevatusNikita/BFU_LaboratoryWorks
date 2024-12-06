#include "funcs.hpp"
#include <iostream>

bool is_suitable(int x)
{
    if (x < 100 || x > 999)
        return false;
    else
    {
        int m;
        while (x != 0)
        {
            m = x % 10;
            if (m == 0 || m == 2 || m == 4 || m == 6 || m == 8)
                return false;
            x /= 10;
        }
        return true;
    }
}

bool find_eight(int x)
{
    while (x != 0)
    {
        if ((x % 10) == 8)
            return true;
        x /= 10;
    }
    return false;
}

namespace forward_list
{
    void Make(Node*& head)
    {
        head = new Node {0, nullptr};
    }
    void PushBack(Node* head, int x)
    {
        Node* p = head;
        while (p->next != nullptr)
            p = p->next;
        Node* node = new Node;
        node->data = x;
        node->next = nullptr;
        p->next = node;
    }
    void Print(Node* head)
    {
        Node* p = head;
        while (p->next != nullptr)
        {
            p = p->next;
            std::cout << p->data << " ";
        }
    }
    void RemoveByIndex(Node* head, int index)
    {
        Node* p = head;
        int ind = 0;
        while (p->next != nullptr && ind != index)
        {
            p = p->next;
            ind++;
        }
        if (p->next == nullptr)
            return;
        Node* tmp = p->next;
        p->next = p->next->next;
        delete tmp;
    }
    void Remove(Node* head, int x)
    {
        Node* p = head;
        while (p != nullptr && p->next->data != x)
        {
            p = p->next;
        }
        if (p == nullptr)
            return;
        Node* tmp = p->next;
        p->next = p->next->next;
        delete tmp;
    }
    void Clear(Node* head)
    {
        Node* p = head;
        while (p != nullptr)
        {
            Node* tmp = p;
            p = p->next;
            delete tmp;
        }
    }
    void CopyByIndex(Node* head, int index)
    {
        Node* p = head;
        int ind = 0;
        while (p->next != nullptr && ind != index)
        {
            p = p->next;
            ind++;
        }
        if (p->next == nullptr)
            return;
        if (index >= 0)
        {
            p = p->next;
            Node* node = new Node;
            node->data = p->data;
            node->next = p->next;
            p->next = node;
        }   
    }
    void Copy(Node* head, int x)
    {
        Node* p = head;
        while (p->next != nullptr && p->data != x)
        {
            p = p->next;
        }
        if (p == nullptr)
            return;
        Node* node = new Node;
        node->data = x;
        node->next = p->next;
        p->next = node;  
    }
    Node* FindIndex(Node* head, int index)
    {
        Node* p = head;
        int ind = 0;
        while (p->next != nullptr && ind != index)
        {
            p = p->next;
            ind++;
        }
        if (p->next == nullptr)
            return nullptr;
        if (index >= 0)
            return p->next;
    }
    void Change(Node* head, int n)
    {
        for (int i = 0; i < n * 2 + 1; ++i)
        {
            Node* p = FindIndex(head, i);
            if (p != nullptr)
            {
                int x = p->data;
                if (find_eight(x))
                    Remove(head, x);
                else
                {
                    Copy(head, x);
                    i++;
                }
            }
        }
    }
    Node* SortedInsert(Node* newnode, Node* sorted) 
    {
        if (sorted == nullptr || sorted->data >= newnode->data) 
        {
            newnode->next = sorted;
            sorted = newnode;
        }
        else 
        {
            Node* p = sorted;
            while (p->next != nullptr && (p->next->data < newnode->data)) 
                p = p->next;
        newnode->next = p->next;
        p->next = newnode;
        }
        return sorted;
    }

    Node* InsertionSort(Node* head) {
        Node* sorted = nullptr;
        Node* p = head;
        while (p != nullptr) 
        {
            Node* next = p->next;
            sorted = SortedInsert(p, sorted);
            p = next;
        }
        return sorted;
    }
}
