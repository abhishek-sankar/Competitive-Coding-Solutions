/*
https://www.interviewbit.com/problems/merge-overlapping-intervals/
Merge Overlapping Intervals
Asked in:  Google, Amazon
Given a collection of intervals, merge all overlapping intervals.

For example:
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
Make sure the returned intervals are sorted.

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool checkA(Interval a, Interval b){
    return a.end<b.end;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end(), checkA);
    for(int i=A.size()-1;i>=1;i--){
        if(A[i].start <= A[i-1].end){
            // cout<<A[i].start<<" : "<<A[i].end<<" and "<<A[i-1].start<<" : "<<A[i-1].end<<endl;
            int small = min(A[i-1].start, A[i].start);
            int large = max(A[i].end, A[i-1].end);
            Interval temp = {small, large};
            // cout<<temp.start<<" : "<<temp.end<<endl;
            A.erase(A.begin()+i-1);
            A.erase(A.begin()+i-1);
            A.insert(A.begin()+i-1, temp);
        }
    }
    return A;
    
}
