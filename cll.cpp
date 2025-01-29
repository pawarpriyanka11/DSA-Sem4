#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
} *head = NULL, *temp, *ind;

void createNode(int val) {
    temp = new Node(val);
    if (head == NULL) {
        head = temp;
        head->next = head;  // Circular link
    } else {
        ind = head;
        while (ind->next != head) {  // Traverse until last node
            ind = ind->next;
        }
        ind->next = temp;
        temp->next = head;  // Last node points to head
    }
}

void displayList() {
    if (head == NULL) {
        cout << "\nList is empty!";
        return;
    }
    ind = head;
    do {
        cout << ind->data << " ";
        ind = ind->next;
    } while (ind != head);  // Stop when we reach the head again
    cout << endl;
}

void removeNode(int pos) {
    if (head == NULL) {
        cout << "\nList is empty!";
        return;
    }

    temp = head;
    if (pos == 1) {  // Removing the first node
        while (temp->next != head) {
            temp = temp->next;  // Find the last node
        }
        ind = head;
        if (head->next == head) {  // Only one node
            head = NULL;
        } else {
            head = head->next;
            temp->next = head;
        }
        cout << "\nElement removed: " << ind->data;
        delete ind;
        return;
    }

    // Removing a node other than head
    temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head) {
        cout << "\nElement is not in the list!";
        return;
    }

    ind = temp->next;
    temp->next = ind->next;
    cout << "\nElement removed: " << ind->data;
    delete ind;
}

int main() {
    int ch = 1, xx, pos;
    
    while (ch < 4) {
        cout << "\n1. Create\n2. Display\n3. Remove\n";
        cin >> ch;
        
        if (ch == 1) {
            cout << "\nEnter data: ";
            cin >> xx;
            createNode(xx);
        } else if (ch == 2) {
            displayList();
        } else if (ch == 3) {
            cout << "\nEnter the position to remove: ";
            cin >> pos;
            removeNode(pos);
        }
    }
    
    return 0;
}
