//
//  Reader.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 27/04/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "Reader.hpp"

/**
 * @param A (int *) shuffled array
 *
 * @return   int    size of array
**/
int Reader::read(string fileName, int** A){
    int n, i = 0;
    string id, line;
    fstream file;

    file.open(fileName);

    file >> id >> n;

    *A = new int[n];

    while(file >> line){
        (*A)[i] = atoi(line.c_str());
        ++i;
    }

    return n;
}

void Reader::parseMaze(Maze *m, string file){
    
}

vector<Maze*> Reader::parseInputFolder(string inputFolder){
    list<string> files = (new Helper)->getFilesInDirectory(inputFolder);
    vector<Maze*> mazes;
    
    for(string file : files){
        int origin = 1;
        int destination = 2;
        string instanceIdentifier = "teste";
        Maze * m = new Maze(file, instanceIdentifier, new Room(origin), new Room(destination));
        parseMaze(m, file);
        mazes.push_back(m);
    }
    
    return mazes;
}
