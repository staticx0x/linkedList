#include <stdio.h>
#include <stdlib.h>

struct Node {
	//Numberical order of node in list
	int ref;
	//Holds letter inputted by User
	int data;
	//Holds address to next node in list
	struct Node *next;
};

int test() {
	//Constructs new node and number
	struct Node a;
	struct Node b;
	int *rawinput= malloc(sizeof(int));

	//Accepts and appends user input for number
	printf("\nEnter a number for the first node: \n");
	scanf("%d", rawinput);
	a.data = *rawinput;
	printf("Enter a number for the second node: \n");
	scanf("%d", rawinput);
	printf("\n");
	b.data = *rawinput;
	free(rawinput);

	//Link the list
	a.next = &b;
	b.next = NULL;

	//Iterate the list
	printf("Node A is %d\nAddress is %p\n", a.data, &a);
	printf("A points to %p\n\n", a.next);
	printf("Node B is %d\nAddress is %p\n", b.data, &b);
	printf("B points to %p\n\n", b.next);
	return (a.next == &b) ? 0 : 1;
}

struct Node* addNode(int i) {
	int *rawinput = malloc(sizeof(int));
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	//In case the program cannot allocate memory
	if(newNode == NULL) {
		printf("FAILED TO ALLOCATE MEMORY...");
		return NULL;
	}
	//Accepting user input for the data of the Node
	printf("\nEnter a number for the node to store: \n");
	scanf("%d", rawinput);
	newNode->data = *rawinput;
	newNode->ref = i;
	printf("\n");
	free(rawinput);

	return newNode;
}

void removeNode(int i) {
	//free()?
}

void printList(struct Node start) {
	//Print nodes from start to last node on list
	if (start.next == NULL) {
		printf("Node A is the only node in the linked list.");
	}
}

int main() {
	int result;
	int userSelect = 1;
	int close = 0;
	int listLength = 0;
	
	//Checks whether node was constructed sucessfully
	do {
		printf("Select an option by entering the number:\n1. Add\n2. Remove Last Node\n3. Print List\n4. Test Nodes\n5. Exit\n");
		scanf("%d", &userSelect);
		switch (userSelect) {
			case 1:
				//Add node
				listLength++;
				//struct Node* newNode = addNode(listLength);
				break;
			case 2:
				//Delete node
				listLength--;
				break;
			case 3:
				//Print function
				printf("List is %d nodes in length\n", listLength);
				break;
			case 4:
				//Test function
				result = test();
				result == 1 ? printf("There was an error\n") : printf("Node built sucessfully\n");
				break;
			case 5:
				//Exit
				close = 1;
				break;
			default:
				printf("Make a VALID selection!!");
		}
	} while (!close);

	return 0;
}
