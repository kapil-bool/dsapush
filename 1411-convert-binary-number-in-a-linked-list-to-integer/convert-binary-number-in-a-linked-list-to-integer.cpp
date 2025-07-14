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
    int getDecimalValue(ListNode* head) {
        vector<int>store;
        while(head!=NULL){
            store.push_back(head->val);
            head=head->next;
        }
        //now from back and return
        int n=store.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(store[i]==1){

              ans += (1 << (n - i - 1));
            }
            else
            continue;
        }
        return ans;
    }
};