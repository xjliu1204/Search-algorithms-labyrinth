//
//  Writer.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 08/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef Writer_hpp
#define Writer_hpp

#include <stdio.h>

#include "Helper.hpp"
#include "SearchAlgorithm.hpp"

class Writer{
    string outputFile;
    SearchAlgorithm * algorithm;
    Helper * h;
public:
    Writer(string file, string algorithm);
    void writeHeader(Maze * m);
    void writeResults(double elapsedTime, string solution, string treeHeight);
};

#endif /* Writer_hpp */
