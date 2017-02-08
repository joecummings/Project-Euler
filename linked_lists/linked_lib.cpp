#include "linked_lib.h"

#include <memory>
#include <stdexcept>

using namespace std;

// filter_lt modifies the input List to contain only integers less than
// the given limit
void filter_lt(List &front, int limit)
{
    if (front == nullptr) return;

    List temp = front;

    size_t size_temp = 0;

    while(temp->next != nullptr) {
        ++size_temp;
        temp = temp->next;
    }

    List curr = front;

    for (int i = 0; i <= size_temp; ++i) {
        if (curr->data >= limit) {
            curr = curr->next->next;
        }
    }
}

//push_back adds a ListNode to the input List
void push_back(List &front, int data)
{
    List temp = front;
    List curr = make_shared<ListNode>();
    curr->data = data;
    curr->next = nullptr;

    while (temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        temp->next = curr;
    }
}

//pop_front removes the first node and returns it
List pop_front(List &front)
{
    if (front == nullptr) {
        throw runtime_error("front is null pointer.");
    }

    List temp = make_shared<ListNode>();
    temp = front;

    front->next = nullptr;
    temp = temp->next;

    return front;
}

//nth_element returns the value of the node at the given index
int &nth_element(List &front, size_t n)
{
    List temp = front;

    size_t size = 0;

    while(temp->next != nullptr) {
        ++size;
        temp = temp->next;
    }


    if (n >= size) {
        throw runtime_error("out of bounds");
    }

    List curr = front;

    int p = 0;

    for (int i = 0; i <= size; ++i) {
        if (i == n) {
            p =  curr->data;
        } else {
            curr = curr->next;
        }
    }

    return p;
}
