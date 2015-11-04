/**
 *  * Definition for a point.
 *   * struct Point {
 *    *     int x;
 *     *     int y;
 *      *     Point() : x(0), y(0) {}
 *       *     Point(int a, int b) : x(a), y(b) {}
 *        * };
 *         */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size()<=2) return points.size();
        int max=2;
        for (int i=0;i<points.size()-1;i++) {
            unordered_map<float,int> map;
            int temp_map=1;
            int thesame=0;
            int vertical=0;
            for (int j=i+1;j<points.size();j++) {
                if (points[j].x==points[i].x)
                    if (points[j].y==points[i].y) thesame++;
                    else vertical++;
                else {
                float slope=(points[j].y-points[i].y+0.0)/(points[j].x-points[i].x);
                    if (map.find(slope)==map.end()) map[slope]=1;
                    else map[slope]++;
                }
                    
                }
        temp_map+=thesame;
        int temp=temp_map+vertical;
        max=max>temp?max:temp;
        for (unordered_map<float,int>::iterator it=map.begin();it!=map.end();it++) 
            {temp=temp_map+it->second;
            max=max>temp?max:temp;}
        }
        return max;
    }
};
