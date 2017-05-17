//
//  TreeNode.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 08/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
#include "State.hpp"
#include "Helper.hpp"

class TreeNode {
public:
    State * state;
    TreeNode * child;
    TreeNode * sibling;
    TreeNode * father;
    TreeNode(State * state) {this->state = state; this->child = NULL; this->sibling = NULL;};
    TreeNode * insertChild(TreeNode * node);
    TreeNode * getLastSibling(TreeNode * node);
    TreeNode * getLastChild(TreeNode * node);
    std::list<TreeNode*> getChildren();
};

#endif /* TreeNode_hpp */
