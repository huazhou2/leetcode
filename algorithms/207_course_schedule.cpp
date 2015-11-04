#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        for (int i=0;i<numCourses;i++) 
            if (!visited[i]) 
            if (!visit(i,visited, prerequisites)) return false;
        return true;
    }
    bool visit(int v, vector<int>& visited, vector<pair<int,int> >& neighbors) {
        visited[v]=1;
        for (int i=0;i<neighbors.size();i++) {
            if (neighbors[i].first==v) {
                int tovisit=neighbors[i].second;
                if (visited[tovisit]==1) return false;
                if (!visited[tovisit])
                 if (!visit(tovisit,  visited, neighbors)) return false;;
            }}
        visited[v]=2;
        return true;
    }
};

int main() {
	vector<pair<int, int> > prerequisites;
	prerequisites.push_back(std::make_pair<int,int> (0,1));
	//prerequisites.push_back(std::make_pair<int,int> (1,0));
	Solution m;
	bool can=m.canFinish(2,prerequisites);
	can? cout<<"Yes"<<endl: cout<<"No"<<endl;
	}
