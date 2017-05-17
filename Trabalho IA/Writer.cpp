//
//  Writer.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 08/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "Writer.hpp"

static vector<Result*> results;

Writer::Writer(string file){
    this->outputFile = file.replace(file.end() - 3, file.end(), "_" + algorithm + "_output.txt");
    this->h = new Helper();
}

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
    file << "Tree: \n" << tree->getStatesTree(m->getDestination()->getId()) << endl;
    file << "Tree height: " << tree->getTreeHeight() << endl;
    file << "Average expanded states: " << tree->getAverageExpandedStates() << endl;
    
    bool solution = tree->hasSolution();
    file << "Success: " << tree->getSolution() << endl << endl;
    file.close();
    
    results.push_back(new Result(m->getRooms(), m->getNumberOfDoors(), tree->getTreeHeight(), outputFile, algorithm, tree->getAverageExpandedStates(), elapsedTime, solution));
}

void Writer::writeStatistcs(string outputFile){
    fstream file;
    
    file.open(outputFile, fstream::out);
    
    file << "Rooms;Doors;Algorithm;Elapsed Time;Tree Height;Average Expanded States;Success\n";
    
    std::cout.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
    for(Result * r : results){
        stringstream elapsed, avg;
        string e, a;
        elapsed << r->elapsedTime; avg << r->averageExpandedStates;
        e = elapsed.str(); a = avg.str();
        replace(e.begin(), e.end(), '.', ',');
        replace(a.begin(), a.end(), '.', ',');
        
        file << r->rooms << ";" << r->doors << ";" << r->algorithm << ";"
        << e << ";" << r->treeHeight << ";" << a << ";" << r->success << "\n";
    }
    
    file.close();
}
