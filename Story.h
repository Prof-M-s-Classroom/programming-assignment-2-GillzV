#ifndef STORY_H
#define STORY_H

#include <string>
using namespace std;

class Story {
public:
    string description;
    int eventNumber;
    int leftEventNumber;
    int rightEventNumber;

    // Default constructor
    Story();
    // Parameterized constructor     //The int num is the identifier for the event
    Story(string desc, int num, int leftNum, int rightNum);
};
#endif // STORY_H


