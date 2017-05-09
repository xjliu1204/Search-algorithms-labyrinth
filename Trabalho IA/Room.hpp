//
//  Room.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 27/04/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef Room_hpp
#define Room_hpp

#include <stdio.h>
#include "Helper.hpp"

using namespace std;

class Room{
private:
    bool visited;
    int id;
    char visitedBy;
    
    Room * left;
    Room * bottom;
    Room * right;
    Room * top;
public:
    Room(int id);
    int getId() {return this->id;};
    bool wasVisited() {return this->visited;};
    void addDoor(Room * room, char direction);
    void visit(char visitedBy) {this->visited = true; this->visitedBy = visitedBy;};
    Room * getRoom(char direction);
    char getVisitedBy() {return this->visitedBy;};
};

#endif /* Node_hpp */
