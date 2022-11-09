template <typename T>
struct node {
  T data;
  node<T>* next;

  node(T t) : data(t) {}
};
