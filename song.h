#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>     
#include <time.h>      
#include <ctime>
#include <string>

using namespace std;

class Song {
private:
	string name;
	int priority;
	int size;
	
public:
	Song(string, int, int);

	string get_name() const;

	void set_name(string);

	int get_priority () const;

	void inc_priority(int);

	void dec_priority(int);

	int get_size () const;

	void set_size(int);
};

#endif