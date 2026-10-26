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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k==1)
        return head;

        ListNode dummy(0);
        dummy.next=head;

        ListNode* prevgroup=&dummy;

        while(true){
            ListNode* kth=prevgroup;

            for(int i=0;i<k && kth != nullptr;i++){
                kth = kth->next;
            }

            if(kth==nullptr)
            break;
            ListNode* groupnext=kth->next;

            ListNode* prev = groupnext;
            ListNode* curr=prevgroup->next;

            while(curr != groupnext){
                ListNode* nextnode=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nextnode;
            }
            ListNode* oldgrouphead=prevgroup->next;
            prevgroup->next=kth;
            prevgroup=oldgrouphead;
        }
        return dummy.next;
        
    }
};