#pragma once

#include <iostream>
#include <optional>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  static TreeNode* VecToTree(std::vector<std::optional<int>>& input) {
    if (input.empty()) {
      return nullptr;
    }

    std::vector<TreeNode*> node_vec;

    for (auto item : input) {
      if (item.has_value()) {
        node_vec.push_back(new TreeNode(item.value()));
      } else {
        node_vec.push_back(nullptr);
      }
    }
    for (int i = 0; i < node_vec.size(); i++) {
      if (node_vec[i] == nullptr) {
        continue;
      }
      auto left_child_index = i * 2 + 1;
      if (left_child_index < node_vec.size()) {
        node_vec[i]->left = node_vec[left_child_index];
      }
      auto right_child_index = i * 2 + 2;
      if (right_child_index < node_vec.size()) {
        node_vec[i]->right = node_vec[right_child_index];
      }
    }

    return node_vec[0];
  }
};

#pragma endregion