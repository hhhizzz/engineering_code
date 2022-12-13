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
