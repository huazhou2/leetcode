#include <iostream>
using namespace std;
  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* shead=dummy, *lhead=NULL;
        while (shead->next) {
            if (shead->next->val<x) 
                shead=shead->next;
            else {
                lhead=shead->next;
                break;
            }}
        ListNode* pre=head, *cur=head->next;
        
        while(cur) {
            if (pre->val>=x && cur->val<x) {
                shead->next=cur;
                shead=cur;
                pre->next=cur->next;
                cur=cur->next;
            }
            else
            {pre=cur;
            cur=cur->next;}
        }
        shead->next=lhead;
        return dummy->next;
        }
};

void print(ListNode* root) {
	while (root) {
	cout<<root->val<<"->";
	root=root->next;}
	cout<<endl;
	}
int main() {
	Solution m;
	ListNode* l1=new ListNode(2);
	ListNode* l2=new ListNode(1);
	l1->next=l2;
	ListNode* root=m.partition(l1,2);
	print(root);
	}
