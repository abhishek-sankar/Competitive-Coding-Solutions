/**
 * https://www.interviewbit.com/courses/programming/topics/arrays/
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 You may assume that the intervals were initially sorted according to their start times.

 Example 1:
 Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 * /


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval n) {
    
    if(n.start>n.end){
        int temp = n.start;
        n.start = n.end;
        n.end = temp;
    }
    int start_in_interval = -1;
    int end_in_interval = -1;
    for(int i=0;i<intervals.size();i++){
        if(n.start >= intervals[i].start && n.start <= intervals[i].end)start_in_interval = i;
        if(n.end >= intervals[i].start && n.end <= intervals[i].end)end_in_interval = i;
    }
    if((start_in_interval == end_in_interval) && (start_in_interval != -1))return intervals;
    if(start_in_interval != -1 && end_in_interval != -1){
        Interval in = {intervals[start_in_interval].start, intervals[end_in_interval].end};
        int i;
        for(i = end_in_interval; i >= start_in_interval; i--){
            intervals.erase(intervals.begin()+i);
        }
        intervals.insert(intervals.begin()+i+1, in);
    } else if (start_in_interval == -1 && end_in_interval != -1){
        int i;
        for(i = 0; i < intervals.size(); i++){
            if(i!=intervals.size()-1){            
                if(intervals[i].end <= n.start && intervals[i+1].start >= n.start ) // insert at i+1
                    start_in_interval = i;
            }else{
                if(intervals[i].end <= n.start)
                start_in_interval = i;
            }
        }
        Interval in = {n.start, intervals[end_in_interval].end};
        for(i=end_in_interval;i>start_in_interval;i--){
            intervals.erase(intervals.begin()+i);
        }
        intervals.insert(intervals.begin()+i+1, in);
    } else if (end_in_interval == -1 && start_in_interval !=-1){
        for(int i = 0; i < intervals.size(); i++){// check if insertion at ends
            if(i<intervals.size()-1){
                if(intervals[i].end <= n.end && intervals[i+1].start >= n.end ) 
                    end_in_interval = i;
            }else{
                if(intervals[i].end <= n.end){
                    end_in_interval = i;
                    // cout<<endl<<"Yes"<<endl;
                }
            }
        }
        Interval in = {intervals[start_in_interval].start, n.end};
        int i;
        for(i=end_in_interval;i>=start_in_interval;i--){
            intervals.erase(intervals.begin()+i);
        }
        intervals.insert(intervals.begin()+i+1,in);//check this
    } else {
        for(int i=0;i<intervals.size();i++){
            if(i!=intervals.size()-1){
                if(intervals[i].end <= n.start && intervals[i+1].start >= n.start){
                    start_in_interval = i;
                }
            }else{
                if(intervals[i].end <= n.start){
                    start_in_interval = i;
                }
            }
        }
        for(int i=0;i<intervals.size();i++){
            if(i!=intervals.size()-1){
                if(intervals[i].end <= n.end && intervals[i+1].start >= n.end){//chech here latest
                    end_in_interval = i;
                }
            }else{
                if(intervals[i].end <= n.end){
                    end_in_interval = i;
                }
            }
        }
        
        Interval in = {n.start, n.end};
        int i = end_in_interval;
        if(start_in_interval!=end_in_interval)
        for(;i>start_in_interval;i--)
            intervals.erase(intervals.begin()+i);
        intervals.insert(intervals.begin()+i+1, in);
    }
    return intervals;
}
    
    
    
    
    
