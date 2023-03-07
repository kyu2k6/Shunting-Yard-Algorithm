#ifndef nodeh
#define nodeh

class Node {
	public:
		Node();
		~Node();

		void setValue(char*);
		void setLeft(Node*);
		void setRight(Node*);
		void setNext(Node*);
		
		char* getValue();
		Node* getLeft();
		Node* getRight();
		Node* getNext();

	private:
		
		Node* left;
		Node* right;
		Node* next;
		char* value;
};
#endif
