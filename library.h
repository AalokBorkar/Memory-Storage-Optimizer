#ifndef LIBRARY_H
#define LIBRARY_H

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

class Library {
private:
	vector<Song> songs;
	int total_bytes;
	int desired_size;
public:
	Library();

	Library(int);

	void initialize_optimizer();

	int get_total_bytes();

	void set_total_bytes(int);

	int get_desired_size();

	vector<Song>& get_songs();

	void remove_songs(int);

	int optimized_add_song(Song);

	void print_lib();
};

#endif