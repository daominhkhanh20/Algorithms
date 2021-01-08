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
        ListNode* insertionSortList(ListNode*head){
            if(head==NULL|| head->next==NULL) return head;
            ListNode*t=head;
            ListNode*a,*min;
            int temp;
            while(t){
                min=t;
                a=t->next;
                while(a){
                    if(a->val<min->val){
                        min=a;
                    }
                    a=a->next;
                }
                temp=t->val;
                t->val=min->val;
                min->val=temp;
                t=t->next;
            }
            return head;
        }
};
