#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<pair<int,int> > result;
        if (buildings.empty()) return result;
        vector<pair<int,int> > points;
        for (int i=0;i<buildings.size();i++) {
            points.push_back(std::pair<int,int> (buildings[i][0],-buildings[i][2]));
            points.push_back(std::pair<int,int> (buildings[i][1],buildings[i][2]));
        }
        std::sort(points.begin(),points.end(),mycmp);
	for (int i=0;i<points.size();i++) 
		cout<<points[i].first<<" "<<points[i].second<<"; ";
	cout<<endl;
        multiset<int> height;
        int cur=0;
        for (int i=0;i<points.size();i++) {
            if (points[i].second<0) height.insert(-points[i].second);
            else height.erase(height.find(points[i].second));
	    int newheight;
	    if (height.empty()) 
		newheight=0;
	    else 
                newheight=*(--height.end());
		cout<<newheight<<endl;
            if (newheight!=cur) result.push_back(pair<int,int>(points[i].first,newheight));
            cur=newheight;
        }
        return result;
    }
private:
    struct cmp_coordinate {
        bool operator() (const pair<int,int> a, const pair<int,int> b) {
	    if (a.first==b.first) return a.second<b.second;
            else return a.first<b.first;
        }
    } mycmp;
};
void print(const vector<pair<int,int> >& nums) {
	if (nums.empty()) return;
	for (int i=0;i<nums.size();i++) 
	cout<<nums[i].first<<"  "<<nums[i].second<<";  ";
	cout<<endl;
	}
int main() {
	int a[]={0,2,3};
	int b[]={2,5,3};
//	int c[]={3,200,18};
//	int d[]={4,200,17};
//	int e[]={5,200,16};
	vector<int> a1(a,a+sizeof(a)/sizeof(int));
	vector<int> b1(b,b+sizeof(b)/sizeof(int));
//	vector<int> c1(c,c+sizeof(c)/sizeof(int));
//	vector<int> d1(d,d+sizeof(d)/sizeof(int));
//	vector<int> e1(e,e+sizeof(e)/sizeof(int));
	vector<vector<int> > buildings;
	buildings.push_back(a1); 
	buildings.push_back(b1); 
//	buildings.push_back(c1); 
//	buildings.push_back(d1); 
//	buildings.push_back(e1); 
	Solution m;
	vector<pair<int,int> > result=m.getSkyline(buildings);
	print(result);
	}
	

	
