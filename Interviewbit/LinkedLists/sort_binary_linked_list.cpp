/*
https://www.interviewbit.com/problems/sort-binary-linked-list/

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    ListNode *ptr = A;
    if(A==NULL)return A;
    int count_1 = 0, count_elements = 0;
    
    for(;ptr!=NULL;){
        if(ptr->val==1)count_1+=1;
        // cout<<ptr->val<<" Done"<<endl;
        count_elements+=1;
        ptr = ptr->next;
    }
    ptr = A;
    int diff = count_elements - count_1;
    for(;ptr!=NULL;){
        // cout<<ptr->val<<" Done"<<endl;
        if(diff<=0){
            ptr->val = 1;
        }
        else{
            ptr->val = 0;
        }
        diff--;
        ptr = ptr->next;
    }
    return A;
}
