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
        /* intution is prev and current one 
        1.if its in nums i make the prev->next = curretn->next and current=curretn->next */
         unordered_set<int> mp(nums.begin(), nums.end()); //store the nums
        // for(auto &i :nums){
        //     mp[i]++;
        // }

        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode * current=head;
        ListNode* prev=dummy;
        while( current ){
            if(mp.count(current->val)){
                prev->next=current->next;
                current=current->next;
            }
            else{
                prev=current;
                current=current->next;
            }
        }
        
       return  dummy->next;
    }
};