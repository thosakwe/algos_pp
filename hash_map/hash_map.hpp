#ifndef ALGOS_PP_HASH_MAP_HPP
#define ALGOS_PP_HASH_MAP_HPP
#include <functional>
#include <memory>

namespace algos_pp {
template <typename K, typename V, class Hash = std::hash<K>> class hash_map {
public:
  struct node {
    typename Hash::result_type index;
    V data;
    std::unique_ptr<node> left, right;
  };

private:
  Hash hash;
  std::unique_ptr<node> root;

public:
  bool find(K key, V *value) {
    auto &cur = root;
    auto index = hash(key);
    while (cur) {
      if (cur.index == index) {
        *value = cur.data;
        return true;
      } else if (cur.index > index) {
        cur = cur.left;
      } else {
        cur = cur.right;
      }
    }
    return false;
  }

  void insert(K key, V value) {
    auto &cur = root;
    auto index = hash(key);
    while (cur) {
      if (cur.index == index)
        return;
      else if (cur.index > index) {
        cur = cur.left;
      } else {
        cur = cur.right;
      }
    }
    cur = {index, value};
  }

  V operator[](K key) {
    auto value = V();
    find(key, &value);
    return value;
  }
};
} // namespace algos_pp

#endif
