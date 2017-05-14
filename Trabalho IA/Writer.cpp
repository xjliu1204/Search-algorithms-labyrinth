//
//  Writer.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 08/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "Writer.hpp"

Writer::Writer(string file, string algorithm){
    this->outputFile = file.replace(file.end() - 3, file.end(), "_" + algorithm + "_output.txt");
    this->h = new Helper();
}

void Writer::writeHeader(Maze * m)
{
    fstream file;
    file.open(this->outputFile, fstream::out);
    
    file << "Running search @ " << h->getCurrentTimeStamp() << endl;
    file << "########TEST PARAMS########" << endl;
    file << "Number of rooms: " << m->getRooms() << endl;
    file << "Number of doors: " << m->getNumberOfDoors() << endl;
    file << "Algorithm: " << algorithm->getName() << endl;
    
    file.close();
}

void Writer::writeResults(double elapsedTime, string solution, string treeHeight){
    fstream file;
    file.open(this->outputFile, fstream::out);
    
    file << "Time elapsed: " << elapsedTime << " ms" << endl;
    file << "Solution: " << solution << " ms" << endl;
    file << "Tree height: " << treeHeight << " ms" << endl;
    file << "Average expanded states: " << treeHeight << " ms" << endl;
    file.close();
}
