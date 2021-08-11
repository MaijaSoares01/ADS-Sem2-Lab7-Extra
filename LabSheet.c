#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define bool int
#define true 1
#define false (!true)

struct student{
char studentNumber [20];
char name[20];
};

struct BSTNode{
struct student*student;
struct BSTNode*left;
struct BSTNode*right;
};

struct BSTNode*root = NULL;



int main(){
	char number[20];
	addStudents();
	displayInOrder(root);
	printf("Enter the student (via their number)you wish to find in the tree");
	scanf("%s", number);
	if (search(number))
	printf("%sis stored in the BST\n",searchValue);
	else printf("%sis not stored in the BST\n",searchValue);
	removeMin();
	displayInOrder(root);
	removeMax();
	displayInOrder(root);
}//end main



void displayInOrder(structBSTNode*current){
//See code in Trees lecture notes to traverse tree using inorder traversal
//Values should be displayedin sorted order
}//enddisplayInOrder

void addStudents()//adds 5 studentsto the tree, assume numbersare not duplicated
{
	structstudent*anElement;
	structBSTNode*aNode, *current;
	char number [20];
	char name[20];
	for (inti= 1;i<=5;i++){
	a.Create a new student element using malloc and store its address in anElement
	b.Ask user to input a student number and name and store in anElement
	c.Create a new node using malloc and store its address in aNode
	d.Assign an Elementto the aNode’s data part
	e.Assign null to the aNode’s left and right pointers
	f.If tree is empty then
		Let aNode be the root node
		Else //need to search the tree for the correct position for new node
		a.Assign current to root
		b.While current isn’t null
			i.If aNode’s student number<current’s student number
				1.If current has no left child
					a.Assign current’sleft pointer to aNode
					b.Assign current to NULL
				2.Else
					a.Assign current to its left child
			ii.Else //aNode’sdata > current’s data
				1.If current has no right child
					a.Assign current’s right pointer toaNode
					b.Assign current to NULL
				2.Else
					a.Assign current to its right child
		c.End while}//end for
}//end addStudent


bool search(char *value){
struct BSTNode*aNode, *current;
bool found = false;

if(!isEmpty())//Make sure you write an isEmpty() function also
{
current= root;
while value hasn’t been found and current isn’t null 
if current’s value equals value
	found= true
else 
	if current’s value > value
		Assign current its left child
	Else
		Assign current to its right child
End While}//end if
 returnfound;
 }//end search
 
 
 removeMin() -Remove  the  smallest item  in  the  tree.  This  will  be  the  leftmost  node  so  you will need to set up a loop to keep moving left).
  Set the left pointer of its parent to NULL and delete the leftmost node (by callingfree).
  
  removeMax() -Remove the largest item in the tree (thiswill be the  rightmost item).Set the right pointer of its parent to NULL and delete the rightmost node (by callingfree).
