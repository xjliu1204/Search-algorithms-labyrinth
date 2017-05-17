//
//  Result.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 17/05/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef Result_hpp
#define Result_hpp

class Result{
public:
    long long int rooms, doors, treeHeight;
    string instance, algorithm;
    double averageExpandedStates, elapsedTime;
    bool success;
    
    Result(long long int rooms, long long int doors, long long int treeHeight, string instance, string algorithm, double averageExpandedStates, double elapsedTime, bool success){
        this->rooms = rooms;
        this->doors = doors;
        this->treeHeight = treeHeight;
        this->instance = instance;
        this->algorithm = algorithm;
        this->averageExpandedStates = averageExpandedStates;
        this->elapsedTime = elapsedTime;
        this->success = success;
    }
};

#endif /* Result_hpp */
