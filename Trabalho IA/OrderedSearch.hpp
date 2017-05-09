//
//  OrderedSearch.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 09/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef OrderedSearch_hpp
#define OrderedSearch_hpp

#include "SearchAlgorithm.hpp"
#include "Structure.hpp"

class OrderedSearch : public SearchAlgorithm {
private:
    void searchAlgorithm(Maze * m);
public:
    string getName();
};

#endif /* OrderedSearch_hpp */
