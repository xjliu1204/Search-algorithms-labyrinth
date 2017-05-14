//
//  Reader.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 27/04/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "Reader.hpp"

Maze * Reader::parseMaze(string file){
    fstream inputFile;
    inputFile.open(file);
    
    long long int rooms, origin, destination, m, n, *matrix, currentPosition;
    Maze * maze = new Maze(file, rooms, new Room(origin), new Room(destination));
    
    matrix = new long long int(m * n);
    
    for(long long int i = 0; i < m; ++i)
        for(long long int j = 0; j < n; ++j)
            matrix[i * n + j] = 1;
    
    for(long long int i = 0; i < m; ++i){
        for(long long int j = 0; j < n; ++j){
            currentPosition = i * n + j;
            if(j != n - 1 && matrix[currentPosition + 1])
                maze->addDoor(matrix[currentPosition], matrix[currentPosition + 1], 'R');
            if(j != 0 && matrix[currentPosition - 1])
                maze->addDoor(matrix[currentPosition], matrix[currentPosition - 1], 'L');
            if(i != m - 1 && matrix[currentPosition + n])
                maze->addDoor(matrix[currentPosition], matrix[currentPosition + n], 'B');
            if(i != 0 && matrix[currentPosition - n])
                maze->addDoor(matrix[currentPosition], matrix[currentPosition - n], 'T');
        }
    }
    
    inputFile.close();
    
    return maze;
}

vector<Maze*> Reader::parseInputFolder(string inputFolder){
    list<string> files = (new Helper)->getFilesInDirectory(inputFolder);
    vector<Maze*> mazes;
    
    for(string file : files){
        mazes.push_back(parseMaze(file));
    }
    
    return mazes;
}
