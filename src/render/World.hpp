/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   World.hpp
 * Author: cameron
 *
 * Created on August 23, 2018, 5:05 PM
 */

#ifndef WORLD_HPP
#define WORLD_HPP

#include "../global.hpp"
#include "object/Include_Objects.hpp"
#include <list>

typedef std::list<Object*> ObjectList;

class World {
public:
    World();
    
    // Initialize the world
    bool init();
    
    // Deallocate the internals
    void free();
    
    // Add an test objects to the world
    bool addTestObjects();
    
    // Add an object to the world
    bool addObject(Object *object);
    
    // Return the objects list
    ObjectList getObjects();
    
private:
    
    // The maximum amount of vertices the buffer can hold
    const GLuint MAX_VERTICES = 80000;
    
    // The amount of objects currently in the world
    GLuint obj_count = 0;
    
    // The objects in the world
    ObjectList objects;
    
};
#endif /* WORLD_HPP */

