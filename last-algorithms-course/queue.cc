#include <stddef.h>

#include <iostream>

#include "node.h"

template <typename T>
struct queue {
  node<T>* head;
  node<T>* tail;
  size_t length;

  void enque(T data) {
    node<T>* n = new node<T>(data);
    if (!length)
      head = tail = n;
    else {
      tail->next = n;
      tail = n;
    }

    ++length;
  }

  T peek() { return head->data; }

  T deque() {
    if (!length) return -1;

    --length;

    T out = head->data;
    head = head->next;

    return out;
  }

  size_t size() { return length; };
};

int main() {}
