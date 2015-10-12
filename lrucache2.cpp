#include <iostream>
#include <unordered_map>
using namespace std;
struct Node {
        int val;
        int key;
        Node *next;
        Node *prev;
        Node(int k, int v):key(k),val(v) {}
    };
    
class LRUCache{
    private:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> hashmap;
    
    void insertToEnd(int key, int value) {
        if(isFull() || hashmap.find(key)!=hashmap.end()) return;
        Node *nd = new Node(key, value);
        hashmap[key] = nd;
        if(!head) {
            head = tail = nd;
        }
        else {
            tail->next = nd;
            nd->prev = tail;
            tail = tail->next;
        }
    } 
    
    void removeHead() {
        if(!head) return;
        hashmap.erase(head->key);
        Node *temp = head;
        if(head==tail) 
            head = tail = NULL;
        else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    void moveToEnd(int key) {
         if(hashmap.find(key)==hashmap.end() || hashmap[key]==tail) return;
         Node *nd = hashmap[key];
        if (nd==head) {
           head = head->next;
           head->prev = NULL;
                         }
        else {
           nd->prev->next = nd->next;
           nd->next->prev = nd->prev; 
           }
        tail->next = nd;
        nd->prev = tail;
        nd->next = NULL;
        tail = tail->next;
         }
    public:
      LRUCache(int capacity) {
      this->capacity = capacity;
       head=NULL;
	tail=NULL;
	hashmap.clear();}
      int get(int key) {
       if(hashmap.find(key)==hashmap.end()) return -1;
       moveToEnd(key);
       return hashmap[key]->val;
        }
        
        void set(int key, int value) {
        if(get(key)!=-1) {
        hashmap[key]->val = value;
        return;
        }
        
        if(isFull()) removeHead();
        insertToEnd(key, value);
        }
        
        bool isFull() {
        return hashmap.size()>=capacity;
        }
        };
int main() {
	LRUCache* m=new LRUCache(2);
	m->set(2,1);
	m->set(1,1);
	m->set(2,3);
	m->set(4,1);
	cout<<m->get(1)<<endl;
	cout<<m->get(2)<<endl;
	cout<<m->get(2)<<endl;
	cout<<m->get(1)<<endl;
	}
