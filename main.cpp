//Kevin Yu
//3-17-23
//Shunting Yard Algorithm creates binary tree for prefix infix postfix

#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void push(Node*& top, char* value); //add
void pop(Node*& top); //remove
void peek(); //print
void enqueue(); //add
void dequeue(); //remove
int precedence(char* p);

void infix();
void prefix();
void postfix();

int main() {
	
	Node* top = NULL;
	Node* front = NULL;
	Node* back = NULL;

	char* table = new char [100];
	
	char expression[100];
	char notation[20];
	
	cout << "Please input an equation: ";
	cin.get(expression, 100);
	cin.get();
	
	int index = 0;
	//take from input and put in table
	for (int i = 0; i < strlen(expression); i++) {
		if (expression[i] != ' ') {
			table[index] = expression[i];
			index++;
			cout << expression[i] << endl;
		}
	}

}

void push(Node*& top, char* value) {
	Node* temp = new Node();
	temp->setValue(value);
	temp->setNext(top);
	top = temp;
}

void pop(Node*& top) { //Pop function
    if (top == NULL) {
        cout << "Empty" << endl;
    }
    else {
        Node* temp = top;
        top = top->getNext();
        temp->setNext(NULL);
    }
}

int precedence(char* p) {
    if (*p == '^') {
        return 3; //Highest
    }
    else if (*p == '*' || *p == '/') {
        return 2; //Second highest
    }
    else if (*p == '+' || *p == '-') {
        return 1; //Second lowest
    }
    else if (*p == '(' || *p == ')') {
        return 5; //Can be anything, as long as it is differentiated from the rest
    }
    else {
        return 0; //Lowest, which are the numbers
    }
}

