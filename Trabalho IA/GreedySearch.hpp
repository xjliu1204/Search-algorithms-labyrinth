//
//  GreedySearch.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 09/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef GreedySearch_hpp
#define GreedySearch_hpp

#include "SearchAlgorithm.hpp"
#include "Structure.hpp"

class GreedySearch : public SearchAlgorithm {
private:
    void searchAlgorithm(Maze * m);
    static bool sortingFunction(Structure * a, Structure * b);
public:
    string getName();
};

#endif /* GreedySearch_hpp */
