#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
class operation {
	public:
	bool operator() (Interval a, Interval b) {return (a.start<b.start);}
	} myoperation;
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.empty()) return result;
	std::sort(intervals.begin(),intervals.end(),myoperation);
        result.push_back(intervals[0]);
        for (int i=1;i<intervals.size();i++) {
            if (intervals[i].start>=result.back().start && intervals[i].start<=result.back().end) { 
                if (result.back().end<intervals[i].end) result.back().end=intervals[i].end;
		}
	else result.push_back(intervals[i]);
	
            }
        return result;
        }
};
void print(const vector<Interval>& result) {
	if (result.empty()) return;
	for (int i=0;i<result.size();i++) 
		cout<<result[i].start<<"->"<<result[i].end<<"\t";
	cout<<endl;}

int main() {
	Interval a(1,3);
	Interval b(2,6);
	Interval c(8,10);
	Interval d(15,18);
	vector<Interval> intervals;
	intervals.push_back(a);
	intervals.push_back(b);
	intervals.push_back(c);
	intervals.push_back(d);
	print(intervals);
	Solution m;
	vector<Interval> result=m.merge(intervals);
	print(result);
	}
	
	

