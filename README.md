[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `[Gilbert Venegas]`  
### **Student ID:** `[132166681]`  

---

## **1. Project Overview**
This project is my text based RPG using a binary decision tree. In this game, I made a hashnet which grabs different story lines from my story.txt. The game ends when it hits the leaf node that has a -1 or 1 value.  The actual story is that you wake up from a zombie apocalypse, and are running away from the zombies. The ending is either you survive by running away or you die at the end from some sort of accident.

Example:
>This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `[Main File was used for starting the code and locating the story file onto the program]`  
- **`GameDecisionTree.h`** → `[Created the hash tree where I also included the 2 choices of going left or right]`  
- **`Node.h`** → `[This file contains the template of the binary tree, its got the nodes, the left pointer and the right pointer.]`  
- **`Story.h`** → `[In this file, I have the 3 different constructors, I have the default constructor, a 4 parameter constructor and a 6 parameter constructor.]`  
- **`story.txt`** → `[The game loads the story from this by following the format I am using where its the eventnum, description, the choice 1, left child,  and choice 2, and my right child ]`  

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

    The decision tree is using the constructors from story.h, in order to read the story.txt. In the story.txt file, I have the stories
    connect with each other by the value of the nodes. They are linked based on the left and ride based on the value of the event number. 
    If the event has a -1 as the left or right child, it shows that it is the leaf node which means the story ends at this point. 

- How are `Story` objects created from the text file?  
- How are nodes linked based on left and right event numbers?  
- What happens if an event has `-1` as left or right children?  

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

    The game moves through the decision recursively. The story continues based on the decision of path 1 or path 2. If 1 is chosen, the left 
    event number is chosen, if 2 is chose, the right event number is chosen. When a player reaches the leaf node, it stops the program and 
    it prints out the text The End. In the special case where multiple events lead to the same outcome it still prints the same message
    at the end. 

- How does user input determine the path taken?  
- What happens when the player reaches a leaf node?  
- Explain the special case where multiple events lead to the same outcome.  

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

    The file is read and parsed using a delimiter by using | to split the text between different tokens using stringstream.
    I ensured that they were properly linked using recursion. I started at the root of the tree and went down. I made sure to link each 
    part of the story until the end was reached. And I made sure the game all had a base case.  A challenge I have and still have to fix is 
    prrinting the end part of the story properly. 

- How is the file read and parsed using a delimiter?  
- How do you ensure nodes are properly linked?  
- Any challenges faced while handling file input?  

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

    One debugging challenge I had was that the nodes would not properly connect to each other when running the program and it was 
    stopping at the beginning of the story without continuing onto it. I fixed it by making sure it connecting to the right next node that was
    inputted with the key value.

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)

    An example of how the game runs is it starts like this 
    You wake up in a wrecked hospital with zombies outside.
    Enter your choice:
    1)  Sneak out the back
    2)  Fight your way through
    //player responds like this by putting 1
    1
---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

    Because I am using a hashmap, it's O(n) for leading the tree from the file. It should be the same for 
    searching the event in the tree. As for the game traversal efficiency, Its worse case would be O(n)
    
- **Loading the tree from the file** → `O(?)`  
- **Searching for an event in the tree** → `O(?)`  
- **Game traversal efficiency** → `O(?)`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

    I tested the scenario where I keep running until I trip and then I end up dying from exhaustion. Which is one of the leaf notes 
    so it ran succesffully. 

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

    The key features I added was mainly the extra constructors so that I had more options I can add onto the story. 

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
