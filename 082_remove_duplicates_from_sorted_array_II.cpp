#include <iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* cur=head;
        ListNode* dummy=new ListNode(0);
	ListNode* newhead=dummy;
        int value=cur->val;
        bool appear=false;
        while (cur->next) {
            if (cur->next->val!=value) {
		if (!appear) {
                dummy->next=cur;
		cout<<value<<endl;
                dummy=dummy->next;}
                value=cur->next->val;
                appear=false;
            }
            else {
                appear=true;
		}
            cur=cur->next;
            }
	if (!appear) dummy->next=cur;
	else dummy->next=NULL;
        return newhead->next;
        }
};

void print(ListNode* head) {
	if (!head) return;
	while (head) {
	cout<<head->val<<"  ";
	head=head->next;
		}
	cout<<endl;
	}

int main() {
	ListNode* a=new ListNode(1);
	ListNode* b=new ListNode(1);
	ListNode* c=new ListNode(1);
	ListNode* d=new ListNode(2);
	ListNode* e=new ListNode(3);
	ListNode* f=new ListNode(4);
	ListNode* g=new ListNode(4);
	a->next=b;
	b->next=c;
	c->next=d;
	d->next=e;
	e->next=f;
	f->next=g;
	print(a);
	Solution m;
	ListNode* head=m.deleteDuplicates(a);
	print(head);
	}
	
