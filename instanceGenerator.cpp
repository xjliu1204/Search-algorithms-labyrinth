//
//  instanceGenerator.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 12/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

static void usage(){
    cout << "Usage:\n" <<
    "    ./instanceGenerator [options] [parameters] \n\n" <<
    "Options:\n" <<
    "    -h     Show this help\n" <<
    "Parameters:\n" <<
    "    m      Number of lines\n" <<
    "    n      Number of columns\n" <<
    "    r      Number of rooms\n";
}

long long int m, n, r;

int processArgs(int argc, const char * argv[]){
    if(argc < 3){
        usage();
        return 2;
    }
    
    if (argv[1][0] == '-'){
        usage();
        return 2;
    }
    
    m = atoll(argv[1]);
    n = atoll(argv[2]);
    r = atoll(argv[3]);
    return 0;
}

bool emptyRoom(long long int iterator, long long int room){
    if(r - room + 1 == n * m - iterator)
        return false;
    else
        return rand() % 100 < ((double) r/(m*n)) * 100 - 5;
}

long long int getManhattanDistance(long long int i, long long int j, long long int destination){
    long long int i_dest = destination / n;
    long long int j_dest = destination % n;
    
    return abs(i - i_dest) + abs(j - j_dest);
}

int main(int argc, const char * argv[]) {
    long long int * M = nullptr, room = 1, origin = 0, destination = 0;
    
    stringstream fileString;
    fstream file;
    
    srand(time(NULL));
    
    if(processArgs(argc, argv))
        return 2;
    
    fileString << "instance_" << m << "_" << n << "_" << r << ".in";
    file.open(fileString.str(), fstream::out);
    
    M = new long long int[m * n];
    
    for(unsigned long long int i = 0; i < m * n; ++i){
        if(room > r || emptyRoom(i, room))
            M[i] = 0;
        else {
            if(room == 1)
                origin = i;
            else if(room == r)
                destination = i;
            
            M[i] = room++;
        }
    }
    
    file << m << " " << n << " " << r << " " << M[origin] << " " << M[destination] << "\n";
    
    for(long long int i = 0; i < m; ++i){
        for(long long int j = 0; j < n; ++j){
            file << M[i * n + j] << " ";
        }
        file << "\n";
    }
    
    for(long long int i = 0; i < m; ++i){
        for(long long int j = 0; j < n; ++j){
            if(M[i * n + j])
                file << M[i * n + j] << " " << getManhattanDistance(i, j, destination) << "\n";
        }
    }
    
    file.close();
    
    return 0;
}
