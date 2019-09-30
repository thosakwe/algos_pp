#include "hash_set.hpp"
#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
int main() {
  algos_pp::hash_set<int> set;
  set.insert(10);
  set.insert(23);
  set.insert(56);
  set.get_map().dump(std::cout);

  while (true) {
    int key;
    std::cout << "> ";
    std::cin >> key;
    if (key == -1) {
      set.get_map().dump(std::cout);
    } else if (set.insert(key)) {
      std::cout << "Inserted " << key << std::endl;
    } else {
      std::cout << "Already exists" << std::endl;
    }
  }
}
#pragma clang diagnostic pop