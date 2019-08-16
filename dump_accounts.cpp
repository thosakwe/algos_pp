#include "account.hpp"
#include <fstream>
#include <iostream>

// Dummy program to verify that reading works.
int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Missing input file." << std::endl;
    return 1;
  }

  std::ifstream ifs(argv[1]);
  if (!ifs) {
    std::cout << "Could not open file." << std::endl;
    return 1;
  }

  std::vector<account> accounts;
  ifs >> accounts;
  std::cout << accounts;
  return 0;
}