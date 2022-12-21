#pragma once

#include <vector>

struct ListNode {
  int val;
  ListNode* next = nullptr;
  explicit ListNode(int x) : val(x) {}

  static std::vector<int> ToVec(const ListNode* head) {
    std::vector<int> result;
    auto current = head;

    while (current != nullptr) {
      result.push_back(current->val);
      current = current->next;
    }

    return result;
  }

  static ListNode* Build(const std::vector<int>& input) {
    ListNode pre_head_item(-1);
    ListNode* pre_head = &pre_head_item;

    auto pre = pre_head;
    for (auto item : input) {
      auto current = new ListNode(item);
      pre->next = current;
      pre = current;
    }
    auto head = pre_head->next;

    return head;
  }
};

#pragma endregion