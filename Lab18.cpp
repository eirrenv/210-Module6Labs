#include <iostream>
#include <string>
using namespace std;

// review Node struct
struct Node {
    double rating;
    string review;
    Node *next;
};

// entering review function prototype
void enterReview(Node *&reviewNode);

// insert at head of linked list function prototype
void insertAtHead(Node *&headNode);

// insert at tail of linked list prototype
void insertAtTail(Node *&headNode);

// print reviews prototype
void printReviews(Node *headNode);

int main() {
    Node *head = nullptr;

    int insertChoice; // int to contain LL method

    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list" << endl;
    cout << "\t[2] New nodes are added at the tail of the linked list" << endl;
    cout << "\tChoice: ";
    cin >> insertChoice;

    return 0;
}

// enter reviews 
void enterReview(Node *&reviewNode) {
    cout << "Enter review rating 0-5: ";
    cin >> reviewNode->rating;
    cin.ignore();
    cout << endl << "Enter review comments: ";
    getline(cin, reviewNode->review);
    cout << endl;
}

// print reviews and calculate and print average
void printReviews(Node *headNode) {
    cout << "Outputting all reviews:" << endl;
    if (headNode == nullptr) {
        cout << "\tNo reviews to output." << endl;
    }
    else {
        Node *current = headNode;
        int count = 0;
        double total = 0.0;
        while (current) {
            cout << "\t> Review #" << count + 1 << ": " << current->rating << ": " << current->review << endl;
            total += current->rating;
            ++count;
        }
        cout << "\t> Average: " << total / count << endl;

    }
}

// insert node at head
void insertAtHead(Node *&headNode) {
    Node *newNode = new Node;
    enterReview(newNode);
    if (headNode == nullptr) {
        headNode = newNode;
    }
    else {
        newNode->next = headNode;
        headNode = newNode;
    }
}

// insert node at tail
void insertAtTail(Node *&headNode) {
    Node *newNode = new Node;
    Node *current = headNode;
    enterReview(newNode);
    if (headNode == nullptr) {
        headNode = newNode;
    }
    else {
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}
