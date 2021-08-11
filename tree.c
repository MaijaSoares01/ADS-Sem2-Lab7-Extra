#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define bool int
#define true 1
#define false (!true)

struct Node {
	char value;
};

struct BinaryTreeNode 
{
	struct Node *data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};

struct BinaryTreeNode *root = NULL;

void inputValues();
void displayPreOrder(struct BinaryTreeNode *);
void displayInOrder(struct BinaryTreeNode *);
void displayPostOrder(struct BinaryTreeNode *);


int main()
{
	inputValues();
	printf("\nDisplaying preorder...\n");
	displayPreOrder(root);
	printf("\n\nDisplaying inorder...\n");
	displayInOrder(root);
	printf("\n\nDisplaying postorder...\n");
	displayPostOrder(root);
}

void inputValues()
{
	struct Node *aNode;
	struct BinaryTreeNode *current, *previous;
	
	//Hardwire in the elements in the Tree to match Slide 26 of the lecture notes
	aNode = (struct Node *)malloc(sizeof (struct Node));
	aNode->value = 'A';  
	current = (struct BinaryTreeNode *)malloc(sizeof (struct BinaryTreeNode));
   	current->data = aNode;
	current->left = NULL;
	current->right = NULL;
	root = current;
	previous = current; //Previous = A
	
	aNode = (struct Node *)malloc(sizeof (struct Node));
	aNode->value = 'C';  
	current = (struct BinaryTreeNode *)malloc(sizeof (struct BinaryTreeNode));
   	current->data = aNode;
	current->left = NULL;
	current->right = NULL;
	previous->right = current; //Right child of A is C
	
	aNode = (struct Node *)malloc(sizeof (struct Node));
	aNode->value = 'B';  
	current = (struct BinaryTreeNode *)malloc(sizeof (struct BinaryTreeNode));
   	current->data = aNode;
	current->left = NULL;
	current->right = NULL;
	previous->left = current; //Left child of A is B
	previous = current; //Previous is now B
	
	aNode = (struct Node *)malloc(sizeof (struct Node));
	aNode->value = 'E';  
	current = (struct BinaryTreeNode *)malloc(sizeof (struct BinaryTreeNode));
   	current->data = aNode;
	current->left = NULL;
	current->right = NULL;
	previous->right = current; //Right child of B is E
	
	aNode = (struct Node *)malloc(sizeof (struct Node));
	aNode->value = 'D';  
	current = (struct BinaryTreeNode *)malloc(sizeof (struct BinaryTreeNode));
   	current->data = aNode;
	current->left = NULL;
	current->right = NULL;
	previous->left = current; //Left child of B is D
		
	
}

void displayPreOrder (struct BinaryTreeNode *tree)
{
	if (tree != NULL)
	{
		printf(" %c ", tree->data->value);
		displayPreOrder(tree->left);
		displayPreOrder(tree->right);
	}
}

void displayInOrder (struct BinaryTreeNode *tree)
{
	if (tree != NULL)
	{
		displayInOrder(tree->left);
	    printf(" %c ", tree->data->value);
		displayInOrder(tree->right);
	}
}

void displayPostOrder (struct BinaryTreeNode *tree)
{
	if (tree != NULL)
	{
		displayPostOrder(tree->left);
	    displayPostOrder(tree->right);
	    printf(" %c ", tree->data->value);
	}
}
