#include <set>

template <typename T> struct node {
  node *next;
  T value;
};

template <typename T>
node<T>* remove_duplicates(node<T>* head) {
  std::set<T> seen;
  node<T>* out, *top = nullptr;
  while (head != nullptr) {
    if (seen.insert(head->value)) {
      if (out == nullptr) {
        out = top = head;
      } else {
        top->next = head;
        top = head;
      }
    }
    head = head->next;
  }
  return out;
}
