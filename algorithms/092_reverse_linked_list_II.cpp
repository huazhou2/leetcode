#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return head;
        ListNode* left=head;
        ListNode * dummy=new ListNode(0);
        dummy->next=head;
        ListNode* cur=dummy;
        int count=0;
        while(cur->next) {
            count++;
            if (count==m) {
                left=cur;
                break;}
        cur=cur->next;
        }
        cur=left->next;
        count=0;
        while (count<n-m) {
            count++;
            ListNode * right=left->next;
            left->next=cur->next;
            cur->next=left->next->next;
            left->next->next=right;
        }
    return dummy->next;
    }
};
void print(ListNode* head) {
	if (!head) return;
	ListNode* cur=head;
	while (cur) {
	if (!cur->next) 
		cout<<cur->val;
	else
	cout<<cur->val<<"->";
	cur=cur->next;}
	cout<<endl;
	}

int main() {
	ListNode *a=new ListNode(1);
	ListNode *b=new ListNode(2);
	ListNode *c=new ListNode(3);
	a->next=b;
	b->next=c;
	print(a);
	Solution m;
	ListNode* head=m.reverseBetween(a,2,3);
	print(head);
	}
	
