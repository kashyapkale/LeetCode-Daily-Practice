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
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> nums_set;
        for(auto num : nums){
            nums_set.insert(num);
        }

        ListNode* curr = head;
        ListNode* newHead = new ListNode(-1, head);
        ListNode* prev = newHead;
        while(curr){
            if(nums_set.find(curr->val) != nums_set.end()){
                prev->next = curr->next;
            } else {
                prev = curr;
            }

            curr = curr->next;
        }
        

        return newHead->next;
    }
};