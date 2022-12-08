#pragma once

#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}

  static ListNode* Build(std::vector<int>& input) {
    auto pre_head = new ListNode(-1);
    auto pre = pre_head;
    for (auto item : input) {
      auto current = new ListNode(item);
      pre->next = current;
      pre = current;
    }
    auto head = pre_head->next;
    delete pre_head;
    return head;
  }
};

#pragma endregion