#include "node.h"
#include <iostream>

Node::Node() {
	
	next = NULL;
	value = NULL;

}

Node::~Node() {

}

void Node::setValue(char newvalue) {
	value = newvalue;
}

void Node::setNext(Node* newNext) {
	next = newNext;
}

Node* Node::getNext() {
	return next;
}

char Node::getValue() {
	return value;
}
