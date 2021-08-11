#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define STACKSIZE 20

#define bool int
#define true 1
#define false (!true)

struct Node {
	char anOperator;
	bool isOperator;
};

struct BinaryTreeNode 
{
	struct Node data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};

//Function prototypes
void inputExpressionForStack();
void stackPush(char );
char stackPop ();
bool stackNotIsEmpty();
struct Node constructNode (char );
struct BinaryTreeNode *createNode (struct Node );
bool isEmpty();
void displayInOrder (struct BinaryTreeNode *);
struct BinaryTreeNode *findLeftMostNode (struct BinaryTreeNode *);


//Global Variables
int treeCounter = 0, stackCounter = 0, answer;
char stack[10];
struct BinaryTreeNode *root = NULL;


int main() {
	struct Node aNode;
	struct BinaryTreeNode *parent, *leftChild, *rightChild;
	char anOperator;
	bool finished = false;
	int answer;

//input the postfix expression into the stack.
	inputExpressionForStack();	
//move from stack into the binary tree
	root = NULL;
	do
	{
      if (root == NULL) //get parent, its right and left children
	  {
	  	if (stackNotIsEmpty()) {
			anOperator = stackPop(); 
			aNode = constructNode(anOperator);
			parent = createNode (aNode);
			root = parent;
		}
			else finished = true;
	
		if (stackNotIsEmpty()) {
			anOperator = stackPop(); 
			aNode = constructNode(anOperator);
			rightChild = createNode(aNode);
			parent -> right = rightChild;
		}
			else finished = true;
		
		if (stackNotIsEmpty()) {
			anOperator = stackPop(); 
			aNode = constructNode(anOperator);
			leftChild = createNode(aNode);
			parent -> left = leftChild;
		}
			else finished = true;
	  }

// Now we have created the root node and its left and right 
//children. The remaining code adds on any other subtrees
else //there are already 3 nodes in the tree
	  {
		 parent = findLeftMostNode(root);
		 if (stackNotIsEmpty()) {
			anOperator = stackPop();
		
			aNode = constructNode(anOperator);
			rightChild = createNode(aNode);
			parent -> right = rightChild;
		}
			else finished = true;

		if (stackNotIsEmpty()) {
			anOperator = stackPop(); 
			aNode = constructNode(anOperator);
			leftChild = createNode(aNode);
			parent -> left = leftChild;
		}
			else finished = true;
	  }//end else	
	 }while (finished == false);
//NOW DISPLAY THE CONTENT OF THE TREE AS A REGULAR MATHS EXPRESSION		
   displayInOrder(root);
}

void inputExpressionForStack() {
   int index;   
   char anOperator; 
   
//make stack
	for (index = 0; index < STACKSIZE; index++)
		stack[index] = ' ';

	printf("Enter a new postfix expression : ");
	printf("Enter the integer or operator (+,-,*,/) on separate lines. Note that symbol ! will quit\n");
	
	do 
	{
		anOperator = getchar();
		fflush(stdin);
		if (anOperator != '!') 
		      stackPush(anOperator);
	}while (anOperator != '!');
}


void stackPush(char aCharacter) {
	stack[stackCounter++] = aCharacter;
}

char stackPop ()
{
	char top = ' ';
	if (stack[stackCounter] == ' ') stackCounter--;
	top = stack[stackCounter--];
	return top;
}

bool stackNotIsEmpty()
{
	if (stackCounter < 0)
		return false;
	else
		return true;
}

struct Node constructNode (char aCharacter) {
	struct Node temp;
	 temp.anOperator = aCharacter;
	if ((aCharacter == '+') || (aCharacter == '-') || (aCharacter == '*') || (aCharacter == '/')) 
	  temp.isOperator = true;
  else 
	  temp.isOperator = false;
  return temp;
}

struct BinaryTreeNode *createNode (struct Node aNode) {
	struct BinaryTreeNode *pointer;
   
	pointer = (struct BinaryTreeNode *)malloc(sizeof (struct BinaryTreeNode));
   	pointer->data = aNode;
	pointer->left = NULL;
	pointer->right = NULL;
	
	if (isEmpty()) //need to assign the root pointer
		root = pointer;
	treeCounter++;

	return pointer;
}

bool isEmpty() {
	  return (treeCounter==0);
  }


void displayInOrder (struct BinaryTreeNode *tree)
{
	if (tree != NULL)
	{
		displayInOrder(tree->left);
		printf(" %c ", tree->data.anOperator);
		displayInOrder(tree->right);
	}
}

struct BinaryTreeNode *findLeftMostNode (struct BinaryTreeNode *pointer) {
	struct BinaryTreeNode *temp;

	if (pointer->left == NULL)
		return pointer;
	else
		temp = findLeftMostNode(pointer->left);
}

