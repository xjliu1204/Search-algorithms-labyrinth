//
//  Backtracking.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 09/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "Backtracking.hpp"

string Backtracking::getName(){
    return "Backtracking";
};

void Backtracking::searchAlgorithm(Maze * m){
    int i;
    bool success = false, failure = false;
    
    this->tree->setRoot((new State(m->getOrigin()->getId(), -1, 'N')));
    TreeNode * father = this->tree->getRoot();
    Room * r = m->getOrigin();
    Room * nr = nullptr;
    
    while(!success || failure){
        int fatherId = r->getId();
        
        //Get the first non visited room by op order
        for(i = 3; i >= 0; --i){
            nr = r->getRoom(this->operationOrder[i]);
            if(nr != NULL && !nr->wasVisited()){
                r = nr;
                r->visit(this->getSimetricalOp(i));
                break;
            }
        }
        
        //If a new room wasn't assigned
        if(r != nr){
            //If it's the origin room
            if(r->getId() == m->getOrigin()->getId())
                failure = true;
            else {
                //Room becomes the room that presented this iterations room
                r = r->getRoom(r->getVisitedBy());
                
                //Removes current state and father becomes the previous state
                father = this->tree->removeState(father);
            }
        } else {
            //Adds a new state and father becomes it
            father = this->tree->addState(father, new State(r->getId(), fatherId, this->operationOrder[i]));
            
            if (r->getId() == m->getDestination()->getId())
                success = true;
        }
    }
}

