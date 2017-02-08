#include "linked_lib.h"

#include <UnitTest++/UnitTest++.h>
#include <memory>
#include <iostream>
#include <stdexcept>

using namespace std;

// Test case for pop_front
TEST(POP_FRONT)
{

    ListNode xy;
    xy.data = 11;
    List xs = make_shared<ListNode>(xy);
    List ys = make_shared<ListNode>();
    ys->data = 12;
    xs->next = ys;
    List zs = make_shared<ListNode>();
    zs->data = 13;
    zs->next = nullptr;
    ys->next = zs;

    pop_front(xs);

    CHECK_EQUAL(xs->next == nullptr, true);
    CHECK_EQUAL(ys->next == nullptr, false);

}

// Test case for push_back
TEST(PUSH_BACK)
{

  List xs = make_shared<ListNode>();
  xs->data = 514;
  List ys = xs;

  push_back(xs, 2017211);

  CHECK_EQUAL(ys, xs);
  CHECK_EQUAL(514, xs->data);
  CHECK(xs->next != nullptr);
  CHECK_EQUAL(2017211, xs->next->data);
  CHECK(xs->next->next == nullptr);
}

// Test case for nth_element
TEST(NTH_ELEMENT)
{

    ListNode xy;
    xy.data = 11;
    List xs = make_shared<ListNode>(xy);
    List ys = make_shared<ListNode>();
    ys->data = 12;
    xs->next = ys;
    List zs = make_shared<ListNode>();
    zs->data = 13;
    zs->next = nullptr;
    ys->next = zs;

    int n = nth_element(xs, 1);

    CHECK_EQUAL(n, 12);
    CHECK_EQUAL(n == 11, false);
    CHECK_THROW(nth_element(xs, 3), runtime_error);

}

// Test case for filter_lt
TEST(FILTER_LT)
{

    ListNode xy;
    xy.data = 11;
    List xs = make_shared<ListNode>(xy);
    List ys = make_shared<ListNode>();
    ys->data = 10;
    xs->next = ys;
    List zs = make_shared<ListNode>();
    zs->data = 12;
    ys->next = zs;
    List as = make_shared<ListNode>();
    as->data = 14;
    zs->next = as;
    List bs = make_shared<ListNode>();
    bs->data = 15;
    bs->next = nullptr;
    as->next = bs;

    filter_lt(xs, 13);

    CHECK_EQUAL(xs->data == 11, true);
    CHECK_EQUAL(xs->next->data == 10, true);

    List px = nullptr;
    filter_lt(px, 10);

    CHECK_EQUAL(px == nullptr, true);

    filter_lt(ys, 100);

    CHECK_EQUAL(ys->data == 10, true);
    CHECK_EQUAL(ys->next->data == 12, true);

}

// This function overloads the '<<' operator to enable printing on List
// types. For example, 'cout << xs << '\n';' will compile and print its
// content. However, we are still not able to write tests such as
// CHECK_EQUAL(nullptr, xs) since nullptr might be of any pointer type
// and the '<<' operator does not know how to print it.
ostream& operator<<(ostream& out, const List& lst)
{
  if (lst) {
    out << "<ListNode@" << static_cast<void*>(lst.get());
    out << " data=" << lst->data;
    out << " next=" << static_cast<void*>(lst->next.get());
    out << ">";
  } else {
    out << "(nullptr)";
  }
  return out;
}
