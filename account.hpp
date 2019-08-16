#ifndef ALGOS_PP_ACCOUNT_HPP
#define ALGOS_PP_ACCOUNT_HPP
#include <iostream>
#include <string>
#include <vector>

struct account {
  int id;
  std::string name;
  float balance;
  friend bool operator<(const account &a, const account &b);
  friend bool operator>(const account &a, const account &b);
  friend bool operator<=(const account &a, const account &b);
  friend bool operator>=(const account &a, const account &b);
  friend bool operator==(const account &a, const account &b);
};

std::istream &operator>>(std::istream &stream, account &account);
std::ostream &operator<<(std::ostream &stream, const account &account);
std::istream &operator>>(std::istream &stream, std::vector<account> &vec);
std::ostream &operator<<(std::ostream &stream, std::vector<account> &vec);

#endif