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
    for(char op : this->operationOrder){
        nr = r->getRoom(op);
        if(nr != NULL && !nr->wasVisited()){
            nr->visit(this->getSimetricalOp(op));
            *c = op;
            return nr;
        }
    }
    
    return NULL;
}

Room * SearchAlgorithm::getFirstNonVisitedRoomByHeuristicValue(Room * r, char * c){
    Room * nr, *rnr = NULL;
    long long int heuristicValue = LLONG_MAX;
    for(char op : this->operationOrder){
        nr = r->getRoom(op);
        if(nr != NULL && !nr->wasVisited() && heuristicValue > nr->getHeuristicValue()){
            heuristicValue = nr->getHeuristicValue();
            rnr = nr;
            *c = op;
        }
    }
    
    if(rnr != NULL)
        rnr->visit(this->getSimetricalOp(*c));
    
    return rnr;
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
