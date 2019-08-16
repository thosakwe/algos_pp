#include "account.hpp"
#include <iomanip>

bool operator<(const account &a, const account &b) { return a.id < b.id; }

bool operator>(const account &a, const account &b) { return a.id > b.id; }

bool operator<=(const account &a, const account &b) { return a < b || a == b; }

bool operator>=(const account &a, const account &b) { return a > b || a == b; }

bool operator==(const account &a, const account &b) {
  return a.id == b.id && a.name == b.name && a.balance == b.balance;
}

std::istream &operator>>(std::istream &stream, account &account) {
  std::string discard;
  stream >> account.id;
  getline(stream, discard, ';');      // Consume the first semicolon
  getline(stream, account.name, ';'); // Read the actual name
  stream >> account.balance;
  return stream;
}

std::ostream &operator<<(std::ostream &stream, const account &account) {
  stream << "User ID #" << account.id;
  stream << ", " << account.name << ", has $";
  stream << std::fixed << std::setprecision(2) << account.balance;
  stream << ".";
  return stream;
}

std::istream &operator>>(std::istream &stream, std::vector<account> &vec) {
  account acct;
  while (stream >> acct) {
    vec.push_back(acct);
  }
  return stream;
}

std::ostream &operator<<(std::ostream &stream, std::vector<account> &vec) {
  stream << vec.size() << " account(s):" << std::endl;
  //  stream << "[";
  //  auto i = 0;
  for (const auto &acct : vec) {
    //    if (i++ > 0)
    //      stream << ", ";
    //    stream << acct.id;
    stream << acct << std::endl;
  }
  //  stream << "]";
  return stream;
}