#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};
node* initHead(int data){
    node* head = new node();
    head->data = data;
    head->next = NULL;
    head->prev = NULL;
    return head;
}
node* initTail(node* head){
    node* tail = head;
    return tail;
}
node* addToTail(int data, node* tail){
    node* temp = new node();
    temp->data = data;
    temp->next = NULL;
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    return tail; 
}
node* addToHead(int data, node* head){
    node* temp = new node();
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
    return head;
}
void printList(node* head){
	cout<<"Forward Print"<<endl;
	for(auto i=head;i!=NULL;i = i->next){
		cout<<i->data<<" ";
	}
	cout<<endl;
}
void printReverseList(node* tail){
	stack<int>myStack;
	cout<<"Reverse Print"<<endl;
	for(auto i = tail; i!=NULL;i = i->prev){
		myStack.push(i->data);
	}
	// cout<<"Size : "<<myStack.size()<<endl;
	while(!myStack.empty()){
		cout<<myStack.top()<<" ";
		myStack.pop();
	}
	cout<<endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    node* head = NULL;
    node* tail = NULL;
    int n, q, dataVal, start, finish, type;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>dataVal;
        if(head==NULL){
            head = initHead(dataVal);
            tail = initTail(head);
			// printList(head);
        }else{
        	tail = addToTail(dataVal, tail);
			// printList(head);
        }
    }
    // for(node* i = head; i!=tail->next;i = i->next){
    //     cout<<i->data<<" ";
    // }
    for(int j = 0; j < q; j++){
        cin>>type>>start>>finish;
        node* startNode;
        node* finishNode;
        node* ptr = head;
        for(auto i = 0; ptr!=NULL; i++, ptr = ptr->next){
            if(i==start-1)startNode = ptr;
            else if(i==finish-1){
                finishNode = ptr;
                break;
            }
        }
        if(startNode==head && finishNode==tail){
			cout<<"head==tail"<<endl;
			continue;
			}
        else if(type==1){
            if(finishNode!=tail && startNode!=head){
                (startNode->prev)->next = finishNode->next;
                (finishNode->next)->prev = startNode->prev;
                finishNode->next = head;
				head->prev = finishNode;
                startNode->prev = NULL;
                head = startNode;
            }else if(finishNode == tail){
                (startNode->prev)->next = NULL;
                tail = startNode->prev;
                startNode->prev = NULL;
                finishNode->next = head;
                head->prev = finishNode;
                head = startNode;
            }else if(startNode == head){
				cout<<"start==head"<<endl;
				continue;
			}
        }else if(type==2){
            if(startNode!=head && finishNode!=tail){
                (startNode->prev)->next = finishNode->next;
                (finishNode->next)->prev = startNode->prev;
                tail->next = startNode;
				startNode->prev = tail;
                finishNode->next = NULL;
                tail = finishNode;
            }else if(startNode==head){
                (finishNode->next)->prev = NULL;
                startNode->prev = tail;
                tail->next = startNode;
                head = finishNode->next;
                finishNode->next = NULL;
                tail = finishNode;
            }else if(finishNode==tail){
				cout<<"finish==tail"<<endl;
				continue;
			}
        }
		printList(head);
		printReverseList(tail);
    }
    cout<<abs(head->data-tail->data)<<endl;
    for(auto i=head;i!=tail->next;i = i->next){
		if(i!=tail)
        cout<<i->data<<" ";
		else 
		cout<<i->data;
    }
	cout<<endl;
	// printReverseList(tail);
    return 0;
}
