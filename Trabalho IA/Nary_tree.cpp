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
    if(alreadyOpened(state) != NULL){
        return father->insertChild(state);
    }
    
    return NULL;
}

TreeNode * Nary_tree::removeState(TreeNode * state){
    TreeNode * n = state->father;
    
    if(n->child == state)
        n->child = NULL;
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
    
    state = this->destroy(state);
    
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
