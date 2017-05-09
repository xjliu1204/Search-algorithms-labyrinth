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
    Nary_tree * tree;
    virtual void searchAlgorithm(Maze * m) = 0;
    char operationOrder[4] = {'L', 'B', 'R', 'T'};
    char getSimetricalOp(int i){
        switch(this->operationOrder[i]){
            case 'L':
                return 'R';
            case 'R':
                return 'L';
            case 'B':
                return 'T';
            default:
                return 'B';
        }
    };
public:
    virtual string getName() = 0;
    virtual string getTreeHeight() = 0;
    virtual string getSolution() = 0;
    
    void search(Maze * m) {
        searchAlgorithm(m);
    };
};


#endif /* SortAlgorithm_hpp */
