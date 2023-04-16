#include <bits/stdc++.h>
using namespace std;

struct node{
    
   int data;
    node *prev;
    node *next;
    
};

void insert_at_front(node** head, int data){
    
    node* new_node = new node();
    new_node->data = data;
    
    new_node->prev = NULL;
    
    new_node->next = (*head);
    
    if((*head) != NULL){
        (*head)->prev = new_node;
    }
    
    (*head) = new_node;
    
    return;
    
}

void insert_after_given_node(node* given_node, int data){
    
    node* new_node = new node();
    new_node->data = data;
    
    new_node->next = given_node->next;
    
    given_node->next = new_node;
    
    new_node->prev = given_node;
    
    if(new_node->next != NULL){
        new_node->next->prev = new_node;
    }
    
    return;
    
}


void insert_at_end(node** head, int data){
    
    node* new_node = new node();
    new_node->data = data;
    
    new_node->next = NULL;
    
    if((*head) == NULL){
        new_node->prev = NULL;
    }
    
    node* end = (*head);
    
    while(end->next != NULL){
        end = end->next;
    }
    
    end->next = new_node;
    
    new_node->prev = end;
    
    return;
    
}




node* deleteFirstNode(struct node* head)
{
   if (head == NULL)
   return NULL;
    node* tempNode = head;
   head = head->next;
   delete tempNode;
 
   return head;
}

node* removeLastNode(struct node* head)
{
   if (head == NULL)
   return NULL;
 
   if (head->next == NULL) {
      delete head;
      return NULL;
   }
 
node* second_last = head;
while (second_last->next->next != NULL)
second_last = second_last->next;
 
delete (second_last->next);
 
second_last->next = NULL;
 
return head;
}


void delete_given_node(node** head, node* given_node){
    
    if(given_node == (*head)){
        (*head) = given_node->next;
    }
    
    given_node->prev->next = given_node->next;
    
    if(given_node->next == NULL){
        return;
    }
    
    given_node->next->prev = given_node->prev;
    
    return;
}

void display(struct node *head,struct node *end){
        while(head != NULL){
        end = head;
        cout<<head->data<<" ";
        head = head->next;
    }
}


int main() {
    
    
    struct node *head = NULL;
    
    struct node *end = NULL;
    
    insert_at_front(&head, 1);
    insert_at_front(&head, 2);
    insert_at_end(&head, 3);
    insert_after_given_node(head, 4);
    
    display(head,end);

    

      head = deleteFirstNode(head);
   cout<<endl<<"After deleting head node"<<endl; 
   display(head,end);
 
   head = removeLastNode(head);
   cout<<endl<<"After deleting last node"<<endl;
   display(head,end);
    
    return 0;
}


//write a function for binary search 

void binarySearch(int arr[])
{
    int n = arr.length;
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        int mid = (i + j) / 2;
        if (arr[mid] == mid) {
}