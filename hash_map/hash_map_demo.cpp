#include "hash_map.hpp"
#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
int main() {
  algos_pp::hash_map<int, bool> map;
  map.insert(10, true);
  map.insert(23, true);
  map.insert(56, true);
  map.dump(std::cout);

  while (true) {
    int key;
    bool lookup;
    std::cout << "> ";
    std::cin >> key;
    if (key == -1) {
      map.dump(std::cout);
    } else if (!map.find(key, &lookup)) {
      map.insert(key, true);
      std::cout << "Inserted " << key << std::endl;
    } else {
      std::cout << "Already exists" << std::endl;
    }
  }
}
#pragma clang diagnostic pop