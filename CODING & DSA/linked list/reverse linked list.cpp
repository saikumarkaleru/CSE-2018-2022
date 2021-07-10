class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      ListNode* prev = NULL;
      while(head != NULL)
      {
        ListNode* next_node = head->next;
        head->next = prev;
        prev = head;
        head = next_node;
      }
      return prev;
    }
};