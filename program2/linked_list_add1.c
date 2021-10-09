#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"

// inserts into a linked list
void listInsert(node_t **head, class_t* cl) {

	int days_comp, times_comp;
    node_t* new_node = malloc(sizeof(node_t));
    new_node->cl = cl;
    new_node->next = NULL;

    // empty list - new node is only thing in list and becomes head
    if (*head == NULL) {
        *head = new_node;
    }
    else {
        node_t *cur_node = *head, *prev_node;
        int inserted = 0;
        while (!inserted) {
            if (cur_node != NULL) {
		    //does the day and time ordering
		    days_comp = strcmp(new_node->cl->cdays,cur_node->cl->cdays);
		    times_comp = strcmp(new_node->cl->ctime, cur_node->cl->ctime);

                // we are not at the end of the list
                if (days_comp < 0 || (days_comp == 0 && times_comp < 0)) {
                    if (*head == cur_node) {
                        // replaces the head
                        new_node->next = *head;
                        *head = new_node;
                    }
                    else {
                        // not at the head and not at the end
                        prev_node->next = new_node;
                        new_node->next = cur_node;
                    }
                    inserted = 1;
                }
                prev_node = cur_node;
                cur_node = cur_node->next;
            }
            else {
                // insert at end of list
                prev_node->next = new_node;
                inserted = 1;
           }                     
        }

    } 
    return;
}




