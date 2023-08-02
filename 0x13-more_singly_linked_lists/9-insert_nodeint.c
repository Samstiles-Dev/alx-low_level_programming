#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	// Create a new node
    listint_t *newNode = (listint_t *)malloc(sizeof(listint_t));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    newNode->n = n;

    // If the index is 0, insert at the beginning
    if (idx == 0) {
        newNode->next = *head;
        *head = newNode;
        return newNode;
    }

    // Traverse the list to find the previous node
    listint_t *prev = *head;
    for (unsigned int i = 0; i < idx - 1; i++) {
        if (prev == NULL) {
            // Index out of bounds, cannot insert
            free(newNode);
            return NULL;
        }
        prev = prev->next;
    }

    // If prev is NULL, index is out of bounds
    if (prev == NULL) {
        free(newNode);
        return NULL;
    }

    newNode->next = prev->next;
    prev->next = newNode;

    return newNode;
}
