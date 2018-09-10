/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vertex2D.hpp
 * Author: cameron
 *
 * Created on September 6, 2018, 8:57 PM
 */

#ifndef VERTEX2D_HPP
#define VERTEX2D_HPP

#include "Position3D.hpp"
#include "texture/TexCoord.hpp"

struct Vertex2D {
    Position3D pos;
    TexCoord texCoord;
};

#endif /* VERTEX2D_HPP */

