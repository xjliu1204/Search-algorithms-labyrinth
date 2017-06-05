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
    char op;
    this->success = this->failure = false;
    
    this->tree->setRoot((new State(m->getOrigin()->getId(), -1, 'N', 0)));
    TreeNode * currentState = this->tree->getRoot();
    Room * r = m->getOrigin();
    Room * nr = nullptr;
    
    while(!this->success || this->failure){
        if (r->getId() == m->getDestination()->getId()){
            success = true;
            break;
        }
        
        nr = this->getFirstNonVisitedRoomByOpOrder(r, &op);
        
        //If a new room wasn't assigned
        if(nr == NULL){
            //If it's the origin room
            if(r->getId() == m->getOrigin()->getId()){
                failure = true;
                break;
            }
        
            //Room becomes the room that presented this iteration room
            r = r->getRoom(r->getVisitedByOp());
        
            //Removes current state and currentState becomes the previous state
            currentState = this->tree->removeState(currentState);
        } else {
            //Adds a new state and currentState becomes it
            currentState = this->tree->addState(currentState, new State(nr->getId(), r->getId(), op,
                                                                        currentState->state->getCost() + 1));
            
            //Room becomes the next room
            r = nr;
        }
    }
}

