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
#include "Result.hpp"

class Writer{
private:
    string outputFile, algorithm;
    Helper * h;
public:
    Writer(string file);
    Writer(string file, string algorithm);
    void writeResults(double elapsedTime, Maze * m, Nary_tree * tree);
    static void writeStatistcs(string outputFile);
};

#endif /* Writer_hpp */
