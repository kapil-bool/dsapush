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
    ListNode *reverse(ListNode*node){
        ListNode *prev=nullptr;
        while(node){
            ListNode *nxt=node->next;
            node->next=prev;
            prev=node;
            node=nxt;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        //idea is middle one and reverse and then pair wise sum max approch;
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next; //may point to null so dont use this one 
        }

        ListNode * revhalf=reverse(slow);
        ListNode* ptr1=head;
        int ans=-1;
        while(revhalf){
           ans=max(ptr1->val+revhalf->val,ans);
           ptr1=ptr1->next;
           revhalf=revhalf->next;
        }

        //this slow is the middle point here
        return ans;
    }
};