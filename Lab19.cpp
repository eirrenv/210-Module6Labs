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
        Node *head;
    public:
        // getters and setters for title, rating and review 
        string getTitle() { return movieTitle; }
        void setTitle(string title) { movieTitle = title; }
        Node getRating() { return *head; }
        void setRating(double rating, string review) { 
            head->rating = rating;
            head->review = review;
        }
        
        // insert review in Movie object
        void addReview(double rating, string review) {
            Node *newNode = new Node;
            newNode->rating = rating;
            newNode->review = review;
            newNode->next = head;
            head = newNode;
        }

        // print reviews in Movie object
        void printReviews() {
            Node *current = head;
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
};

const int NUM_REVIEWS = 3; // number of reviews per movie

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
            tmp.setTitle(title);
            for (int i = 0; i < NUM_REVIEWS; ++i) {
                tmp.setRating(rating, review);
            }


        }
        fin.close();
    }
    else {
        cout << "Input file not found.\n";
    }
}