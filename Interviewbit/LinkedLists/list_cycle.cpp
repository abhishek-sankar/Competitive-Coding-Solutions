/*
https://www.interviewbit.com/problems/list-cycle/
List Cycle
Asked in:  Amazon, Microsoft, NetApp
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Try solving it using constant additional space.

Example :
Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode *ptr1 = A;
    map<ListNode*, int>m;
    while(ptr1!=NULL){
        if(m.find(ptr1)!=m.end()){
            // cout<<"Duplicate is "<<ptr1->val<<endl;
            return ptr1;
        }else{
            m.insert({ptr1, 1});
            // cout<<"Inserting "<<ptr1->val<<endl;
        }
        ptr1 = ptr1->next;
    }
    // cout<<"No duplicates"<<endl;
    return NULL;
}
