#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        int length=0,count=0;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* cur=head,*right;
        while(cur) {
            length++;
	    cur=cur->next;
        }
        if (k>length) return head;
        ListNode* left=dummy;
        cur=left->next;
        int cycle=0;
        length=length/k;
        while (cycle<length) {
            cycle++;
            count=0;
        while (count<k-1) {
            count++;
            right=left->next;
            left->next=cur->next;
            cur->next=left->next->next;
            left->next->next=right; }
        if (cycle<length) {
                left=cur;
                cur=cur->next;
            }
        }
        return dummy->next;
    }
};
void print(ListNode* head) {
	if (!head) return;
	while (head) {
	if (head->next) 
		cout<<head->val<<"->";
	else
		cout<<head->val;
	head=head->next;
	}
	cout<<endl;
	}
int main() {
	ListNode* a=new ListNode(1);
	ListNode* b=new ListNode(2);
	ListNode* c=new ListNode(3);
	ListNode* d=new ListNode(4);
	ListNode* e=new ListNode(5);
	ListNode* f=new ListNode(6);
	ListNode* g=new ListNode(7);
	a->next=b;
	b->next=c;
	c->next=d;
	d->next=e;
	e->next=f;
	f->next=g;
	print(a);
	Solution m;
	ListNode* head=m.reverseKGroup(a,3);
	print(head);
	}
