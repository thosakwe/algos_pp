#include "account.hpp"
#include "quicksort.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 3) {
    std::cout << "usage: sort_accounts <file> ";
    std::cout << "<bubble|quick_it|quick_rec>" << std::endl;
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
  if (method == "quick_rec") {
    std::cout << "QUICKSORT RECURSIVE" << std::endl;
    quicksort(accounts);
  } else if (method == "quick_it") {
    std::cout << "QUICKSORT ITERATIVE, PIVOT AS END" << std::endl;
    quicksort_end(accounts);
  } else {
    std::cout << "Unknown method " << method << std::endl;
  }

  std::cout << accounts;
}