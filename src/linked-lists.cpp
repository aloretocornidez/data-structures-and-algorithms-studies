#include "../lib/linked-lists.hpp"
#include <iostream>

LinkedList::LinkedList()
{
  this->listSize = 0;

  this->head = new Node();
  this->tail = new Node();

  // initialize head
  this->head->next = this->tail;
  this->head->previous = nullptr;

  // initialize tail
  this->tail->previous = this->head;
  this->tail->next = nullptr;
}

LinkedList::~LinkedList()
{
  Node *temp = this->head->next;

  if (this->listSize > 0)
  {
    for (int i = 0; i < this->listSize; i++)
    {
      Node *deleteMe = temp;
      temp = temp->next;

      delete deleteMe;
    }
  }

  delete this->head;
  delete this->tail;
}

// add data to the end of a list.
void LinkedList::appendNode(int data)
{

  // Get second to last node.
  Node *prev = this->tail->previous;

  // initialize node.
  Node *newNode = new Node();
  newNode->data = data;

  // Set new references for inserted node.
  newNode->next = tail;
  newNode->previous = prev;

  // Set new references for existing list.
  prev->next = newNode;
  this->tail->previous = newNode;

  // increment list size.
  this->listSize++;
}

// add data to the beginning of a list.
void LinkedList::insertAtBeginning(int data)
{

  // create new node
  Node *newNode = new Node;
  newNode->data = data;

  // initialize references for new node.
  newNode->next = head->next;
  newNode->previous = head;

  // initialize references for existing list.
  head->next->previous = newNode;
  head->next = newNode;

  // increment list size.
  this->listSize++;
}

// insert node at index.
void LinkedList::insertNodeAtIndex(int data, int index)
{

  // append to end of the list if entered index is larger than list size.
  if (index >= (int)this->listSize)
  {
    index = this->listSize;
  }
  // negative indexes add to elements from end of list.
  else if (index < 0)
  {

    index = this->listSize + index;

    if (index < 0)
    {
      index = 0;
    }
  }

  Node *tempPrev = head;

  // traverse list that many times.
  int i = 0;
  while (i++ < index)
  {
    tempPrev = tempPrev->next;
  }

  // create new node
  Node *newNode = new Node;
  newNode->data = data;

  // initialize references for new node.
  newNode->next = tempPrev->next;
  newNode->previous = tempPrev;

  // initialize references for existing list.
  tempPrev->next->previous = newNode;
  tempPrev->next = newNode;

  // increment list size.
  this->listSize++;
}

// Traverses to the node and then removes it from the list.
void LinkedList::deleteNodeAtIndex(int index)
{

  Node *temp = getNodeAtIndex(index);

  Node *prev = temp->previous;

  prev->next = temp->next;
  temp->next->previous = prev;

  delete temp;
}
// Get a node in the list.
LinkedList::Node *LinkedList::getNodeAtIndex(int index)
{

  // if list is empty.
  if (this->listSize == 0)
  {
    return nullptr;
  }
  // append to end of the list if entered index is larger than list size.
  if (index >= (int)this->listSize)
  {
    index = this->listSize;
  }
  // negative indexes add to elements from end of list.
  else if (index < 0)
  {

    index = this->listSize + index;

    if (index < 0)
    {
      index = 0;
    }
  }

  // set pointer to head.
  Node *temp = this->head->next;

  // traverse list until index is reached.
  unsigned int i = 0;
  while (i++ < index)
  {
    temp = temp->next;
  }
  return temp;
}

void LinkedList::printList()
{

  Node *temp = this->head;

  // std::cout << "List Size: " << this->listSize << std::endl;

  while (temp->next != this->tail)
  {

    // traverse list
    temp = temp->next;

    // print the data.
    std::cout << temp->data;

    // Add comma while not at end of list.
    if (temp->next != this->tail)
    {
      std::cout << ", ";
    }
  }
  // add a new line at the end.
  if (listSize > 0)
  {
    std::cout << std::endl;
  }
}

void LinkedList::printBackwards()
{

  Node *temp = this->tail;

  while (temp->previous != this->head)
  {

    // traverse list
    temp = temp->previous;

    // print the data.
    std::cout << temp->data;

    // Add comma while not at end of list.
    if (temp->previous != this->head)
    {
      std::cout << ", ";
    }
  }
  // add a new line at the end.
  if (listSize > 0)
  {
    std::cout << std::endl;
  }
}
// reverse the linked list.
void LinkedList::reverseList()
{

  // create a temporary holder
  Node *newTail = this->head;
  Node *newHead = this->tail;

  Node *temp = new Node();
  Node *prev = new Node();
  temp = this->head;

  // traverse the list and reverse elements.
  while (temp != nullptr)
  {
    prev = temp;
    temp = temp->next;

    prev->next = prev->previous;
    prev->previous = temp;
  }

  this->tail = newTail;
  this->head = newHead;
}
