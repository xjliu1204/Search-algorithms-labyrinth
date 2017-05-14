//
//  Reader.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 27/04/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef Reader_hpp
#define Reader_hpp

#include "Helper.hpp"
#include "Maze.hpp"
#include <list>

using namespace std;

class Reader{
public:
    int read(string file, int** A);
    vector<Maze*> parseInputFolder(string inputFolder);
    Maze * parseMaze(string file);
};

#endif /* Reader_hpp */
