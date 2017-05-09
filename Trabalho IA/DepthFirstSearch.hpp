//
//  DepthFirstSearch.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 09/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef DepthFirstSearch_hpp
#define DepthFirstSearch_hpp

#include "SearchAlgorithm.hpp"
#include "Maze.hpp"

class DepthFirstSearch : public SearchAlgorithm {
private:
    void searchAlgorithm(Maze * m);
public:
    string getName();
};

#endif /* DepthFirstSearch_hpp */
