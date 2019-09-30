#ifndef ALGOS_PP_HASH_MAP_HPP
#define ALGOS_PP_HASH_MAP_HPP
#include <functional>
#include <iostream>
#include <memory>
#include <stack>

namespace algos_pp {
template <typename K, typename V, class Hash = std::hash<K>> class hash_map {
public:
  struct node {
    typename Hash::result_type index;
    V data;
    std::shared_ptr<node> left, right;
    node() = default;
    node(typename Hash::result_type i, V d) : index(i), data(d) {}
  };

private:
  Hash hash;
  std::shared_ptr<node> root;

  bool insert(std::shared_ptr<node> &head, typename Hash::result_type index,
              V value, bool preserve = false) {
    if (!head) {
      head = std::make_shared<node>(index, value);
      return true;
    } else if (index == head->index) {
      if (!preserve) {
        head->data = value;
        return true;
      } else {
        return false;
      }
    } else if (index < head->index) {
      return insert(head->left, index, value);
    } else {
      return insert(head->right, index, value);
    }
  }

public:
  void dump(std::ostream &out) const {
    std::stack<std::shared_ptr<node>> stack;
    if (root)
      stack.push(root);
    while (!stack.empty()) {
      auto cur = stack.top();
      stack.pop();
      out << "[" << cur->index << "]=" << cur->data << std::endl;
      if (cur->left)
        stack.push(cur->left);
      if (cur->right)
        stack.push(cur->right);
    }
  }

  bool find(K key, V *value) const {
    auto cur = root;
    auto index = hash(key);
    while (cur) {
      if (cur->index == index) {
        //        std::cout << "Found hash " << index << " for key " << key << "
        //        = "
        //                  << cur->data << std::endl;
        *value = cur->data;
        return true;
      } else if (cur->index > index) {
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }
    return false;
  }

  bool insert(K key, V value, bool preserve = false) {
    auto index = hash(key);
    return insert(root, index, value, preserve);
  }

  V operator[](K key) const {
    auto value = V();
    find(key, &value);
    return value;
  }
};
} // namespace algos_pp

#endif
