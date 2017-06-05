//
//  IDAStar.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 05/06/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "IDAStar.hpp"


string IDAStar::getName(){
    return "IDA*";
};

bool IDAStar::sortingFunction(Structure * a, Structure * b){
    return a->room->getHeuristicValue() + a->node->state->getCost() >
    b->room->getHeuristicValue() + b->node->state->getCost();
}

void IDAStar::searchAlgorithm(Maze * m){
    char op;
    this->success = this->failure = false;
    
    this->tree->setRoot((new State(m->getOrigin()->getId(), -1, 'N', 0)));
    TreeNode * currentState = this->tree->getRoot();
    Room * r = m->getOrigin();
    Room * nr = nullptr;
    long long int bound = r->getHeuristicValue(), oldBound = -1, iterationBound = LLONG_MAX;
    
    while(!this->success || this->failure){
        if(bound == oldBound){
            this->failure = true;
            break;
        }
    
        if (r->getId() == m->getDestination()->getId() && currentState->state->getCost() + r->getHeuristicValue() <= bound){
            success = true;
            break;
        }
        
        if(currentState->state->getCost() + r->getHeuristicValue() > bound){
            //Updates the iteration bound
            iterationBound = min(iterationBound, currentState->state->getCost() + r->getHeuristicValue());
            
            //Room becomes the room that presented this iterations room
            r = r->getRoom(r->getVisitedByOp());
            
            //Removes current state and currentState becomes the previous state
            currentState = this->tree->removeState(currentState);
            
            continue;
        }
        
        nr = this->getFirstNonVisitedRoomByHeuristicValue(r, &op);
        
        //If a new room wasn't assigned
        if(nr == NULL){
            //If it's the origin room
            if(r->getId() == m->getOrigin()->getId()){
                //Resets the bound
                oldBound = bound; bound = iterationBound; iterationBound = LLONG_MAX;
                
                //Clears the maze so it can begin searching again
                m->clear();
            } else {
                //Room becomes the room that presented this iteration room
                r = r->getRoom(r->getVisitedByOp());
                
                //Removes current state and currentState becomes the previous state
                currentState = this->tree->removeState(currentState);
            }
        } else {
            //Adds a new state and currentState becomes it
            currentState = this->tree->addState(currentState, new State(nr->getId(), r->getId(), op,
                                                                        currentState->state->getCost() + 1));
            
            //Room becomes the next room
            r = nr;
        }
    }
}
