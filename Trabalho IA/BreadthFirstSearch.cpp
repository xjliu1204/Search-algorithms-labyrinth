//
//  BreadthFirstSearch.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 09/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "BreadthFirstSearch.hpp"

string BreadthFirstSearch::getName(){
    return "Breadth First Search";
};

void BreadthFirstSearch::searchAlgorithm(Maze * m){
    this->success = false;
    TreeNode * currentState;
    queue<Structure*> structureQueue;
    
    this->tree->setRoot((new State(m->getOrigin()->getId(), -1, 'N', 0)));
    
    structureQueue.push(new Structure(m->getOrigin(), this->tree->getRoot()));
    
    Room * nr = nullptr, * r;
    while(!structureQueue.empty()){
        r = structureQueue.front()->room;
        currentState = structureQueue.front()->node;
        structureQueue.pop();
        
        if (r->getId() == m->getDestination()->getId()){
            this->success = true;
            break;
        }
        
        for(char op : this->operationOrder){
            nr = r->getRoom(op);
            if(nr != NULL && !nr->wasVisited()){
                nr->visit(this->getSimetricalOp(op));
                
                structureQueue.push(new Structure(nr,
                                                        this->tree->addState(currentState, new State(nr->getId(), r->getId(), op, currentState->state->getCost() + 1))));
            }
        }
    }
    
    this->failure = !this->success;
}

