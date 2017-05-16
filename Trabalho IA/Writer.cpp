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
    this->algorithm = algorithm;
}

void Writer::writeResults(double elapsedTime, Maze * m, Nary_tree * tree){
    fstream file;
    
    file.open(this->outputFile, fstream::out);
    
    file << "Running search @ " << h->getCurrentTimeStamp() << endl;
    file << "########TEST PARAMS########" << endl;
    file << "Number of rooms: " << m->getRooms() << endl;
    file << "Number of doors: " << m->getNumberOfDoors() << endl;
    file << "Algorithm: " << algorithm << endl;
    
    file << "Elapsed time: " << elapsedTime << " ms" << endl;
    file << "Tree: " << tree->getStatesTree(m->getDestination()->getId()) << endl;
    file << "Tree height: " << tree->getTreeHeight() << endl;
    file << "Average expanded states: " << tree->getAverageExpandedStates() << endl;
    file << "Success: " << tree->getSolution() << endl;
    file.close();
}
