#include "account.hpp"

bool operator<(const account &a, const account &b) { return a.id < b.id; }

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
  stream << account.balance << "." << std::endl;
  return stream;
}

void read_accounts(std::istream &stream, std::vector<account> &vec) {
  account acct;
  while (stream >> acct) {
    vec.push_back(acct);
  }
}
