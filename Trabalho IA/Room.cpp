//
//  Room.cpp
//  Trabalho IA
//
//  Created by Yan Mendes on 27/04/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#include "Room.hpp"

Room::Room(long long int id) {
    this->id = id;
    this->visited = false;
    this->left = this->bottom = this->right = this->top = NULL;
    this->visitedByOp = NULL;
}

void Room::addDoor(Room * room, char direction){
    switch (direction) {
        case 'L':
            this->left = room;
            room->right = this;
            break;
        case 'B':
            this->bottom = room;
            room->top = this;
            break;
        case 'R':
            this->right = room;
            room->left = this;
            break;
        case 'T':
            this->top = room;
            room->bottom = this;
            break;
    }
}

Room * Room::getRoom(char direction){
    switch (direction) {
        case 'L':
            return this->left;
            break;
        case 'B':
            return this->bottom;
            break;
        case 'R':
            return this->right;
            break;
        case 'T':
            return this->top;
            break;
        default:
            return NULL;
    }
}
