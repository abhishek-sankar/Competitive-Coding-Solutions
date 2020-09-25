#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node();
	Node(int d)
	{
		data = d;
	}
	Node *addToTail(int data, Node *head);
	void printAllNodes(Node *head);
	Node *removeDuplicates(Node *head);
};
Node *Node::addToTail(int data, Node *head)
{
	Node *node = new Node(data);
	Node *temp = head;
	if (head == NULL)
	{
		head = node;
		return head;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = node;
	node->next = NULL;
	return head;
}
void Node::printAllNodes(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << "->";
		head = head->next;
	}
	cout << "NULL\n";
}
Node *Node::removeDuplicates(Node *head)
{
	Node *temp = head;
	map<int, int> nodeMap;
	if (head != NULL)
		nodeMap[head->data] = 1;
	while (head->next != NULL)
	{
		if (nodeMap.find((head->next)->data) == nodeMap.end())
		{
			nodeMap[((head->next)->data)] = 1;
			head = head->next;
		}
		else
		{
			Node *temp = head;
			while (head->next != NULL && nodeMap.find((head->next)->data) != nodeMap.end())
			{
				head = head->next;
			}
			if (head->next == NULL)
			{
				temp->next = NULL;
			}
			else
			{
				temp->next = head->next;
				head = head->next;
				nodeMap[head->data] = 1;
			}
		}
	}
	return temp;
}
int returnKthLastElement(Node *head, int k)
{
	int count = 0;
	queue<int> kLastElements;
	Node *temp = head;
	while (head != NULL)
	{
		if (kLastElements.size() == k)
		{
			kLastElements.pop();
		}
		kLastElements.push(head->data);
		count++;
		head = head->next;
	}
	if (count >= k)
		return kLastElements.front();
	else
		return -1;
}
void deleteNodeMiddle(Node *node)
{
	node->data = (node->next)->data;
	node->next = (node->next)->next;
}
Node *partitionWithRespectToValue(Node *head, int x)
{
	Node *newLesserHead = NULL;
	Node *newLesserTail = newLesserHead;
	Node *newGreaterHead = NULL;
	Node *newGreaterTail = newGreaterHead;
	while (head != NULL)
	{
		if (head->data >= x)
		{
			//insert at newGreaterTail
			if (newGreaterTail == NULL)
			{
				newGreaterHead = new Node(head->data);
				newGreaterTail = newGreaterHead;
			}
			else
			{
				Node *newNode = new Node(head->data);
				newGreaterTail->next = newNode;
				newNode->next = NULL;
				newGreaterTail = newNode;
			}
		}
		else
		{
			//insert at newLesserTail
			if (newLesserHead == NULL)
			{
				newLesserHead = new Node(head->data);
				newLesserTail = newLesserHead;
			}
			else
			{
				Node *newNode = new Node(head->data);
				newLesserTail->next = newNode;
				newNode->next = NULL;
				newLesserTail = newNode;
			}
		}
		head = head->next;
	}
	newLesserTail->next = newGreaterHead;
	return newLesserHead;
}
int getDigitTypeOne(Node *head)
{
	int num = 0;
	while (head != NULL)
	{
		num += head->data;
		num *= 10;
		head = head->next;
	}
	return num;
}
Node *makeLinkedListTypeOne(int sum)
{
	Node *head = new Node();
	Node *mytemp = head;
	head->data = sum % 10;
	head->next = NULL;
	while (sum /= 10)
	{
		Node *temp = new Node(sum % 10);
		mytemp->next = temp;
		temp->next = NULL;
		mytemp = temp;
	}
	return head;
}
Node *sumListsByDigit(Node *head1, Node *head2, int type)
{
	if (type == 1)
	{
		int numFirst = getDigitTypeOne(head1);
		int numSecond = getDigitTypeOne(head2);
		int sum = numFirst + numSecond;
		return makeLinkedListTypeOne(sum);
	}
}
int main()
{
	Node *head = new Node(1);
	head = head->addToTail(3, head);
	head = head->addToTail(4, head);
	Node *temp = head->next->next;
	head = head->addToTail(1, head);
	head = head->addToTail(5, head);
	head->printAllNodes(head);
	cout << returnKthLastElement(head, 10) << endl;
	// head = head->removeDuplicates(head);
	head = partitionWithRespectToValue(head, 3);
	head->printAllNodes(head);
	// deleteNodeMiddle(temp);
	// head->printAllNodes(head);
	return 0;
}