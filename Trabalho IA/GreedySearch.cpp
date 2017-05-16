//
//  GreedySearch.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 09/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "GreedySearch.hpp"

string GreedySearch::getName(){
    return "Greedy Search";
};

bool GreedySearch::sortingFunction(Structure * a, Structure * b){
    return a->room->getHeuristicValue() > b->room->getHeuristicValue();
}

void GreedySearch::searchAlgorithm(Maze * m){
    this->success = false;
    TreeNode * currentState;
    vector<Structure*> structureVector;
    
    this->tree->setRoot((new State(m->getOrigin()->getId(), -1, 'N')));
    
    structureVector.push_back(new Structure(m->getOrigin(), this->tree->getRoot()));
    
    Room * nr = nullptr, * r;
    while(!structureVector.empty()){
        //sort DESCENDING the structure vector by heuristic value
        sort(structureVector.begin(), structureVector.end(), sortingFunction);
        r = structureVector.back()->room;
        currentState = structureVector.back()->state;
        structureVector.pop_back();
        
        if (r->getId() == m->getDestination()->getId()){
            this->success = true;
            while(!structureVector.empty()){
                this->tree->removeState(structureVector.back()->state);
                structureVector.pop_back();
            }
            break;
        }
        
        for(char op : this->operationOrder){
            nr = r->getRoom(op);
            if(nr != NULL && !nr->wasVisited()){
                nr->visit(this->getSimetricalOp(op));
                
                structureVector.push_back(new Structure(nr,
                    this->tree->addState(currentState, new State(nr->getId(), r->getId(), op))));
            }
        }
    }
    
    this->failure = !this->success;
}
