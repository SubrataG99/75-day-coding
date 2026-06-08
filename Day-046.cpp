/*
Problem name : << Delete Nodes with Greater on Right >>

Given a singly linked list, remove all nodes that have a node with a greater value anywhere to their right in the list. Return the head of the modified linked list.

Examples:
Input: LinkedList = 12->15->10->11->5->6->2->3
Output: 15->11->6->3
Explanation: Since, 12, 10, 5 and 2 are the elements which have greater elements on the following nodes. So, after deleting them, the linked list would like be 15, 11, 6, 3.

Input: LinkedList = 10->20->30->40->50->60
Output: 60
Explanation: All the nodes except the last node has a greater value node on its right, so all the nodes except the last node must be removed.
*/

// ==============================================> Solution

/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution
{
    public:
    Node *revList(Node *head)
    {
        Node *curr = head;
        Node *prev = nullptr;
        Node *next;
        while(curr != nullptr)
        {
            // Simply reverse the direction of linkedlist to reverse it
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // The end will be start now
        return prev;
    }
    
    Node *compute(Node *head)
    {
        head = revList(head);
        Node *curr = head;
        Node *maxNode = head;
        Node *temp;
        // Traverse till it is end
        while((curr != nullptr) && (curr->next != nullptr))
        {
            if(curr->next->data < maxNode->data)
            {
                // Skip if small
                temp = curr->next;
                curr->next = temp->next;
                delete(temp);
            }
            else
            {
                // Continue the series if normal
                curr = curr->next;
                maxNode = curr;
            }
        }
        // Re-reverse to get original orer with skipped elements
        return revList(head);
    }
};
