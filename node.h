#ifndef nodeh
#define nodeh

class Node {
	public:
		Node(); //constructor
		~Node(); //destructor

		char getValue();
		Node* getNext();

		void setValue(char value);
		void setNext(Node* next);
	
		Node* next;
		char value;
};
#endif
