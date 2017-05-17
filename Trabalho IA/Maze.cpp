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
    
    this->origin->visit('L');
}

void Maze::addDoor(long long int origin, long long int destination, char direction){
    Room * o = getRoom(origin);
    Room * d = getRoom(destination);
    
    if(o == NULL)
        o = new Room(origin);
    
    if(d == NULL)
        d = new Room(destination);
    
    o->addDoor(d, direction);
}

Room * Maze::getRoom(long long int id){
    vector<long long int> visited;
    queue<Room*> queue;
    queue.push(this->origin);
    Room * r;
    
    while(!queue.empty()){
        r = queue.front();
        queue.pop();
        
        if(r == NULL)
            continue;
        
        else if(r->getId() == id)
            return r;
        
        else if(find(visited.begin(), visited.end(), r->getId()) == visited.end()){
            queue.push(r->getRoom('L'));
            queue.push(r->getRoom('B'));
            queue.push(r->getRoom('R'));
            queue.push(r->getRoom('T'));
            visited.push_back(r->getId());
        }
    }
    
    return NULL;
}

unsigned long long int Maze::getNumberOfDoors(){
    unsigned long long int doors = 0;
    vector<long long int> visited;
    queue<Room*> queue;
    queue.push(this->origin);
    Room * r;
    
    while(!queue.empty()){
        r = queue.front();
        queue.pop();
        
        if(r == NULL)
            continue;
        
        else if(find(visited.begin(), visited.end(), r->getId()) == visited.end()){
            queue.push(r->getRoom('L'));
            queue.push(r->getRoom('B'));
            queue.push(r->getRoom('R'));
            queue.push(r->getRoom('T'));
            visited.push_back(r->getId());
        }
        
        ++doors;
    }
    
    return doors/2;
}

void Maze::clear(){
    vector<long long int> visited;
    queue<Room*> queue;
    queue.push(this->origin);
    Room * r;
    
    while(!queue.empty()){
        r = queue.front();
        queue.pop();
        
        if(r == NULL)
            continue;
        
        else if(find(visited.begin(), visited.end(), r->getId()) == visited.end()){
            r->resetVisit();
            queue.push(r->getRoom('L'));
            queue.push(r->getRoom('B'));
            queue.push(r->getRoom('R'));
            queue.push(r->getRoom('T'));
            visited.push_back(r->getId());
        }
    }
    
    this->origin->visit('L');
}
