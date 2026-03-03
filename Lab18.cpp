#include <iostream>
using namespace std;

// review Node struct
struct Node {
    double rating;
    string review;
    Node *next;
};

// insert at head of linked list function prototype
void insertAtHead(Node *&headNode);

// insert at tail of linked list prototype
void insertAtTail(Node *headNode);

int main() {
    Node *head = nullptr;

    return 0;
}