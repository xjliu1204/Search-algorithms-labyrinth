//
//  IDAStar.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 05/06/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef IDAStar_hpp
#define IDAStar_hpp

#include "SearchAlgorithm.hpp"
#include "Structure.hpp"

class IDAStar : public SearchAlgorithm {
private:
    void searchAlgorithm(Maze * m);
    static bool sortingFunction(Structure * a, Structure * b);
public:
    string getName();
};

#endif /* IDAStar_hpp */
