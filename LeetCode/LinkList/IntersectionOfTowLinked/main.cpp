//https://leetcode.com/problems/intersection-of-two-linked-lists/
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x): val(x),next(NULL){}
};

class Solution{
    public:
        int getLenght(ListNode*head){
            int count=0;
            while(head){
                count++;
                head=head->next;
            }
            return count;
        }
        ListNode* getIntersectionNode(ListNode*headA,ListNode*headB){
            int countA=getLenght(headA),countB=getLenght(headB),d;
            if(countA<countB){
                d=countB-countA;
                for(int i=0;i<d;i++){
                    headB=headB->next;
                }
            }
            else if(countA>countB){
                d=countA-countB;
                for(int i=0;i<d;i++){
                    headA=headA->next;
                }
            }
            while(headA!=headB){
                headA=headA->next;
                headB=headB->next;
            }
            return headA;
        }
};
