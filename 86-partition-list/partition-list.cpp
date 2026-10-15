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
    ListNode* partition(ListNode* head, int x) {
        ListNode lessdummy(0);
        ListNode greaterdummy(0);

        ListNode* less = &lessdummy;
        ListNode* greater=&greaterdummy;

        while(head != nullptr){
            if(head->val <x){
                less->next =head;
                less=less->next;
            }else{
                greater->next=head;
                greater=greater->next;
            }
            head=head->next;
        }
        greater->next=nullptr;
        less->next=greaterdummy.next;

        return lessdummy.next;
        
    }
};