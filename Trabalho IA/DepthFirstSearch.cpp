//
//  DepthFirstSearch.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 09/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "DepthFirstSearch.hpp"

string DepthFirstSearch::getName(){
    return "Depth First Search";
};

void DepthFirstSearch::searchAlgorithm(Maze * m){
    int i;
    this->success = false;
    TreeNode * currentState;
    stack<Structure*> structureStack;
    
    this->tree->setRoot((new State(m->getOrigin()->getId(), -1, 'N')));
    
    structureStack.push(new Structure(m->getOrigin(), this->tree->getRoot()));
    
    Room * nr = nullptr, * r;
    while(!structureStack.empty()){
        r = structureStack.top()->room;
        currentState = structureStack.top()->state;
        structureStack.pop();
        
        if (r->getId() == m->getDestination()->getId()){
            this->success = true;
            break;
        }
        
        for(i = 3; i >= 0; --i){
            char op = this->operationOrder[i];
            nr = r->getRoom(op);
            if(nr != NULL && !nr->wasVisited()){
                nr->visit(this->getSimetricalOp(op));
                structureStack.push(new Structure(nr,
                    this->tree->addState(currentState, new State(nr->getId(), r->getId(), op))));
            }
        }
    }
    
    this->failure = !this->success;
}

