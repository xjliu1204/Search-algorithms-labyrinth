//
//  SearchAlgorithm.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 09/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "SearchAlgorithm.hpp"

Room * SearchAlgorithm::getFirstNonVisitedRoomByOpOrder(Room * r, char * c){
    Room * nr;
    for(auto &&c : this->operationOrder){
        nr = r->getRoom(c);
        if(nr != NULL && !nr->wasVisited()){
            nr->visit(this->getSimetricalOp(c));
            return nr;
        }
    }
    
    return NULL;
}

char SearchAlgorithm::getSimetricalOp(char c){
    switch(c){
        case 'L':
            return 'R';
        case 'R':
            return 'L';
        case 'B':
            return 'T';
        default:
            return 'B';
    }
};
