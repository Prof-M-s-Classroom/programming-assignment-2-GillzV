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
    unordered_map<int, Node<T>*> nodeMap;

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

        string line;

        //  Creating the Nodes
        while (getline(file, line)) {
            stringstream ss(line);
            string token;

            string eventStr, desc, choice1, leftStr, choice2, rightStr;

            if (!getline(ss, eventStr, delimiter)) continue;
            if (!getline(ss, desc, delimiter)) continue;
            if (!getline(ss, choice1, delimiter)) continue;
            if (!getline(ss, leftStr, delimiter)) continue;
            if (!getline(ss, choice2, delimiter)) continue;
            if (!getline(ss, rightStr, delimiter)) continue;

            try {
                int eventNum = stoi(eventStr);
                int left = stoi(leftStr);
                int right = stoi(rightStr);

                T story(desc, eventNum, choice1, left, choice2, right);
                nodeMap[eventNum] = new Node<T>(story);
            } catch (invalid_argument& e) {
                cerr << "Error parsing line: " << line << "\n";
                continue; // skip bad lines
            }
        }

        // Connecting Children Nodes
        for (auto& [id, node] : nodeMap) {
            int l = node->data.leftEventNumber;
            int r = node->data.rightEventNumber;

            // Connect left child
            if (l != -1) {
                auto it = nodeMap.find(l);
                if (it != nodeMap.end()) {
                    node->left = it->second;
                } else {
                    node->left = nullptr;
                }
            } else {
                node->left = nullptr;
            }

            // Connect right child
            if (r != -1) {
                auto it = nodeMap.find(r);
                if (it != nodeMap.end()) {
                    node->right = it->second;
                } else {
                    node->right = nullptr;
                }
            } else {
                node->right = nullptr;
            }
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

            // Check if this is an ending (both paths are -1)
            if (current->data.leftEventNumber == -1 && current->data.rightEventNumber == -1) {
                cout << "The End.\n";
                break;
            }

            // Only show choices that lead somewhere
            cout << "Enter your choice:\n";
            if (current->data.leftEventNumber != -1) {
                cout << "1) " << current->data.choice1Text << "\n";
            }
            if (current->data.rightEventNumber != -1) {
                cout << "2) " << current->data.choice2Text << "\n";
            }

            int choice;
            while (true) {
                cin >> choice;

                if (!cin) {
                    cout << "Invalid input. Please enter a number (1 or 2).\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else if (choice != 1 && choice != 2) {
                    cout << "Invalid choice. Please enter 1 or 2.\n";
                } else if (choice == 1 && current->data.leftEventNumber == -1) {
                    cout << "That path leads to certain death. Choose another option.\n";
                } else if (choice == 2 && current->data.rightEventNumber == -1) {
                    cout << "That path leads to certain death. Choose another option.\n";
                } else {
                    break;
                }
            }

            if (choice == 1) {
                if (current->left) {
                    current = current->left;
                } else if (current->data.leftEventNumber == -1) {
                    cout << "The End.\n";
                    break;
                } else {
                    // Find the ending node
                    auto it = nodeMap.find(current->data.leftEventNumber);
                    if (it != nodeMap.end()) {
                        cout << it->second->data.description << "\n";
                    }
                    cout << "The End.\n";
                    break;
                }
            } else if (choice == 2) {
                if (current->right) {
                    current = current->right;
                } else if (current->data.rightEventNumber == -1) {
                    cout << "The End.\n";
                    break;
                } else {
                    // Find the ending node
                    auto it = nodeMap.find(current->data.rightEventNumber);
                    if (it != nodeMap.end()) {
                        cout << it->second->data.description << "\n";
                    }
                    cout << "The End.\n";
                    break;
                }
            }
        }
    }

};

#endif // GAMEDECISIONTREE_H

