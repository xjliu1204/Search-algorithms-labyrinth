//
//  Irrevocable.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 09/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "Irrevocable.hpp"

string Irrevocable::getName(){
    return "Irrevocable";
};

void Irrevocable::searchAlgorithm(Maze * m){
    char op;
    this->success = this->failure = false;
    
    this->tree->setRoot((new State(m->getOrigin()->getId(), -1, 'N')));
    TreeNode * currentState = this->tree->getRoot();
    Room * r = m->getOrigin();
    Room * nr = nullptr;
    
    while(!success || failure){
        if (r->getId() == m->getDestination()->getId()){
            success = true;
            break;
        }
        
        nr = this->getFirstNonVisitedRoomByOpOrder(r, &op);
        
        //If a new room wasn't assigned
        if(nr == NULL){
            failure = true;
            break;
        } else {
            //Adds a new state and currentState becomes it
            currentState = this->tree->addState(currentState, new State(nr->getId(), r->getId(), op));
            
            //Room becomes the next room
            r = nr;
        }
    }
}

