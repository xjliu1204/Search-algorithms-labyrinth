//
//  main.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 27/04/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include <iostream>

using namespace std;

#include "Reader.hpp"
#include "Writer.hpp"

//Algorithms
#include "Backtracking.hpp"

bool debug = false;
Reader * r = new Reader();
string inputFolder;
string inputHeuristicFile;
int * A;
vector<SearchAlgorithm*> algorithms;
string instance_type;

static void usage(){
    cout << "Usage:\n" <<
    "    ./SortTest [options] [algorithm] \n\n" <<
    "Options:\n" <<
    "    -h                     Show this help\n" <<
    "    -i                     Input folder\n" <<
    "    [-ih]                  Input Heuristic File\n" <<
    "    [--debug]              Print Shuffled Vector before the sorted one\n" <<
    "Algorithm:\n" <<
    "    irrevogavel     Irrevogável\n" <<
    "    backtracking    Backtracking\n" <<
    "    dsf             Busca em Profundidade\n" <<
    "    bsf             Busca em Largura\n" <<
    "    ordenada        Busca ordenada\n" <<
    "    heuristica      Busca heurística\n" <<
    "    a*              A*\n" <<
    "    ida*            IDA*\n";
}

int processArgs(int argc, const char * argv[]){
    if(argc < 2){
        usage();
        return 2;
    }
    
    int argInd;
    
    for(argInd = 1; argInd < argc; ++argInd) {
        if (argv[argInd][0] != '-')
            break;
        
        if (!strcmp(argv[argInd], "-h")) {
            usage();
            return 2;
        } else if (!strcmp(argv[argInd], "-i")) {
            inputFolder = argv[++argInd];
        } else if (!strcmp(argv[argInd], "-ih")) {
            inputHeuristicFile = argv[++argInd];
        } else if (!strcmp(argv[argInd], "--debug")) {
            debug = true;
        }
    }
    
    if(!strcmp (argv[argInd], "all")) {
        algorithms.push_back(new Backtracking());
    } else {
        if(!strcmp (argv[argInd], "irrevogavel")) {
//            algorithms.push_back(new SelectionSort());
            argInd++;
        }
        if(!strcmp (argv[argInd], "backtracking")) {
            algorithms.push_back(new Backtracking());
            argInd++;
        }
        if(!strcmp (argv[argInd], "dsf")) {
//            algorithm = new HeapSort();
            argInd++;
        }
        if(!strcmp (argv[argInd], "bsf")) {
//            algorithm = new InsertionSort();
            argInd++;
        }
        if(!strcmp (argv[argInd], "ordenada")) {
//            algorithm = new MergeSort(mergeMethod);
            argInd++;
        }
        if(!strcmp (argv[argInd], "heuristica")) {
//            algorithm = new QuickSort(partitionMethod);
            argInd++;
        }
        if(!strcmp (argv[argInd], "a*")) {
//            algorithm = new RadixSort();
            argInd++;
        }
        if(!strcmp (argv[argInd], "ida*")) {
//            algorithms.push_back(Backtracking());
            argInd++;
        }
    }
    
    if (argInd != argc - 1) {
        cout << "Invalid Algorithm!!" << endl;
        usage();
        return 4;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    int errors;
    
    if((errors = processArgs(argc, argv)))
        return errors;
    
    Reader * r = new Reader();
    
    cout << "- - - - - - Processing the input - - - - - - " << endl;
    vector<Maze*> mazes = r->parseInputFolder(inputFolder);
    
    for(vector<SearchAlgorithm*>::iterator algorithm = algorithms.begin(); algorithm != algorithms.end(); ++algorithm){
        cout << "Selected Algorithm: " << (*algorithm)->getName() << endl;
        
        for(Maze * m : mazes){
            Writer * w = new Writer(m->getFileName(), (*algorithm)->getName());
            
            w->writeHeader(m);
            clock_t before_sort = clock();
            (*algorithm)->search(m);
            clock_t after_sort  = clock();
            w->writeResults(after_sort - before_sort, (*algorithm)->getSolution(), (*algorithm)->getTreeHeight());
        }
    }
    
    return 0;
}
