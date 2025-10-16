#include "list.h"
#include <stdlib.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 * @note This function simply returns the input pointer, which represents the head of the list.
 * @note If the input pointer is NULL, it indicates that the list is empty.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * TODO: Describe what the function does
 * Returns the tail of the linked list.
 * @param head Pointer to the first node of the linked list.
 * @return The tail of the linked list. If the list is empty (NULL), returns NULL.
 * @note This function traverses the linked list to find the last node.
 * @note If the input pointer is NULL, it indicates that the list is empty.
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if(head == NULL){
        return NULL;
    }
    struct ll_node tail;
    while(head->next != NULL){
        head = head->next;

    }
    return head;
}

/**
 * TODO: Describe what the function does
 * Returns the size of the linked list.
 * @param head Pointer to the first node of the linked list.
 * @return The number of nodes in the linked list. If the list is empty (NULL), returns 0.
 * @note This function traverses the linked list to count the number of nodes.
 * @note If the input pointer is NULL, it indicates that the list is empty.
 * @note The function should return the count of nodes in the linked list.
 */
int ll_size(struct ll_node *head) {
    if(head == NULL){
        return 0;
    }
    int count = 0;
    while (head != NULL){
        head = head->next;
        count++;
    }
    return count;
}

/**
 * TODO: Describe what the function does
 * Finds a node in the linked list with the specified value.
 * @param head Pointer to the first node of the linked list.
 * @param value The value to search for in the linked list.
 * @return Pointer to the node containing the specified value. If not found, returns NULL.
 * @note This function traverses the linked list to find the first node with the specified value
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
    if(head == NULL){
        return NULL;
    }
    while(head->data != value && head->next != NULL){
        head = head->next;
    }
    if(head->data == value){
        return head;
    }
    else{
        return NULL;
    }
   
}

/**
 * TODO: Describe what the function does
 * Converts the linked list to an array of integers.
 * @param head Pointer to the first node of the linked list.
 * @return Pointer to an array of integers containing the values from the linked list.
 * @note The function allocates memory for the array and copies the values from the linked list
 */
int *ll_toarray(struct ll_node *head) {
   if(head == NULL){
    return NULL;
   }
    int size = ll_size(head);
    int* arr = malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        arr[i] = head->data;
        head = head->next;
    }
    return arr;

}

/**
 * TODO: Describe what the function does
 * Creates a new linked list node with the specified data.
 * @param data The integer data to be stored in the new node.
 * @return Pointer to the newly created node. If memory allocation fails, returns NULL.
 * @note The function allocates memory for a new node and initializes its data field.
 */
struct ll_node *ll_create(int data) {
   struct ll_node *newNode;
   newNode = (struct ll_node *)malloc(sizeof(struct ll_node));
   if(newNode == NULL){
    exit(EXIT_FAILURE);
   }
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

/**
 * TODO: Describe what the function does
 * Destroys the linked list and frees the allocated memory.
 * @param head Pointer to the first node of the linked list.
 * @note The function traverses the linked list and frees each node's memory.
 */
void ll_destroy(struct ll_node *head) {
    if(head == NULL){
        return;
    }
    else if(head!=NULL){
        ll_destroy(head->next);
        free(head);
    }
}

/**
 * TODO: Describe what the function does
 * Appends a new node with the specified data to the end of the linked list.
 * @param head Pointer to the first node of the linked list.
 * @param data The integer data to be stored in the new node.
 */
void ll_append(struct ll_node *head, int data) {
    if(head->next == NULL){
        head->next = ll_create(data);
        return;
    }
    else{
        ll_append(head->next, data);
    }
}

/**
 * TODO: Describe what the function does
 * Creates a linked list from an array of integers.
 * @param data Pointer to an array of integers.
 * @param len The length of the array.
 * @return Pointer to the head of the newly created linked list. If the array is empty, returns NULL.
 */
struct ll_node *ll_fromarray(int* data, int len) {
    struct ll_node *head = ll_create(data[0]);
    for(int i=1; i<len; i++){
        ll_append(head, data[i]);
    }
    return head;
}

/**
 * TODO: Describe what the function does
 * Removes the first occurrence of a node with the specified value from the linked list.
 * @param head Pointer to the first node of the linked list.
 * @param value The value to be removed from the linked list.
 * @return Pointer to the head of the linked list after removal. If the value is not found, returns the original head.
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    if(head == NULL){
        return NULL;
    }
    if(head->data == value){
        struct ll_node *temp = head->next;
        free(head);
        return temp;
    }
    struct ll_node *current = head;
    while(current->next != NULL && current->next->data != value){
        current = current->next;
    }
    if(current->next != NULL){
        struct ll_node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    return head;
}
