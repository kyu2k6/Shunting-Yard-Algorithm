//Kevin Yu
//3-17-23
//Shunting Yard Algorithm creates binary tree for prefix infix postfix

#include <iostream>
#include <cstring>
#include "node.h"

//make a linkedlist for the operators
//add rest to output queue

using namespace std;

void enqueue(char value);
void push(Node*& operators, char value);
void order(Node*& output, char input);

Node* output = new Node();
Node* operators = new Node();
Node* head = NULL;

int main() {

        char input[100];
        cout << "Please input an equation: ";
        cin.get(input, 100);
        cin.get();

        int first = 0;

        for (int i = 0; i < strlen(input); i++) {
                if (order(input[i]) == 0) {

                        enqueue(output, input[i])
                }
                else {
                        //put into operator stack
                }
        }
}

void enqueue(Node*& output, char value) {
        Node* old = new Node();
        Node* tempNode;
        Node* tempOld;
        Node* tempHead;

        if (head == NULL) {
                tempNode = new Node(
        }
}

void push(Node*& operators, char value) {

}

int order(char input) {
    if (input == '^') {
        return 3; //Highest
    }
    else if (input == '*' || *p == '/') {
        return 2; //Second highest
    }
    else if (input == '+' || *p == '-') {
        return 1; //Second lowest
    }
    else if (input == '(' || *p == ')') {
        return 4; //Can be anything, as long as it is differentiated from the rest
    }
    else {
        return 0; //Lowest, which are the numbers
    }
}
