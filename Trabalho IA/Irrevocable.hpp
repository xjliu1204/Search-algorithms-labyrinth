//
//  Irrevocable.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 09/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef Irrevocable_hpp
#define Irrevocable_hpp

#include "SearchAlgorithm.hpp"
#include "Maze.hpp"

class Irrevocable : public SearchAlgorithm {
private:
    void searchAlgorithm(Maze * m);
public:
    string getName();
};

#endif /* Irrevocable_hpp */
