//
//  Maze.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 27/04/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "Maze.hpp"

using namespace std;

Maze::Maze(string file, string instanceIdentifier, Room * origin, Room * destination){
    this->file = file;
    this->instanceIdentifier = instanceIdentifier;
    this->origin = origin;
    this->destination = destination;
}

void Maze::addDoor(int origin, int destination, char direction){
    Room * o = getRoom(origin);
    Room * d = getRoom(destination);
    
    o->addDoor(d != NULL ? d : (new Room(destination)), direction);
}

Room * Maze::getRoom(int id){
    queue<Room*> queue;
    queue.push(this->origin);
    Room * r;
    
    while(!queue.empty()){
        r = queue.front();
        queue.pop();
        
        if(r == NULL)
            continue;
        
        if(r->getId() == id)
            return r;
        
        queue.push(r->getRoom('L'));
        queue.push(r->getRoom('B'));
        queue.push(r->getRoom('R'));
        queue.push(r->getRoom('T'));
    }
    
    return NULL;
}

void Maze::getNumberOfRoomsAndDoors(unsigned long int *rooms, unsigned long int *doors){
    queue<Room*> queue;
    queue.push(this->origin);
    Room * r;
    
    while(!queue.empty()){
        r = queue.front();
        queue.pop();
        
        if(r == NULL)
            continue;
        
        *doors += 1;
        
        if(!r->wasVisited()){
            *rooms += 1;
            r->visit('L');
        }
        
        queue.push(r->getRoom('L'));
        queue.push(r->getRoom('B'));
        queue.push(r->getRoom('R'));
        queue.push(r->getRoom('T'));
    }
}
