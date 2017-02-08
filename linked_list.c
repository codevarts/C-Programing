#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* arbritary data for list */
typedef struct data {

	char * task_name;
	int task_number;
} data;

typedef struct node {

	struct data * data;
	/* pointer to next node */
	struct node * next;
	struct node * prev;
} node;

typedef struct list {

	node * head;
	node * last;
	int num_nodes;
} list;

/* list status */
int is_empty(list * list) {
	if(list->head == NULL) {
		return 1;
	} else {
		return 0;
	}
}

/* initialize list */
void init_list(list * list) {
	list->head = NULL;
	list->last = NULL;
	list->num_nodes = 0;
}

/* returns initialized node */
node * get_new_node(data * data) {
	node * new_node = (node*)malloc(sizeof(node));
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = data;

	return new_node;
}

/* insert functions */
/* insert start */
void insert_start(list * list, node * node_to_insert) {

	/* prepare node */
	node_to_insert->next = list->head;
	node_to_insert->prev = NULL;

	/* update list */
	list->head = node_to_insert;

	/* update num nodes */
	list->num_nodes++;
}

/* insert end */
void insert_end(list * list, node * node_to_insert) {

	/* sentinal to loop through list */
	node * current;

	/* prep sentinel */
	current = list->head;

	/* loop through list to get to last node */
	while (current->next != NULL) {
		current = current->next;
	}

	/* current next is pointing to last node so set new node to next of that */
	current->next = node_to_insert;
	node_to_insert->prev = current;
	list->last = node_to_insert;

	/* update num nodes */
	list->num_nodes++;
}

void insert(list * list, node * node_to_insert) {

	/* sentinal to loop through list */
	node * current;
	current = list->head;

	/* search for insert point */
	while(current->next != NULL) {
		/* break if condition for insertion found */
		if (current->data->task_number == node_to_insert->data->task_number) {
			break;
		}
	}

	/* current is now pointing to insertion point */
	/* update new node */
	node_to_insert->next = current->next;
	node_to_insert->prev = current;
	current->next = node_to_insert;

	/* update num nodes */
	list->num_nodes++;
}

/* delete functions */
/* delete start list not empty */
void delete_start(list * list) {

	/* memory will need to be free'd if this is dynamic */
	/* temp node to maintain pointer to node to remove */
	node * temp = list->head;

	/* point list first to next along */
	list->head = list->head->next;
	list->head->prev = NULL;

	/* free the node just removed */
	free(temp);

	/* decrement count */
	list->num_nodes--;
}

/* delete last list not empty */
void delete_last(list * list) {

	/* memory will need to be free'd if this is dynamic */
	/* temp node to maintain pointer to node to remove */
	node * temp;
	node * current = list->head;

	/* find last node */
	while (current->next->next != NULL) {
		current = current->next;
	}

	/* current is now pointing to the 2nd to last node last node */
	temp = current->next;
	current->next = NULL;
	list->last = current;

	/* dont need to set prev cuz it's already set */
	free(temp);

	list->num_nodes--;
}

void delete(list * list, node * node_to_delete) {

		node * current = list->first;
		node * temp = NULL;

		while (current != NULL) {
			if (current->data->task_number == node_to_delete->data->task_number)
		}

}

void print_list(list * list) {

			node * current = list->head;

			while (current != NULL) {
					printf("Task Description: %s\n", current->data->task_name);
					printf("Task Number: %d\n\n", current->data->task_number);
					current = current->next;			
			}
}

void print_list_backward(list * list) {

			node * current = list->last;

			while (current != NULL) {
					printf("Task Description: %s\n", current->data->task_name);
					printf("Task Number: %d\n\n", current->data->task_number);
					current = current->prev;			
			}
}

int main(void) {

	list taskList;
	node * new_task;
	node * new_task2;
	data * task_data = NULL;
	data * task_data2= NULL;

	task_data = (data*)malloc(sizeof(data));
	task_data2 = (data*)malloc(sizeof(data));

	/* task info */
	task_data->task_name = (char*)malloc(sizeof(char) * 25);
	strcpy(task_data->task_name, "Install new servers");
	task_data->task_number = 1;

	/* task info */
	task_data2->task_name = (char*)malloc(sizeof(char) * 25);
	strcpy(task_data2->task_name, "Update databases");
	task_data2->task_number = 2;

	/* add task info to node */
	new_task = get_new_node(task_data);
	new_task2 = get_new_node(task_data2);

	/* initialise list */
	init_list(&taskList);

	/* Add task to start */
	insert_start(&taskList, new_task);
	printf("Number of tasks: %d\n", taskList.num_nodes);

	/* Add to end */
	insert_end(&taskList, new_task2);
	printf("Number of tasks: %d\n", taskList.num_nodes);
	print_list(&taskList);
	print_list_backward(&taskList);

	/* remove start */
	delete_start(&taskList);
	printf("Number of tasks: %d\n", taskList.num_nodes);
	print_list(&taskList);	

	return EXIT_SUCCESS;
}
