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
    string file, instanceIdentifier;
    
    Room * origin;
    Room * destination;
    
    Room * getRoom(int id);
public:
    Maze(string file, string instanceIdentifier, Room * origin, Room * destination);
    void addDoor(int origin, int destination, char direction);
    Room * getOrigin() {return this->origin;};
    Room * getDestination() {return this->destination;};
    
    //Identifiers
    string getFileName() {return file;};
    string getInstanceIdentifier(){return this->instanceIdentifier;};
    void getNumberOfRoomsAndDoors(unsigned long int *rooms, unsigned long int *doors);
};

#endif /* Maze_hpp */
