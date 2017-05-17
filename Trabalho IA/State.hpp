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
    long long int roomId;
    long long int presentedBy;
    char op;
    long long int cost;
public:
    State(long long int roomId, long long int presentedBy, char op, long long int cost)
        {this->roomId = roomId; this->presentedBy = presentedBy; this-> op = op; this->cost = cost;};
    long long int getPresentedBy() {return this->presentedBy;};
    char getOp() {return this->op;};
    long long int getRoomId() {return this->roomId;};
    long long int getCost() {return this->cost;};
};

#endif /* State_hpp */
