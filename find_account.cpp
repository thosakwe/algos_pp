#include "account.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 4) {
    std::cout << "usage: find <file> <id> <loop|binary>" << std::endl;
    return 1;
  }

  std::ifstream ifs(argv[1]);
  std::string id_str(argv[2]);
  auto id = stoi(id_str);
  std::string method(argv[3]);
  if (!ifs) {
    std::cout << "Could not open file." << std::endl;
    return 1;
  }

  std::vector<account> accounts;
  ifs >> accounts;

  // TODO: Other sorts
  if (method == "loop") {

  }
}