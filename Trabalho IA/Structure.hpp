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
    TreeNode * state;
    Structure(Room * room, TreeNode * state) {this->room = room; this->state = state;};
};

#endif /* Structure_hpp */
