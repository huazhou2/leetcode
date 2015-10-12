#include <iostream>
#include <unordered_map>
using namespace std;
struct Node {
    int key;
    int val;
    Node* prev, *next;
    Node() {};
    Node (int k1,int k2) :key(k1), val(k2) {};
};

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capicity=capacity;
        head=NULL;
        tail=NULL;
        hashmap.clear();
    }
    int get(int key) {
        unordered_map<int,Node*>::iterator it=hashmap.find(key);
        if (it==hashmap.end()) return -1;
        else {
            update(key);
            return it->second->val;
        }
    }
    
    void set(int key, int value) {
        if (hashmap.find(key)!=hashmap.end()) {
            hashmap[key]->val=value;
            update(key);
        }
        else insert(key,value);
    }
    
private:
    Node* head;
    Node* tail;
    unordered_map<int,Node*> hashmap;
    int capicity;
    void update(int key) {
        if (hashmap[key]==head) return;
        if (hashmap[key]->next) {
        Node* temp=hashmap[key]->next;
        hashmap[key]->next=head;
        hashmap[key]->prev->next=temp;
        temp->prev=hashmap[key]->prev;
        head->prev=hashmap[key];
        head=hashmap[key];
        head->prev=NULL;}
        else {
            tail->next=head;
            head->prev=tail;
            head=tail;
            tail=tail->prev;
            tail->next=NULL;
        }
    }
    void insert(int key,int val) {
        if (hashmap.size()==capicity) {
            if (hashmap.size()==1) {
                head=tail=NULL;
                hashmap.clear();}
            else {
            tail=tail->prev;
            hashmap.erase(tail->next->key);
            tail->next=NULL;
            }
        } 
        Node* temp=new Node(key,val);
        hashmap[key]=temp;
        if (hashmap.size()==1) {
            tail=temp;
            head=temp;}
        else {temp->next=head;
        head->prev=temp;
        head=temp;
        }
    }
};
int main() {
	LRUCache m(2);
	m.set(2,1);
	m.set(1,1);
	m.set(2,3);
	m.set(4,1);
	cout<<m.get(1)<<endl;
	cout<<m.get(2)<<endl;
	cout<<m.get(4)<<endl;
	}
