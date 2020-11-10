/*
https://www.interviewbit.com/problems/rotate-list/
Rotate List
Asked in:  Amazon
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int count = 0;
    ListNode* ptr = A;
    ListNode* end, *ret;
    if(A==NULL)return A;
    while(ptr!=NULL){
        if(ptr->next==NULL){
            end = ptr;
        }
        count++;
        ptr = ptr->next;
    }
    B = B%count;
    ptr = A;
    int current_count = 0;
    while(current_count+1<count - B){
        ptr = ptr->next;
        current_count++;
    }
    end->next = A;
    ret = ptr->next;
    ptr->next = NULL;
    return ret;
}
