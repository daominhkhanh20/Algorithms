#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode*addTwoNumber(ListNode*l1,ListNode*l2){
    ListNode*sum=new ListNode(0);
    ListNode*t1=l1,*t2=l2,*curr=sum;
    int mem=0,x,y,temp;
    while(t1!=NULL || t2!=NULL){
        x=(t1!=NULL)?t1->val:0;
        y=(t2!=NULL)?t2->val:0;
        temp=x+y+mem;
        curr->next=new ListNode(temp%10);
        mem=temp/10;
        curr=curr->next;
        if(t1!=NULL)t1=t1->next;
        if(t2!=NULL)t2=t2->next;
    }
    if(mem!=0)curr->next=new ListNode(mem);
    return sum->next;
}
