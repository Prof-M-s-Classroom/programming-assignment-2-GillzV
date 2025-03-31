#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"
#include <limits>


using namespace std;

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const string& filename, char delimiter) {
        ifstream file(filename);
        if (!file) {
            cerr << "Failed to open file: " << filename << "\n";
            return;
        }

        unordered_map<int, Node<T>*> nodeMap;
        string line;

        //  Creating the Nodes
        while (getline(file, line)) {
            stringstream ss(line);
            string token;

            getline(ss, token, delimiter);
            int eventNum = stoi(token);

            getline(ss, token, delimiter);
            string desc = token;

            getline(ss, token, delimiter);
            int left = stoi(token);

            getline(ss, token, delimiter);
            int right = stoi(token);

            T story{desc, eventNum, left, right};
            nodeMap[eventNum] = new Node<T>(story);
        }

        // Connecting Children Nodes
        for (auto& [id, node] : nodeMap) {
            int l = node->data.leftEventNumber;
            int r = node->data.rightEventNumber;

            node->left = (l != -1) ? nodeMap[l] : nullptr;
            node->right = (r != -1) ? nodeMap[r] : nullptr;
        }

        // Setting the Root Node
        root = nodeMap.count(1) ? nodeMap[1] : nullptr;
    }



    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        if (!root) {
            cout << "Load a story to start playing.\n";
            return;
        }

        Node<T>* current = root;
        while (true) {
            cout << "\n" << current->data.description << "\n";

            if (current->data.leftEventNumber == -1 && current->data.rightEventNumber == -1) {
                cout << "The End.\n";
                break;
            }

            cout << "Enter your choice:\n"
                 << "1) Go Left\n"
                 << "2) Go Right\n";

            int choice;
            while (true) {
                cin >> choice;

                if (!cin) {
                    cout << "Invalid input. Please enter a number (1 or 2).\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else if (choice != 1 && choice != 2) {
                    cout << "Invalid choice. Please enter 1 or 2.\n";
                } else {
                    break;
                }
            }

            if (choice == 1) {
                if (current->left) {
                    current = current->left;
                } else {
                    cout << "No further path in that direction. The story ends here.\n";
                    break;
                }
            } else if (choice == 2) {
                if (current->right) {
                    current = current->right;
                } else {
                    cout << "No further path in that direction. The story ends here.\n";
                    break;
                }
            }
        }
    }

};

#endif // GAMEDECISIONTREE_H

