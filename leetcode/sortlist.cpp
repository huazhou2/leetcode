#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        int length=0;
        ListNode* cur=head;
        while (cur) {
            length++;
            cur=cur->next;
        }
        return mergesort(head,length);
    }
    ListNode* mergesort(ListNode*& head, int length) {
        if (length==1) {
            ListNode *temp=head;
            head=head->next;
	    temp->next=NULL;
            return temp;}
        ListNode* lhead=mergesort(head,length/2);
        ListNode* rhead=mergesort(head,length-length/2);
        return merge(lhead,rhead);
    }
    ListNode* merge(ListNode* lhead, ListNode* rhead) {
        if (!lhead) return rhead;
        if (!rhead) return lhead;
        ListNode* head=new ListNode(-1);
        ListNode* cur=head;
        while (lhead || rhead) {
            if (!lhead) {
                cur->next=rhead;
                break;}
            if (!rhead) {
                cur->next=lhead;
                break;}
                
            if (lhead->val<=rhead->val) {
                cur->next=lhead;
                cur=cur->next;
                lhead=lhead->next;}
            else {
                cur->next=rhead;
                cur=cur->next;
                rhead=rhead->next;}
            }
        return head->next;
        }
};

void print(ListNode* head) {
	if (!head) return;
	ListNode* cur=head;
	while (cur) { 
	cout<<cur->val<<"  ";
	cur=cur->next;}
	cout<<endl;}
int main() {
	ListNode *head=new ListNode(2);
	ListNode *cur=head;
	cur->next=new ListNode(1);
	cur=cur->next;
	cur->next=new ListNode(4);
	cur=cur->next;
	cur->next=new ListNode(3);
	cur=cur->next;
	print(head);
	Solution m;
	ListNode* newhead=m.sortList(head);
	print(newhead);
	}

