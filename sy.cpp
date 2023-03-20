#include <iostream>
#include "node.h"
#include <cstring>

using namespace std;

int order(char input);
void enqueue(Node*& headQ, char newvalue);
void print(Node* head);
void stack(Node*& headS, char newvalue);

int main() {
	Node* headS = NULL;
	Node* headQ = NULL;
	
	char input[100];

	cout << "Please input your expression with spaces: ";

	cin.get(input, 100);
	cin.get();
	
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] != ' ') {
			if (order(input[i]) == 0) {
				enqueue(headQ, input[i]);
			}		
			else {
				stack(headS, input[i]);
			}
		}
	}
	enqueue(headQ, headS->value);

	print(headQ);
	print(headS);
}

void enqueue(Node*& headQ, char newvalue) {
	Node* n = new Node();
	n->setValue(newvalue);
	n->setNext(NULL);
	if(headQ == NULL) {
		headQ = n;
}
	else {
		Node* temp = headQ;
		while(temp -> next != NULL) {
			temp = temp -> next;
		}
		temp -> next = n;
	}
}

void stack(Node*& headS, char newvalue) {
	Node* n = new Node();
	n->setValue(newvalue);
	n->setNext(headS);
	headS = n;
}

void print(Node*headQ){
	Node* temp = headQ;
	if (temp != NULL) {
		cout << "List: ";
		while(temp != NULL) {
			cout << temp -> value << " ";
			temp = temp -> next;
		}
		cout << endl;
	}
	else {
		cout << "nuthin";
	}
}

//Idea from Nathan Zou to use number scale
int order(char input) {
    if (input == '^') {
        return 3; //Highest
    }
    else if (input == '*' || input == '/') {
        return 2; //Second highest
    }
    else if (input == '+' || input == '-') {
        return 1; //Second lowest
    }
    else if (input == '(' || input == ')') {
        return 4; //Can be anything, as long as it is differentiated from the rest
    }
    else {
        return 0; //Lowest, which are the numbers
    }
}


