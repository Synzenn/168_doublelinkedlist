#include <iostream>
#include <string>
using namespace std;

struct Node{
	string name;
	int noMhs;
	Node *next;
	Node *prev;
};

Node *START = NULL;

void addNode(){
	Node* newNode = new Node();
	cout << "\nEnter the roll number of the student :";
	cin >> newNode->noMhs;
	cout << "\nEnter the name of the student :";
	cin >> newNode->name;

	if (START == NULL  || newNode -> noMhs == START->noMhs){
		if (START != NULL && newNode->noMhs == START->noMhs) {
			cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
		}

		newNode->next = START;
		if (START != NULL) {
			START->prev = newNode;
		}
		newNode->prev = NULL;
		START = newNode;
	}
	else {
		Node* current = START;
		Node* previous = NULL;

		while (current != NULL && current->noMhs < newNode->noMhs) {
			previous = current;
			current = current->next;
		}

		newNode->next = current;
		newNode->prev = previous;

		if (current != NULL) {
			current->prev = newNode;
		}
		if (current != NULL) {
			current->next = newNode;
		}
		else{
			START = newNode;
		}
	}
}

bool search(int rollNo, Node** previous, Node** current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

void deleteNode()
{
    Node* previous, * current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollNo;                                                                  //step 3get the roll number to be deleted

    if (START == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    current = START;                                                               //step 1:start from the first node
    previous = NULL;

    //locate the node to be deleted
    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number " << rollNo << "not found\033[0m" << endl;
        return;
    }

    //Node to be deleted is the firts node
    if (current == START)
    {
        START = START->next;                                            //step 2:update the START pointer
        if (START != NULL)
        {
            START->prev = NULL;                                         //step
        }
    }
    else
    {   //Node to be deleted is not the first node
        previous->next = current->next;
        if (current->next != NULL)
        {   //if there's successor, update is prev pointer
            current->next->prev = previous;
        }
    }

    //release the memory of the node marked as current
    delete current;
    cout << "\x1b[32mRecord with roll number " << rollNo << "deleted\x1b[0m" << endl;
}

bool listempty()
{
    return (START == NULL);
}

void traverse()
{
    if (listempty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecord is ascending order of roll number are:  " << endl;
        Node* currentNode = START;              //step 1
        while (currentNode != NULL)             //step 2
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;         //step 3
            currentNode = currentNode->next;                                        //step 4
        }
    }
}


