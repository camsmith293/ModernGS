/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "World.hpp"

World::World() {
    
}

bool World::init() {
    return true;
}

bool World::addObject(Object *object) {
    // Add the object to the buffer
    this->objects.push_back(object);
    this->obj_count++;

    return true;
    
}

bool World::addTestObjects() {
    Square *square= new Square(SCREEN_WIDTH * -1.f / 2.f, SCREEN_WIDTH * 1.f / 2.f, 100.f, 100.f);
    
    bool success = this->addObject(square);
    return success;
}

// Return the objects list
ObjectList World::getObjects() {
    return this->objects;
}

void World::free() {
    
    // Free the items of the list
    for(auto&& object : this->objects) {
        delete object;
    }
}