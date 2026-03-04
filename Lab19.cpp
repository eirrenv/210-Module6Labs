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
        Movie() {
            head = nullptr;
        }
        // getters and setters for title, rating and review 
        string getTitle() { return movieTitle; }
        void setTitle(string title) { movieTitle = title; }
        Node getRating() { return *head; }
        
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
            cout << "Movie Title: " << movieTitle << endl;
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


int main() {
    Node *head = nullptr;
    vector<Movie> movieVector; // vector containing Movie objects

    string title; // holds temp title
    double rating; // holds temp rating
    string review; // holds temp review

    ifstream fin("text.txt");
    if (fin.good()) {
        while (getline(fin, title)) { // capture data from input file

            Movie tmp; // temporary Movie object to store input data

            tmp.setTitle(title); // set temporary title

            // for loop to contain ratings and reviews
            for (int i = 0; i < NUM_REVIEWS; ++i) {
                fin >> rating;
                fin.ignore();
                getline(fin, review);
                tmp.addReview(rating, review);
            }
            movieVector.push_back(tmp); // add Movie object to vector
        }
        fin.close();
    }
    else {
        cout << "Input file not found.\n";
    }
    // print Movie objects in vector
    for (int i = 0; i < movieVector.size(); ++i) {
        movieVector.at(i).printReviews();
    }
}