//https://leetcode.com/problems/swap-nodes-in-pairs/
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(): val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode*next): val(x),next(next){}
};

class Solution{
    public:
        //Faster than 56.56%, Memory use:7.9MB
        ListNode* swapPairv1(ListNode*head){
            if(head==NULL||head->next==NULL)return head;
            ListNode*t=head;
            while(t!=NULL && t->next!=NULL){
                int k=t->next->val;
                t->next->val=t->val;
                t->val=k;
                t=t->next->next;
            }
            return head;
        }
        //Runtime 0ms, faster than 100% memory use 7.9MB
        ListNode*swapPairv2(ListNode*head){
            if(!head||!head->next) return head;
            ListNode*temp=head;
            head=head->next;
            temp->next=head->next;
            head->next=temp;
            temp->next=swapPairv2(temp->next);
            return head;
        }
};
