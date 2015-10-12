#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        UndirectedGraphNode *newnode=new UndirectedGraphNode(node->label);
        if (node->neighbors.empty()) return newnode;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        stack<UndirectedGraphNode*> sta;
        map[node]=newnode;
        sta.push(node);
        while (!sta.empty()) {
            UndirectedGraphNode * cur= sta.top();
            sta.pop();
            for (int i=0;i<cur->neighbors.size();i++) {
                unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator it=map.find(cur->neighbors[i]);
                if (it==map.end()) { 
                    map[cur->neighbors[i]]=new UndirectedGraphNode(cur->neighbors[i]->label);
                    sta.push(cur->neighbors[i]);}
                map[cur]->neighbors.push_back(map[cur->neighbors[i]]);
        }
	}
        return map[node];
    }
};

void print(UndirectedGraphNode* cur) {
	if (!cur) return;
		cout<<cur->label<<", ";
		for (int i=0;i<cur->neighbors.size();i++) 
			cout<<cur->neighbors[i]->label<<", ";
		cout<<"# ";
		for (int i=0;i<cur->neighbors.size();i++) 
			if (cur!=cur->neighbors[i]) 
				print(cur->neighbors[i]);

	cout<<endl;
	}

int main() {
	UndirectedGraphNode* node1=new UndirectedGraphNode(0);
	UndirectedGraphNode* node2=new UndirectedGraphNode(1);
	UndirectedGraphNode* node3=new UndirectedGraphNode(2);
	node1->neighbors.push_back(node2);
	node1->neighbors.push_back(node3);
	node2->neighbors.push_back(node3);
	node3->neighbors.push_back(node3);
	print(node1);
	Solution m;
	UndirectedGraphNode* newhead=m.cloneGraph(node1);
	print(newhead);
	}
	
	
		
