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
    char operationOrder[4] = {'L', 'B', 'R', 'T'};
    char getSimetricalOp(char c);
    Room * getFirstNonVisitedRoomByOpOrder(Room * r, char * c);
    
public:
    virtual string getName() = 0;
    virtual string getTreeHeight() {return "teste";};
    virtual string getSolution() {return "teste";};
    
    void search(Maze * m) {
        searchAlgorithm(m);
    };
};


#endif /* SortAlgorithm_hpp */
