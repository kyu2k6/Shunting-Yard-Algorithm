//Kevin Yu
//3-17-23
//Shunting Yard Algorithm creates binary tree for prefix infix postfix

#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void push(Node*& top, char* value); //add
void pop(Node*& top); //remove
void peek(); 
void enqueue(Node*& front, Node*& back, char* value); //add
void dequeue(); //remove
int precedence(char* p);

void infix();
void prefix();
void postfix();

int main() {
	
	Node* top = NULL;
	Node* front = NULL;
	Node* back = NULL;

	char** table = new char * [100];
	
	char expression[100];
	char notation[20];
	
	cout << "Please input an equation: ";
	cin.get(expression, 100);
	cin.get();
	
	int index = 0;
	//take from input and put in table
	for (int i = 0; i < strlen(expression); i++) {
		if (expression[i] != ' ') {
			char* tmp = new char[1];
			tmp[0] = expression[i];
			table[index] = tmp;
			index++;
		}
	}
	int count = 0;
	/*
	while (count < index) {
		//if (precedence(table[index]) == 0) { //If token is a number
                    enqueue(front, back, table[index]);
                }
                if (precedence(table[index]) == 1 || precedence(table[index]) == 2 || precedence(table[index]) == 3) { //If token is a operator
                    if (top != NULL) {
                        while (precedence(top->getValue()) >= precedence(table[index]) && *top->getValue() != '(') {
                            enqueue(front, back, top->getValue()); 
                            pop(top);
                            if (top == NULL) {
                                break;
                            }
                        }
                    }
                    push(top, table[index]); 
                }
		count++;
	}
	*/

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

void enqueue(Node*& front, Node*& back, char* value) { //Enqueue function
    Node* temp = new Node();
    temp->setValue(value);
    temp->setNext(NULL);
    if (front == NULL) { //No nodes yet
        front = temp;
        back = temp;
    }
    else { //At least one node exists
        back->setNext(temp);
        back = temp;
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
        return 4; //Can be anything, as long as it is differentiated from the rest
    }
    else {
        return 0; //Lowest, which are the numbers
    }
}

