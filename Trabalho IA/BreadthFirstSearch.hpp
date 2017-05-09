//
//  BreadthFirstSearch.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 09/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef BreadthFirstSearch_hpp
#define BreadthFirstSearch_hpp

#include "SearchAlgorithm.hpp"
#include "Structure.hpp"

class BreadthFirstSearch : public SearchAlgorithm {
private:
    void searchAlgorithm(Maze * m);
public:
    string getName();
};


#endif /* BreadthFirstSearch_hpp */
