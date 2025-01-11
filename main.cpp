
// This file is used as the driver to run different data structure algorithms.

#include "lib/linked-lists.hpp"
#include <iostream>

int main(int argc, char *argv[]) {

  // Linked list Section.
  bool runningLinkedLists = true;

  if (runningLinkedLists) {

    // Create a singly list
    LinkedList *mySingleList = new LinkedList;

    // build list.
    mySingleList->appendNode(5);
    mySingleList->appendNode(6);
    mySingleList->appendNode(7);
    mySingleList->insertAtBeginning(3);
    mySingleList->insertAtBeginning(2);
    mySingleList->insertAtBeginning(1);

    mySingleList->insertNodeAtIndex(4, 3);

    // add node to the end of the list.
    mySingleList->insertNodeAtIndex(11, 7);

    // add node to the three elements from the end of the list.
    mySingleList->insertNodeAtIndex(-4, -11);

    // Print the nodes
    std::cout << "Printing List" << std::endl;
    mySingleList->printList();

    // reverse the list
    std::cout << "Reversing List" << std::endl;
    mySingleList->reverseList();

    // print the list
    std::cout << "Printing Reversed List" << std::endl;
    mySingleList->printList();

    // print the list
    std::cout << "Removing Node" << std::endl;
    mySingleList->deleteNodeAtIndex(3);
    mySingleList->printList();

    delete mySingleList;
  }

  // 
  return 0;
}
