/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.hpp
 * Author: Cameron
 *
 * Created on May 12, 2018, 8:28 PM
 */

#ifndef MAP_HPP
#define MAP_HPP

#include "Country.hpp"
#include "Province.hpp"

class Map {
public:
    Map();
    ~Map();
    
    // Creates the map
    bool init();
    
private:
    
    int heigth, width, num_countries, num_provinces;
    
};

#endif /* MAP_HPP */

