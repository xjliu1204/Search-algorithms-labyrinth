//
//  Nary_tree.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 08/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "Nary_tree.hpp"

using namespace std;

TreeNode * Nary_tree::alreadyOpened(State * state){
    queue<TreeNode*> queue;
    vector<TreeNode*> children;
    queue.push(this->root);
    TreeNode * n;
    
    while(!queue.empty()){
        n = queue.front();
        queue.pop();
        
        if(n->state == state)
            return n;
        
        children = n->getChildren();
        
        while(!children.empty()){
            queue.push(children.back());
            children.pop_back();
        }
    }
    
    return NULL;
}

TreeNode * Nary_tree::addState(TreeNode * father, State *state){
    return father->insertChild(new TreeNode(state));
}

TreeNode * Nary_tree::removeState(TreeNode * state){
    TreeNode * n = state->father;
    
    if(n->child == state)
        n->child = state->sibling;
    else {
        TreeNode * child = n->child;
        while(child->sibling != NULL){
            if(child->sibling == state){
                child->sibling = child->sibling->sibling;
                break;
            }

            child = child->sibling;
        }
    }
    
    //state = this->destroy(state);
    
    return n;
}

TreeNode * Nary_tree::destroy(TreeNode * node){
    if (node->child != NULL)
        return node->child = destroy(node->child);
    if (node->sibling != NULL)
        return node->sibling = destroy(node->sibling);
    else
        return NULL;
}

string Nary_tree::getStatesTree(long long int destination){
    queue<TreeNode*> queue;
    vector<TreeNode*> children;
    queue.push(this->root);
    TreeNode * n;
    
    this->treeHeight = 0;
    //Disconsider the root
    this->expandedStates = -1;
    
    stringstream statesTree;
    long long int father = this->root->state->getRoomId();
    
    stack<TreeNode*> path;
    
    while(!queue.empty()){
        n = queue.front();
        queue.pop();
        
        path.push(n);
        
        if(n->state->getPresentedBy() != -1){
            if(father != n->state->getPresentedBy()){
                father = n->state->getPresentedBy();
                statesTree << "\n";
                ++this->treeHeight;
            }
            statesTree << n->state->getPresentedBy() << " -" << n->state->getOp() << "-> " << n->state->getRoomId() << " || ";
        }
        
        children = n->getChildren();
        while(!children.empty()){
            queue.push(children.back());
            children.pop_back();
            ++this->expandedStates;
        }
    }

    if(path.top()->state->getRoomId() == destination){
        long long int father = 0;
        while(!path.empty()){
            n = path.top();
            path.pop();
            
            if(n->state->getRoomId() == destination || n->state->getRoomId() == father){
                this->solutionPath.push(n);
                father = n->state->getPresentedBy();
            }
        }
    }
    
    return statesTree.str();
}

unsigned long long int Nary_tree::getTreeHeight(){
    return this->treeHeight;
}

double Nary_tree::getAverageExpandedStates(){
    return (double) this->expandedStates / this->getTreeHeight();
}

string Nary_tree::getSolution(){
    stringstream solution;
    
    if(this->solutionPath.empty())
        solution << "False";
    else {
        solution << "True\n";
        
        //Popping the first room
        this->solutionPath.pop();
        
        while(!this->solutionPath.empty()){
            TreeNode * top = this->solutionPath.top();
            this->solutionPath.pop();
            
            solution << top->state->getPresentedBy() << "-" << top->state->getOp() << "->";
            if(this->solutionPath.size() == 0)
                solution << top->state->getRoomId();
        }
    }
    
    return solution.str();
}
