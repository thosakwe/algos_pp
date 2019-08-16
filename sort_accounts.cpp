#include "account.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 3) {
    std::cout << "usage: sort_accounts <file> <bubble|quick>" << std::endl;
    return 1;
  }

  std::ifstream ifs(argv[1]);
  std::string method(argv[2]);
  if (!ifs) {
    std::cout << "Could not open file." << std::endl;
    return 1;
  }

  std::vector<account> accounts;
  ifs >> accounts;

  // TODO: Other sorts
  if (method == "bubble") {

  }

  std::cout << accounts;
}