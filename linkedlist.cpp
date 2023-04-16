#include <iostream>
using namespace std;
 
struct Node
{
   int data;
   struct Node *next;
};


void push(struct Node** head, int node_data)
{
   struct Node* newNode = new Node;

   newNode->data = node_data;
   newNode->next = (*head);
   (*head) = newNode;
}
 

void insertAfter(struct Node* prev_node, int node_data)
{
    if (prev_node == NULL)
    {
        cout<<"Node before it is needed";
        return;
    } 
   struct Node* newNode =new Node; 

   newNode->data = node_data;
   newNode->next = prev_node->next;
   prev_node->next = newNode;
}
 
void end(struct Node** head, int node_data)
{
struct Node* newNode = new Node;
struct Node *last = *head;

newNode->data = node_data;
newNode->next = NULL;

if (*head == NULL)
{
    *head = newNode;
    return;
}
 
 
while (last->next != NULL)
    last = last->next;
 
last->next = newNode;
return;

}
 

void displayList(struct Node *node)
{
    cout<<"List: "<<endl;
   while     (node != NULL)
   {
      cout<<node->data<<"-->";
      node = node->next;
   }
 
    if(node== NULL)
    cout<<"null"; 
} 


Node* deleteFirstNode(struct Node* head)
{
   if (head == NULL)
   return NULL;
    Node* tempNode = head;
   head = head->next;
   delete tempNode;
 
   return head;
}

Node* removeLastNode(struct Node* head)
{
   if (head == NULL)
   return NULL;
 
   if (head->next == NULL) {
      delete head;
      return NULL;
   }
 
Node* second_last = head;
while (second_last->next->next != NULL)
second_last = second_last->next;
 
delete (second_last->next);
 
second_last->next = NULL;
 
return head;
}
 



int main() 
{ 
struct Node* head = NULL; 

int ch;

end(&head, 10);
push(&head, 20); 
push(&head, 30); 
end(&head, 40); 
insertAfter(head->next, 50);
 

displayList(head);

         Node* temp;


   head = deleteFirstNode(head);
   cout<<endl<<"After deleting head node"<<endl; 
   displayList(head);
 
   head = removeLastNode(head);
   cout<<endl<<"After deleting last node"<<endl;
   displayList(head);
 
return 0;
}