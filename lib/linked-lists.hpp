#ifndef LINKED_LISTS
#define LINKED_LISTS

class LinkedList {

  // A node structure to be used for the linked list.
  struct Node {
  public:
    int data;
    Node *next;
    Node *previous;
  };

public:
  // Initialize head and tail of list.
  LinkedList();

  // Delete all nodes in the list then delete head and tail.
  ~LinkedList();

  // add data to the end of a list.
  void appendNode(int data);

  // add data to the beginning of a list.
  void insertAtBeginning(int data);

  // insert node at index.
  void insertNodeAtIndex(int data, int index);

  // Delete a node at index 
  void deleteNodeAtIndex(int index);

  // Get a node in the list.
  Node *getNodeAtIndex(int index);

  

  void printList();
  void printBackwards();

  // reverse the linked list.
  void reverseList();

private:
  Node *head;
  Node *tail;
  int listSize;
};

#endif // !LINKED_LISTS
