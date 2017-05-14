//
//  Maze.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 27/04/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "Maze.hpp"

using namespace std;

Maze::Maze(string file, long long int rooms, Room * origin, Room * destination){
    this->file = file;
    this->rooms = rooms;
    this->origin = origin;
    this->destination = destination;
}

void Maze::addDoor(long long int origin, long long int destination, char direction){
    Room * o = getRoom(origin);
    Room * d = getRoom(destination);
    
    o->addDoor(d != NULL ? d : (new Room(destination)), direction);
}

Room * Maze::getRoom(long long int id){
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

unsigned long long int Maze::getNumberOfDoors(){
    unsigned long long int doors = 0;
    queue<Room*> queue;
    queue.push(this->origin);
    Room * r;
    
    while(!queue.empty()){
        r = queue.front();
        queue.pop();
        
        if(r == NULL)
            continue;
        
        ++doors;
        
        queue.push(r->getRoom('L'));
        queue.push(r->getRoom('B'));
        queue.push(r->getRoom('R'));
        queue.push(r->getRoom('T'));
    }
    
    return doors;
}

