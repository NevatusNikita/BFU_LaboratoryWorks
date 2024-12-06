#include <iostream>
#include "funcs.hpp"

int main()
{
    setlocale(0, "");
    /*forward_list::Node* head;
    forward_list::Make(head);
    forward_list::PushBack(head, 1);
    forward_list::PushBack(head, 3);
    forward_list::PushBack(head, 5);
    forward_list::Print(head);
    forward_list::Copy(head, 5);
    forward_list::Print(head);
    forward_list::Clear(head);*/
    std::cout << "¬ведите количество элементов последовательности: ";
    int n;
    std::cin >> n;
    std::cout << "¬ведите элементы последовательности: ";
    int x;
    forward_list::Node* head;
    forward_list::Make(head);
    bool suitable_fib = false;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x;
        if (is_suitable(x))
            suitable_fib = true;
        forward_list::PushBack(head, x);
    }
    std::cout << std::endl;
    if (suitable_fib)
        forward_list::Change(head, n);
    else
        forward_list::InsertionSort(head);
    forward_list::Print(head);
    forward_list::Clear(head);
}