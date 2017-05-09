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
    stack<Room*> rooms;
    stack<TreeNode*> states;
    
    this->tree->setRoot((new State(m->getOrigin()->getId(), -1, 'N')));
    states.push(this->tree->getRoot());
    rooms.push(m->getOrigin());
    Room * nr = nullptr, * r;
    
    while(!rooms.empty()){
        r = rooms.top();
        rooms.pop();
        currentState = states.top();
        states.pop();
        
        if (r->getId() == m->getDestination()->getId()){
            this->success = true;
            break;
        }
        
        for(i = 3; i >= 0; --i){
            char op = this->operationOrder[i];
            nr = r->getRoom(op);
            if(nr != NULL && !nr->wasVisited()){
                nr->visit(this->getSimetricalOp(op));
                rooms.push(nr);
                states.push(this->tree->addState(currentState, new State(nr->getId(), r->getId(), op)));
            }
        }
    }
    
    this->failure = !this->success;
}

