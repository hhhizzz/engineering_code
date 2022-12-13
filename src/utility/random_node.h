#pragma once

#include <map>
#include <utility>
#include <vector>

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  explicit Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }

  static Node* BuildNode(const std::vector<std::pair<int, int>>& input) {
    if (input.empty()) {
      return nullptr;
    }

    auto node_vec = std::vector<Node*>(input.size(), nullptr);

    for (int i = 0; i < input.size(); i++) {
      node_vec[i] = new Node(input[i].first);
      if (i > 0) {
        node_vec[i - 1]->next = node_vec[i];
      }
    }
    for (int i = 0; i < input.size(); i++) {
      if (input[i].second != -1) {
        node_vec[i]->random = node_vec[input[i].second];
      }
    }
    return node_vec[0];
  }

  static std::vector<std::pair<int, int>> ToVec(Node* head) {
    std::vector<std::pair<int, int>> result;
    std::map<Node*, int> m;

    auto current = head;
    int index = 0;
    while (current != nullptr) {
      auto item = std::pair<int, int>(current->val, -1);
      m[current] = index;
      result.push_back(item);
      index++;
      current = current->next;
    }

    current = head;
    index = 0;
    while(current != nullptr){
      if(current->random != nullptr){
        auto random_index = m[current->random];
        result[index].second = random_index;
      }
      index++;
      current = current->next;
    }

    return result;
  }
};

#pragma endregion