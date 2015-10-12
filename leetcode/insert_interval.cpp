#include <iostream>
#include <vector>
using namespace std;
struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        if (intervals.empty()) {
            result.push_back(newInterval);
            return result;}
        for (int i=0;i<intervals.size();i++) {
            if ((intervals[i].start>=newInterval.start && intervals[i].start <=newInterval.end) || (intervals[i].end>=newInterval.start && intervals[i].end<=newInterval.end) || (intervals[i].start<=newInterval.start && intervals[i].end>=newInterval.end) ) {
                newInterval.end=intervals[i].end<newInterval.end? newInterval.end:intervals[i].end;
                newInterval.start=intervals[i].start<newInterval.start? intervals[i].start:newInterval.start;
		if (i==intervals.size()-1) result.push_back(newInterval);
            }
            else if (intervals[i].end<newInterval.start) {
		result.push_back(intervals[i]);
		if (i==intervals.size()-1) result.push_back(newInterval);
		}
            else if (intervals[i].start>newInterval.end) {
                result.push_back(newInterval); 
                for (;i<intervals.size();i++) 
                    result.push_back(intervals[i]);
                }
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
	Interval a(1,5);
/*	Interval b(3,5);
	Interval c(6,7);
	Interval d(8,10);
	Interval e(12,16);*/
	Interval newInterval(2,3);
	vector<Interval> intervals;
	intervals.push_back(a);
/*	intervals.push_back(b);
	intervals.push_back(c);
	intervals.push_back(d);
	intervals.push_back(e);*/
	print(intervals);
	Solution m;
	vector<Interval> result=m.insert(intervals,newInterval);
	print(result);
	}
	
