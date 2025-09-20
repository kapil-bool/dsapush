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
 //here intution is 2 pointer for s and e ; only in case of even one
 //prev->grp and next grp also there next grp from end always 
 //prev grp ican make it traverse make a dummy one 
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next =head;
        ListNode* prev=dummy;
        ListNode* current=head;
        int grpsize=1;
        while(current){
            //odd and even grp both will have  adiffernt functi
            int count =0;
          
            for(ListNode* temp=current ;temp and count<grpsize;++count,temp=temp->next);
            if((count &1)==0){
                ListNode* start=current;
                ListNode* end=current;
                for(int i=1;i<count;i++){
                    end=end->next;
                }
                  ListNode* nextgrp = end->next;

                // reverse [start ... end]
                ListNode* prevNode = nextgrp;
                ListNode* node = start;
                while (node != nextgrp) {
                    ListNode* nxt = node->next;
                    node->next = prevNode;
                    prevNode = node;
                    node = nxt;
                }
                prev->next=end;
                //next grp se kya connect hoga 
                prev=start;
                current=nextgrp;

                
            }
            else{
                //odd grp ka prevos ko current -1 so dummy is here 
                for(int i=0;i<count;i++){
                    prev=current;
                    current=current->next;
                }
            }
            
            grpsize++;
        }
        return dummy->next;
    }
};