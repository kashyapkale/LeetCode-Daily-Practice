/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
         ListNode* slow = head;
         ListNode* fast = head;

         while(fast && slow && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
         }

         ListNode* newlistHead = reverseLL(slow->next);
         slow->next = NULL;

         ListNode* newHead = new ListNode(-1);
         ListNode* curr = newHead;
         ListNode* curr1 = head;
         ListNode* curr2 = newlistHead;
         ListNode* temp = newlistHead;

         while(curr1 && curr2){
            curr->next = curr1;
            curr1 = curr1->next;
            if(curr->next)
                curr = curr->next;
            curr->next = curr2;
            curr2 = curr2->next; 
            if(curr->next)
                curr = curr->next;
         }

         if(curr1){
            curr->next = curr1;
         }
    }
};