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
    long long int solutionValue = LLONG_MAX;
    this->success = false;
    TreeNode * currentState;
    vector<Structure*> structureVector;
    
    this->tree->setRoot((new State(m->getOrigin()->getId(), -1, 'N', 0)));
    
    structureVector.push_back(new Structure(m->getOrigin(), this->tree->getRoot()));
    
    Room * nr = nullptr, * r;
    while(!structureVector.empty()){
        //sort DESCENDING the structure vector by heuristic value
        sort(structureVector.begin(), structureVector.end(), this->sortingFunction);
        r = structureVector.back()->room;
        currentState = structureVector.back()->node;
        structureVector.pop_back();
        
        if(this->success && currentState->state->getCost() > solutionValue)
            continue;
        
        if (r->getId() == m->getDestination()->getId() && solutionValue > currentState->state->getCost()){
            this->success = true;
            solutionValue = currentState->state->getCost();
        }
        
        for(char op : this->operationOrder){
            nr = r->getRoom(op);
            if(nr != NULL && (!nr->wasVisited() || this->getTree()->cheaper(nr, currentState->state->getCost() + 1))){
                nr->visit(this->getSimetricalOp(op));
                
                structureVector.push_back(new Structure(nr,
                                                        this->tree->addState(currentState, new State(nr->getId(), r->getId(), op, currentState->state->getCost() + 1))));
            }
        }
    }
    
    this->failure = !this->success;
}
