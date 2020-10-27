/*
https://www.interviewbit.com/problems/wave-array/
Wave Array
Asked in:  Google, Adobe, Amazon

Given an array of integers, sort the array into a wave like array and return it,
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example
Given [1, 2, 3, 4]
One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
 NOTE : If there are multiple answers possible, return the one thats lexicographically smallest.
So, in example case, you will return [2, 1, 4, 3] 
*/

vector<int> Solution::wave(vector<int> &A) {
    vector<int> res;
    vector<int>sub_1;
    vector<int>sub_2;
    sort(A.begin(), A.end());
    for(int i=0;i<A.size();i++){
        if(i%2==0){
            sub_1.push_back(A[i]);
            // cout<<"Addind to sub_1: "<<A[i]<<endl;
        }else{
            sub_2.push_back(A[i]);
            // cout<<"Addind to sub_2: "<<A[i]<<endl;
        }
    }
    int j=0;
    while(res.size()<A.size()){
        if(j<sub_2.size()){
            res.push_back(sub_2[j]);
            // cout<<"Adding to res2: "<<sub_2[j]<<endl;
        }
        if(j<sub_1.size()){
            res.push_back(sub_1[j]);
            // cout<<"Adding to res1: "<<sub_1[j]<<endl;
        }
        j++;
    }
    return res;
}
