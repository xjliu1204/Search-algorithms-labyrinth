//
//  State.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 08/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>

class State{
private:
    int roomId;
    int presentedBy;
    char op;
public:
    State(int roomId, int presentedBy, char op) {this->roomId = roomId; this->presentedBy = presentedBy; this-> op = op;};
    int getPresentedBy() {return this->presentedBy;};
    char getOp() {return this->op;};
};

#endif /* State_hpp */
