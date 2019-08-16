#include "account.hpp"

bool operator<(const account &a, const account &b) { return a.id < b.id; }

std::istream &operator>>(account &account, std::istream &stream) {
  std::string discard;
  stream >> account.id;
  getline(stream, discard, ';');      // Consume the first semicolon
  getline(stream, account.name, ';'); // Read the actual name
  stream >> account.balance;
  return stream;
}

std::ostream &operator<<(const account &account, std::ostream &stream) {
  stream << "User ID #" << account.id;
  stream << ", " << account.name << ", has $";
  stream << account.balance << "." << std::endl;
  return stream;
}
