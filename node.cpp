#include "node.h"
#include <iostream>
#include <cstring>

Node::Node() {
	left = NULL;
	right = NULL;
	next = NULL;
	value = NULL;

}

Node::~Node() {

}

void Node::setValue(char* newvalue) {
	value = newvalue;
}

void Node::setRight(Node* newRight) {
	right = newRight;
}

void Node::setLeft(Node* newLeft) {
	left = newLeft;
}

void Node::setNext(Node* newNext) {
	next = newNext;
}

Node* Node::getRight() {
	return right;
}

Node* Node::getLeft() {
	return left;
}

Node* Node::getNext() {
	return next;
}

char* Node::getValue() {
	return value;
}

