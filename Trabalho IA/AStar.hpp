//
//  AStar.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 09/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef AStar_hpp
#define AStar_hpp

#include "SearchAlgorithm.hpp"
#include "Structure.hpp"

class AStar : public SearchAlgorithm {
private:
    void searchAlgorithm(Maze * m);
public:
    string getName();
};


#endif /* AStar_hpp */
