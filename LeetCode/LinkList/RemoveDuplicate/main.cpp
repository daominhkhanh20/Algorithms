//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    public:
        ListNode* deleteDuplicate(ListNode*head){
            ListNode*temp=new ListNode(0,head);
            ListNode*pre=temp;

            while(head!=NULL){
                if(head->next!=NULL&&head->val==head->next->val){
                    while(head->next!=NULL&&head->val==head->next->val){
                        head=head->next;
                    }
                    pre->next=head->next;
                }
                else{
                    pre=pre->next;
                }
                head=head->next;
            }
            return temp->next;
        }
};
