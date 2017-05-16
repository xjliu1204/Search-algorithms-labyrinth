//
//  Nary_tree.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 08/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef Nary_tree_hpp
#define Nary_tree_hpp

#include <stdio.h>
#include "TreeNode.hpp"
#include "Helper.hpp"

class Nary_tree{
private:
    TreeNode * root;
    TreeNode * destroy(TreeNode * node);
    unsigned long long int treeHeight, expandedStates;
    stack<TreeNode*> solutionPath;
public:
    Nary_tree() {this->root = NULL;};
    TreeNode * alreadyOpened(State * state);
    TreeNode * addState(TreeNode * father, State * state);
    TreeNode * removeState(TreeNode * state);
    void setRoot(State * state) {this->root = new TreeNode(state);};
    TreeNode * getRoot() {return this->root;};
    string getSolution();
    string getStatesTree(long long int destination);
    unsigned long long int getTreeHeight();
    double getAverageExpandedStates();
};

#endif /* Nary_tree_hpp */
