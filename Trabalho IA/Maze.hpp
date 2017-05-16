//
//  Maze.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 27/04/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef Maze_hpp
#define Maze_hpp

#include <stdio.h>
#include "Helper.hpp"
#include "Room.hpp"

class Maze{
private:
    //Identifiers
    string file;
    long long int rooms;
    
    Room * origin;
    Room * destination;
public:
    Maze(string file, long long int rooms, Room * origin, Room * destination);
    void addDoor(long long int origin, long long int destination, char direction);
    Room * getOrigin() {return this->origin;};
    Room * getDestination() {return this->destination;};
    Room * getRoom(long long int id);
    void clear();
    
    //Identifiers
    string getFileName() {return file;};
    long long int getRooms(){return this->rooms;};
    unsigned long long int getNumberOfDoors();
};

#endif /* Maze_hpp */
