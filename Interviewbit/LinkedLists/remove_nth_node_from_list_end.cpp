/*
https://www.interviewbit.com/problems/remove-nth-node-from-list-end/
Remove Nth Node from List End
Asked in:  HCL, Amazon
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode *ptr1 = A, *ptr2 = A;
    while(ptr2->next!=NULL && B>0){
        ptr2 = ptr2->next;
        B--;
        // cout<<B<<endl;
    }
    if(B){
        ptr1 = ptr1->next;
        // cout<<"here"<<endl;
        return ptr1;
    }else{
        while(ptr2->next!=NULL){
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
        ListNode* ptr3 = ptr1;
        ptr1 = ptr1->next;
        ptr3->next = ptr1->next;
    }
    return A;
}
