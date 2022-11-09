#include <stddef.h>

#include <iostream>

#include "node.h"

template <typename T>
struct stack {
  node<T>* head;
  node<T>* tail;
  size_t length;

  void push(T data) {
    node<T>* n = new node<T>(data);

    if (!length)
      head = tail = n;
    else {
      tail->next = n;
      tail = n;
    }

    ++length;
  }

  T peek() { return tail->data; }

  T pop() {
    if (!length) return -1;

    T data;

    if (length == 1) {
      data = head->data;
      head = tail = nullptr;
    } else {
      node<T>* trail;
      for (trail = head; trail->next->next; trail = trail->next)
        ;
      data = trail->next->data;
      trail->next = nullptr;
      tail = trail;
    }

    --length;

    return data;
  }

  size_t size() { return length; }
};

int main() {}
