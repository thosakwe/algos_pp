#include <cctype>
#include <iomanip>
#include <iostream>
#include "b_tree.h"

struct account
{
    int account_id;
    std::string name;
    double balance;
};

void dump_account(std::unique_ptr<node<int, account>>& n) {
    if (n == nullptr) return;
    std::cout << "Account #" << n->key << ": ";
    std::cout << n->value.name << " ($" << std::fixed << std::setprecision(2) << n->value.balance << ")";
    std::cout << std::endl;
    dump_account(n->left);
    dump_account(n->right);
}

int main() {
    int account_size = 0;
    std::unique_ptr<node<int, account>> root = nullptr;

    while (true) {
        char choice;
        std::cout << "A: Add account" << std::endl;
        std::cout << "D: Deposit" << std::endl;
        std::cout << "L: List accounts" << std::endl;
        std::cout << "W: Withdraw" << std::endl;
        std::cout << "X: Close account" << std::endl;
        std::cout << "Q: Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        choice = static_cast<char>(toupper(choice));

        if (choice == 'A') {
            std::string name;
            std::cout << "Enter your name: ";
            std::cin >> name;
            account acct = {account_size++, name, 0.0};
            insert(root, acct.account_id, acct);
        } else if (choice == 'D') {
            int account_no;
            double amount;
            std::cout << "Enter your account number: ";
            std::cin >> account_no;

            auto &node = search_recursively(account_no, root);

            if (node == nullptr) {
                std::cout << "No account found." << std::endl;
            } else {
                std::cout << "Enter the amount to deposit: ";
                std::cin >> amount;
                node->value.balance += amount;
                std::cout << "Hello, " << node->value.name;
                std::cout << "! Your balance is now $" << std::fixed << std::setprecision(2) << node->value.balance << std::endl;
            }
        } else if (choice == 'W') {
            int account_no;
            double amount;
            std::cout << "Enter your account number: ";
            std::cin >> account_no;

            auto &node = search_recursively(account_no, root);

            if (node == nullptr) {
                std::cout << "No account found." << std::endl;
            } else {
                std::cout << "Enter the amount to withdraw: ";
                std::cin >> amount;
                node->value.balance -= amount;
                std::cout << "Hello, " << node->value.name;
                std::cout << "! Your balance is now $" << std::fixed << std::setprecision(2) << node->value.balance << std::endl;
            }
        } else if (choice == 'X') {

        } else if (choice == 'L') {
            dump_account(root);
        } else if (choice == 'Q') {
            break;
        }
    }

    return 0;
}