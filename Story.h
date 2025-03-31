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
    string choice1Text;
    string choice2Text;

    // Default constructor
    Story();

    // 4-parameter constructor (legacy support, optional)
    Story(string desc, int num, int leftNum, int rightNum);

    // ✅ New constructor with labeled choices
    Story(string desc, int num, string choice1, int leftNum, string choice2, int rightNum);
};

#endif // STORY_H
