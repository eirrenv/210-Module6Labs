#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// review Node struct
struct Node {
    double rating;
    string review;
    Node *next = nullptr;
};

// Movie class
class Movie {
    private:
        string movieTitle;
        Node *rateReview;
    public:
        // getters and setters for title, rating and review 
        string getTitle() { return movieTitle; }
        void setTitle(string title) { movieTitle = title; }
        Node getRating() { return *rateReview; }
        void setRating(Node *reviewToSet) { 
            rateReview->rating = reviewToSet->rating; 
            rateReview->review = reviewToSet->review; 
        }
};

// entering review function prototype
void enterReview(Node *&reviewNode);

// insert at head of linked list function prototype
void insertAtHead(Node *&headNode);

// print reviews prototype
void printReviews(Node *headNode);

int main() {
    Node *head = nullptr;
    vector<Movie> movieVector; // vector containing Movie objects

    string title; // holds temp title
    double rating; // holds temp rating
    string review; // holds temp review

    ifstream fin("text.txt");
    if (fin.good()) {
        while (getline(fin, title)) { // capture data from input file
            fin >> rating;
            fin.ignore();
            getline(fin, review);
            Movie tmp;
            Node *tmpNode = new Node;
            tmp.setTitle(title);

        }
        fin.close();
    }
    // insertAtHead(head);
    // printReviews(head);
    
}

// enter reviews 
void enterReview(Node *&reviewNode) {
    cout << "Enter review rating 0-5: ";
    cin >> reviewNode->rating;
    cin.ignore();
    cout << "Enter review comments: ";
    getline(cin, reviewNode->review);
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
        while (current != nullptr) {
            cout << "\t> Review #" << count + 1 << ": " << current->rating << ": " << current->review << endl;
            total += current->rating;
            ++count;
            current = current->next;
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
