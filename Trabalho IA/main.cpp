//
//  main.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 27/04/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "Reader.hpp"
#include "Writer.hpp"

//Algorithms
#include "AStar.hpp"
#include "Backtracking.hpp"
#include "BreadthFirstSearch.hpp"
#include "DepthFirstSearch.hpp"
#include "GreedySearch.hpp"
#include "Irrevocable.hpp"
#include "OrderedSearch.hpp"

bool debug = false, dev = true;
string inputFolder;
int * A;
vector<SearchAlgorithm*> algorithms;
string instance_type;

static void usage(){
    cout << "Usage:\n" <<
    "    ./Trabalho IA [options] [algorithm] \n\n" <<
    "Options:\n" <<
    "    -h              Show this help\n" <<
    "    -i              Input folder\n" <<
    "    [--debug]       Print Shuffled Vector before the sorted one\n" <<
    "Algorithm:\n" <<
    "    irrevocable     Irrevocable\n" <<
    "    backtracking    Backtracking\n" <<
    "    bfs             Breadth First search\n" <<
    "    dfs             Depth First search\n" <<
    "    ordered         Ordered search\n" <<
    "    greedy          Greedy search\n" <<
    "    a*              A*\n" <<
    "    ida*            IDA*\n" <<
    "    all             All algorithms\n";
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
        } else if (!strcmp(argv[argInd], "--debug")) {
            debug = true;
        }
    }
    
    if(!strcmp (argv[argInd], "all")) {
        algorithms.push_back(new Irrevocable());
        algorithms.push_back(new Backtracking());
        algorithms.push_back(new BreadthFirstSearch());
        algorithms.push_back(new DepthFirstSearch());
        algorithms.push_back(new OrderedSearch());
        algorithms.push_back(new GreedySearch());
        algorithms.push_back(new AStar());
//        algorithms.push_back(new AStar());
    } else {
        if(!strcmp (argv[argInd], "irrevocable")) {
            algorithms.push_back(new Irrevocable());
            argInd++;
        }
        if(!strcmp (argv[argInd], "backtracking")) {
            algorithms.push_back(new Backtracking());
            argInd++;
        }
        if(!strcmp (argv[argInd], "bfs")) {
            algorithms.push_back(new BreadthFirstSearch());
            argInd++;
        }
        if(!strcmp (argv[argInd], "dfs")) {
            algorithms.push_back(new DepthFirstSearch());
            argInd++;
        }
        if(!strcmp (argv[argInd], "ordered")) {
            algorithms.push_back(new OrderedSearch());
            argInd++;
        }
        if(!strcmp (argv[argInd], "greedy")) {
            algorithms.push_back(new GreedySearch());
            argInd++;
        }
        if(!strcmp (argv[argInd], "a*")) {
            algorithms.push_back(new AStar());
            argInd++;
        }
        if(!strcmp (argv[argInd], "ida*")) {
//            algorithms.push_back(new AStar());
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
    
    if(dev){
        inputFolder = "/Users/yanmendes/Documents/Faculdades/Ufjf/Inteligência\ Artificial/Trabalho\ IA/instances";
        algorithms.push_back(new Irrevocable());
        algorithms.push_back(new Backtracking());
        algorithms.push_back(new BreadthFirstSearch());
        algorithms.push_back(new DepthFirstSearch());
        algorithms.push_back(new OrderedSearch());
        algorithms.push_back(new GreedySearch());
        algorithms.push_back(new AStar());
    } else if((errors = processArgs(argc, argv)))
        return errors;
    
    cout << "- - - - - - Processing the input - - - - - - " << endl;
    vector<Maze*> mazes = (new Reader())->parseInputFolder(inputFolder);
    cout << "- - - - - - Done processing the input - - - - - - " << endl;
    
    for(vector<SearchAlgorithm*>::iterator algorithm = algorithms.begin(); algorithm != algorithms.end(); ++algorithm){
        cout << "Selected Algorithm: " << (*algorithm)->getName() << endl;
        
        for(Maze * m : mazes){
            clock_t before_search = clock();
            (*algorithm)->search(m);
            clock_t after_search  = clock();
            (new Writer(m->getFileName(), (*algorithm)->getName()))->writeResults(after_search - before_search, m, (*algorithm)->getTree());
            
            m->clear();
        }
    }
    
    string currentTimeStamp = (new Helper())->getCurrentTimeStamp();
    Writer::writeStatistcs(inputFolder + "/statistics.csv");
    
    return 0;
}
