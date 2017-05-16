//
//  SortAlgorithm.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 27/04/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef SortAlgorithm_hpp
#define SortAlgorithm_hpp

#include "Helper.hpp"
#include "Maze.hpp"
#include "Nary_tree.hpp"

using namespace std;

class SearchAlgorithm {
protected:
    bool success, failure;
    Nary_tree * tree;
    virtual void searchAlgorithm(Maze * m) = 0;
    char operationOrder[4] = {'R', 'L', 'B', 'T'};
    char getSimetricalOp(char c);
    Room * getFirstNonVisitedRoomByOpOrder(Room * r, char * c);
    
public:
    virtual string getName() = 0;
    virtual Nary_tree * getTree() {return this->tree;};
    
    SearchAlgorithm() {this->tree = new Nary_tree();};
    
    void search(Maze * m) {
        searchAlgorithm(m);
    };
};


#endif /* SortAlgorithm_hpp */
