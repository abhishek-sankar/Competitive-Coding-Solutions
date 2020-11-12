/*
https://www.interviewbit.com/problems/sort-list/
Sort List
Asked in:  Google
Sort a linked list in O(n log n) time using constant space complexity.

Example :
Input : 1 -> 5 -> 4 -> 3
Returned list : 1 -> 3 -> 4 -> 5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::sortList(ListNode* A) {
    vector<int>res;
    ListNode* ptr = A;
    while(ptr!=NULL){
        res.push_back(ptr->val);
        ptr = ptr->next;
    }
    sort(res.begin(), res.end());
    ptr = A;
    int start = 0;
    while(ptr!=NULL){
        ptr->val = res[start++];
        ptr = ptr->next;
    }
    return A;
}
