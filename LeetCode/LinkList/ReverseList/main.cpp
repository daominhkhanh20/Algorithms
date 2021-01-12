#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(NULL){}
};

//recursive
ListNode*reverseList(ListNode*head){
    if(!head||!head->next) return head;

    ListNode*t=head->next;
    head->next=NULL;
    ListNode*temp=reverseList(t);
    t->next=head;
    return temp;
}

//for
ListNode*reverseList1(ListNode*head){
    if(!head||!head->next) return head;

    ListNode*t=head->next;
    head->next=NULL;
    ListNode*temp=t;
    while(true){
        temp=temp->next;
        t->next=head;
        head=t;
        if(!temp)break;
        t=temp;
    }
    return head;
}

int countNode(ListNode*head){
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
}
//m<=n;
ListNode *reverseBetween(ListNode*head,int m,int n){
    if(m==n || head==NULL || head->next==NULL)return head;
    int count=countNode(head),i=0;
    if(n>=count) return head;

    ListNode*t1,*t2,*temp=head;
    while(temp){
        if(i+1==m){
            t1=temp;
        }
        else if(i+1==n){
            t2=temp;
            break;
        }
        temp=temp->next;
    }
    ListNode*c=t1->next,*d=(t2->next!=NULL)?t2->next:NULL;
    t1->next=t2;
    t2->next=c;
    c->next=d;
    return head;
}
