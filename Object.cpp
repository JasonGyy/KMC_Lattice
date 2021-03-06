// Copyright (c) 2017 Michael C. Heiber
// This source file is part of the KMC_Lattice project, which is subject to the MIT License.
// For more information, see the LICENSE file that accompanies this software.
// The KMC_Lattice project can be found on Github at https://github.com/MikeHeiber/KMC_Lattice

#include "Object.h"

using namespace std;

const string Object::name_base = "Object";

Object::~Object(){
    //dtor
}

Object::Object(){

}

Object::Object(const double time,const int tag_num,const Coords& start_coords){
    time_created = time;
    tag = tag_num;
    coords = start_coords;
    coords_initial = start_coords;
}

double Object::calculateDisplacement() const{
    return sqrt((double)(coords.x+dx-coords_initial.x)*(coords.x+dx-coords_initial.x)+(coords.y+dy-coords_initial.y)*(coords.y+dy-coords_initial.y)+(coords.z+dz-coords_initial.z)*(coords.z+dz-coords_initial.z));
}

Coords Object::getCoords() const{
    return coords;
}

double Object::getCreationTime() const{
    return time_created;
}

list<Event*>::iterator Object::getEventIt() const{
    return event_it;
}

string Object::getName() const{
    return name_base;
}

int Object::getTag() const{
    return tag;
}

void Object::incrementDX(const int num){
    dx += num;
}

void Object::incrementDY(const int num){
    dy += num;
}

void Object::incrementDZ(const int num){
    dz += num;
}

void Object::setCoords(const Coords& input_coords){
    coords = input_coords;
}

void Object::setEventIt(const list<Event*>::iterator input_it){
    event_it = input_it;
}

