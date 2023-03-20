#include <iostream>
#include "node.h"
#include <cstring>

using namespace std;

int order(char input);
void enqueue(Node*& headQ, char newvalue);
void print(Node* head);
void stack(Node*& headS, char newvalue, Node*& headQ);
void pop(Node*& headS, Node*& headQ);

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
				stack(headS, input[i], headQ);
			}
		}
	}
	
	//everything left in stack
	while (headS != NULL) {
		pop(headS, headQ);
	}

	print(headQ);
}
void pop(Node*& headS, Node*& headQ) {
	enqueue(headQ, headS->value);
	Node* temp = headS;
	headS = headS -> next;
	delete temp;
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

void stack(Node*& headS, char newvalue, Node*& headQ) {
	if (headS == NULL) {
		Node* n = new Node();
		n -> setValue(newvalue);
		n -> setNext(NULL);
		headS = n;
	}
	else {	//if no has paranthesis
		if (order(newvalue) != 4) {
			if ((order(newvalue) <= order(headS->value)) && (order(headS -> value) != 4)) {
				pop(headS, headQ);
				stack(headS, newvalue, headQ);
			}
			else {
				//only if incoming is bigger than current top value
				Node* n = new Node();
				n->setValue(newvalue);
				n->setNext(headS);
				headS = n;
			}
		}//if has 
		else {
			if (newvalue == ')') {
				while (headS->value != '(') {
					pop(headS, headQ);
				}
				Node* temp = headS;
				headS = headS -> next;
				delete temp;
			}	
		}
	}
}

void print(Node*head){
	Node* temp = head;
	if (temp != NULL) {
		cout << "Postfix: ";
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


