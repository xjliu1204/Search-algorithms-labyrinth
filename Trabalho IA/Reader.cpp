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
    
    long long int rooms, origin, destination, m, n, *matrix, currentPosition, i = 0, j = 0, room, heuristicValue;
    string line;
    
    inputFile >> m >> n >> rooms >> origin >> destination;
    
    Maze * maze = new Maze(file, rooms, new Room(origin), new Room(destination));
    
    matrix = new long long int(m * n);
    
    for(i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            inputFile >> matrix[i * n + j];

    for(i = 0; i < m; ++i){
        for(j = 0; j < n; ++j){
            currentPosition = i * n + j;
            if(!matrix[currentPosition])
                continue;
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
    
    while(inputFile >> room >> heuristicValue)
        maze->getRoom(room)->setHeuristicValue(heuristicValue);
    
    inputFile.close();
    
    cout << "- - - - - - Done processing maze " << file << " - - - - - - " << endl;
    
    return maze;
}

vector<Maze*> Reader::parseInputFolder(string inputFolder){
    list<string> files = (new Helper)->getFilesInDirectory(inputFolder);
    vector<Maze*> mazes;
    
    for(string file : files)
        mazes.push_back(parseMaze(file));
    
    return mazes;
}
