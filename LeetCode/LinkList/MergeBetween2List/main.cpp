//https://leetcode.com/problems/merge-in-between-linked-lists/
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int countLength(ListNode*head){
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
}
ListNode*mergeInBetween(ListNode*list1,int a,int b,ListNode*list2){
    int n=countLength(list1);
    if(a>=n) return NULL;

    int count=0;
    ListNode*temp=list1;
    ListNode*list2_end=list2,*c,*d;
    while(list2_end->next!=NULL){
        list2_end=list2_end->next;
    }

    while(temp){
        if(count==a-1){
            c=temp;            

        }
        else if(count==b+1){
            d=temp;
            break;
        }
        count++;
        temp=temp->next;
    }
    c->next=list2;
    list2_end->next=(d==NULL)?NULL:d;
    return list1;
}
