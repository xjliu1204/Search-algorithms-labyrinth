//
//  TreeNode.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 08/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "TreeNode.hpp"

using namespace std;

TreeNode * TreeNode::insertChild(State * state){
    TreeNode * node = new TreeNode(state);
    
    if(child == NULL)
        this->child = node;
    else {
        TreeNode * lastSibling = getLastSibling(this->child);
        lastSibling->sibling = node;
    }
    
    node->father = this;
    
    return node;
}

TreeNode * TreeNode::getLastSibling(TreeNode * node){
    if(node->sibling == NULL)
        return node;
    else
        return getLastSibling(node->sibling);
}

vector<TreeNode*> TreeNode::getChildren(){
    vector<TreeNode*> children;
    
    if(this->child != NULL){
        TreeNode* child = this->child;
        
        children.push_back(child);
        
        while(child->sibling != NULL){
            child = child->sibling;
            children.push_back(child);
        }
    }
    
    return children;
}
