#ifndef ALGOS_PP_ACCOUNT_HPP
#define ALGOS_PP_ACCOUNT_HPP
#include <iostream>
#include <string>

struct account {
  int id;
  std::string name;
  float balance;
  friend bool operator<(const account &a, const account &b);
  friend std::istream& operator<<(account& account, std::istream& stream);
  friend std::ostream& operator>>(account& account, std::ostream& stream);
};

#endif