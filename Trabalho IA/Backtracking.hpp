//
//  SelectionSort.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 27/04/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef SelectionSort_hpp
#define SelectionSort_hpp

#include "SearchAlgorithm.hpp"
#include "Maze.hpp"

class Backtracking : public SearchAlgorithm {
private:
    void searchAlgorithm(Maze * m);
public:
    string getName();
    string getTreeHeight() {return "teste";};
    string getSolution() {return "teste";};
};


#endif /* SelectionSort_hpp */
