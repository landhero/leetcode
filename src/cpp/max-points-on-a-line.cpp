/** 
* try to solve it not using hashmap with double/float as its key, O(n^2*logn)
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
	int maxPoints(vector<Point> &);
};
bool stupidCompare(Point x, Point y){ 
    if (1.0*x.x*y.x >= 0.0)
		return 1.0*x.y*y.x < 1.0*x.x*y.y;
	return 1.0*x.y*y.x > 1.0*x.x*y.y;
}
bool moreStupidCompare(Point x, Point y){
    return x.x==y.x? x.y<y.y:x.x<y.x;
}
bool stupidEqual(Point x, Point y ){
    return x.y * y.x == x.x * y.y;
}
int Solution::maxPoints(vector<Point> & points){
    if (points.size()<=2)
        return points.size();
    int rlt = 0;
    sort(points.begin(),points.end(), moreStupidCompare);
    for (vector<Point>::iterator itr = points.begin(); itr!=points.end();){
        int num = 1;
        for (vector<Point>::iterator i = itr+1; i!=points.end() && i->x == itr->x && i->y == itr->y;i++)
            ++num; // same points
        vector<Point> deltas; //records all the delta X, delta Y based on the current point
        for (vector<Point>::iterator i = itr+num; i!= points.end(); i++){
            deltas.push_back (Point( (*i).x-(*itr).x, (*i).y-(*itr).y ) );
        }
        sort(deltas.begin(),deltas.end(), stupidCompare);
        int max = 0;
        for (vector<Point>::iterator i = deltas.begin(); i != deltas.end();){
            int c = 1;
            for (vector<Point>::iterator j=i+1; j!=deltas.end() && stupidEqual(*i, *j); j++)
                ++c;
            i += c;
            if (max<c)
                max = c;
        }
        if (rlt< max+num)
            rlt = max +num;
        itr += num;
        if (rlt >= points.end()-itr)
            break;
    }
    return rlt;
}