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

    int insertChoice; // int to contain LL method

    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list" << endl;
    cout << "\t[2] New nodes are added at the tail of the linked list" << endl;
    cout << "\tChoice: ";
    cin >> insertChoice;
    cout << "You chose: " << insertChoice;

    return 0;
}