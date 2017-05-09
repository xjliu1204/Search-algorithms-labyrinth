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
    queue<Room*> rooms;
    queue<TreeNode*> states;
    
    this->tree->setRoot((new State(m->getOrigin()->getId(), -1, 'N')));
    states.push(this->tree->getRoot());
    rooms.push(m->getOrigin());
    Room * nr = nullptr, * r;
    
    while(!rooms.empty()){
        r = rooms.front();
        rooms.pop();
        currentState = states.front();
        states.pop();
        
        if (r->getId() == m->getDestination()->getId()){
            this->success = true;
            break;
        }
        
        for(char op : this->operationOrder){
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

