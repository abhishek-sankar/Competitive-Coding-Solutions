/*
https://www.interviewbit.com/problems/kth-node-from-middle/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    int count = 0;
    ListNode *ptr = A;
    for(;ptr!=NULL;){
        count+=1;
        ptr = ptr->next;
    }
    ptr = A;
    if((count/2)+1 <= B)return -1;
    else {
        int val = (count/2)-1 - B;
        for(int i=0;i<=val;i++){
            ptr = ptr->next;
        }
    }
    return ptr->val;
}
