#ifndef ALGOS_PP_B_TREE_H
#define ALGOS_PP_B_TREE_H

#include <memory>
#include <vector>
#include <string>

template<typename K, typename V>
struct node
{
    K key;
    V value;
    std::unique_ptr<node<K, V>> left;
    std::unique_ptr<node<K, V>> right;
};

template<typename K, typename V>
std::unique_ptr<node<K, V>>& search_recursively(K key, std::unique_ptr<node<K, V>> &search) {
    if (search == nullptr || search->key == key)
        return search;
    if (key < search->key)
        return search_recursively(key, search->left);
    return search_recursively(key, search->right);
}

template<typename K, typename V>
void insert(std::unique_ptr<node<K, V>> &root, K key, V value) {
    if (root == nullptr) {
        auto n = std::make_unique<node<K, V>>();
        n->key = key;
        n->value = value;
        root = std::move(n);
    } else if (key == root->key)
        root->value = value;
    else if (key < root->key)
        insert(root->left, key, value);
    else
        insert(root->right, key, value);
}

#endif