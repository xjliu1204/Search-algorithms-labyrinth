//
//  Structure.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 09/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef Structure_hpp
#define Structure_hpp

#include "TreeNode.hpp"
#include "State.hpp"

class Structure{
public:
    Room * room;
    TreeNode * node;
    Structure(Room * room, TreeNode * node) {this->room = room; this->node = node;};
};

#endif /* Structure_hpp */
