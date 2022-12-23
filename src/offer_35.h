#include <map>

#include "utility/random_node.h"

namespace method1 {
class Solution {
 private:
  std::map<Node*, Node*> node_memory;

 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) {
      return nullptr;
    }
#if _LIBCPP_STD_VER > 17
    if (node_memory.contains(head)) {
#else
    if (node_memory.count(head)) {
#endif  // _LIBCPP_STD_VER > 17
      return node_memory[head];
    }
    auto new_head = new Node(head->val);
    node_memory[head] = new_head;
    new_head->next = copyRandomList(head->next);
    new_head->random = copyRandomList(head->random);

    return new_head;
  }
};
}  // namespace method1

namespace method2 {
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) {
      return nullptr;
    }
    // For the first iteration, create a node after the original node
    // From: node1 -> node2 -> node3 ... nodeN
    // To: node1 -> dupNode1 -> node2 -> dupNode2 ... nodeN -> dupNodeN
    auto current = head;
    while (current != nullptr) {
      auto new_node = new Node(current->val);
      new_node->next = current->next;
      current->next = new_node;
      current = new_node->next;
    }

    // For the second iteration, set the random pointer
    current = head;
    while (current != nullptr) {
      auto new_node = current->next;
      new_node->random =
          current->random != nullptr ? current->random->next : nullptr;
      current = new_node->next;
    }

    // For the third iteration, pick out the duplicated nodes
    //  To: dupNode1 -> dupNode2 -> ... dupNodeN
    current = head;
    Node new_pre_head(-1);
    auto new_current = &new_pre_head;
    while (current != nullptr) {
      auto new_node = current->next;
      new_current->next = new_node;
      current->next = new_node->next;

      current = current->next;
      new_current = new_current->next;
    }

    return new_pre_head.next;
  }
};
}  // namespace method2
