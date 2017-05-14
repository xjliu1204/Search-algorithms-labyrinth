//
//  Room.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 27/04/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef Room_hpp
#define Room_hpp

#include "Helper.hpp"

using namespace std;

class Room{
private:
    bool visited;
    long long int id;
    char visitedByOp;
    long long int heuristicValue;
    
    Room * left;
    Room * bottom;
    Room * right;
    Room * top;
public:
    Room(long long int id);
    long long int getId() {return this->id;};
    bool wasVisited() {return this->visited;};
    void addDoor(Room * room, char direction);
    void visit(char visitedByOp) {this->visited = true; this->visitedByOp = visitedByOp;};
    Room * getRoom(char direction);
    char getVisitedByOp() {return this->visitedByOp;};
};

#endif /* Node_hpp */
