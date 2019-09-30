#ifndef ALGOS_PP_HASH_SET_HPP
#define ALGOS_PP_HASH_SET_HPP
#include "hash_map.hpp"

namespace algos_pp {
template <typename K, class Hash = std::hash<K>> class hash_set {
private:
  hash_map<K, bool, Hash> map;

public:
  const hash_map<K, bool, Hash> &get_map() const { return map; }

  bool contains(K key) {
    bool value;
    return map.find(key, &value);
  }

  bool insert(K key) { return map.insert(key, true, true); }
};
} // namespace algos_pp

#endif
