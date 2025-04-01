#include "Story.h"

// TODO: Default constructor
Story::Story() : description(""), eventNumber(0), leftEventNumber(-1), rightEventNumber(-1) {}

// TODO: Parameterized constructor
Story::Story(std::string desc, int num, int leftNum, int rightNum)
        : description(desc), eventNumber(num), leftEventNumber(leftNum), rightEventNumber(rightNum) {}

Story::Story(std::string desc, int num, std::string choice1, int leftNum, std::string choice2, int rightNum)
    : description(desc), eventNumber(num),
      choice1Text(choice1), leftEventNumber(leftNum),
      choice2Text(choice2), rightEventNumber(rightNum) {}