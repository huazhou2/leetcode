#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> result;
        bool circle=false;
        vector<int> visited(numCourses,0);
        for (int i=0;i<numCourses;i++)  {
            if (!visited[i]) 
                visit(i,visited,result,prerequisites,circle);
        }
        if (circle) result.clear();
        return result;
    }
    void visit(int v, vector<int>& visited,vector<int>& result, vector<pair<int,int> >& neighbors, bool& circle) {
        if (circle) return;
        visited[v]=1;
        for (int i=0;i<neighbors.size();i++) {
            if (neighbors[i].first==v) {
                int tovisit=neighbors[i].second;
                if (visited[tovisit]==1) {
                    circle=true;
                    return;}    
                else if (visited[tovisit]==0) 
                    visit(tovisit,visited,result,neighbors,circle);
            }
        }
        result.push_back(v);
        visited[v]=2;
    }
};
void print(const vector<int>& nums) {
	if (nums.empty()) return;
	for (int i=0;i<nums.size();i++) 
		if (i==nums.size()-1)
			cout<<nums[i]<<endl;
		else 
			cout<<nums[i]<<" -> ";
		}

int main() {
	vector<pair<int,int> > prerequisites;
	prerequisites.push_back(std::make_pair<int,int>(1,0));
	prerequisites.push_back(std::make_pair<int,int>(2,0));
	prerequisites.push_back(std::make_pair<int,int>(3,1));
	prerequisites.push_back(std::make_pair<int,int>(3,2));
	Solution m;
	vector<int> result=m.findOrder(4,prerequisites);
	print(result);
	}
