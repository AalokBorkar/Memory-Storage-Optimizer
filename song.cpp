#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>     
#include <time.h>      
#include <ctime>
#include <string>
#include "song.h"

using namespace std;

Song::Song(string name, int priority, int size){
	this->name = name; //just havin fun with it, carvin'
	this->priority = priority;
	this->size = size;
}

string Song::get_name() const{
	return name;
}
void Song::set_name(string n){
	name = n;
}
int Song::get_priority () const{
	return priority;
}
void Song::inc_priority(int p){
	priority -= p;
}
void Song::dec_priority(int p){
	priority += p;
}
int Song::get_size () const{
	return size;
}
void Song::set_size(int ss){
	size = ss;
}
