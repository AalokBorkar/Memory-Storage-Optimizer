#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>     
#include <time.h>      
#include <ctime>
#include <string>
#include "song.h"
#include "library.h"

using namespace std;

bool compare(const Song &l, const Song &r){ //Ascendingorder (easier for pop_back)
	return !(l.get_priority() > r.get_priority());	
}

Library::Library(){
	desired_size = 15000; //Recommended size cap
	total_bytes = 0;
}

Library::Library(int ds){ //constructor to init desired_size
	desired_size = ds;
	total_bytes = 0;
}

void Library::initialize_optimizer(){
	if((total_bytes-desired_size) > 0){
		sort(songs.begin(), songs.end(), compare);
		remove_songs(total_bytes-desired_size);
	}
}

int Library::get_total_bytes(){
	return total_bytes;
}

void Library::set_total_bytes(int tb){
	total_bytes = tb;
}

int Library::get_desired_size(){
	return desired_size;
}

vector<Song>& Library::get_songs(){
	return songs;
}

void Library::remove_songs(int memory_to_free){ //expects a safe amount of memory to delete (must go through optimized_add_songs first)
	//if we have to clear a larger amount than what we have (still within bounds of desired)
	cout<<"FREEING: "<<memory_to_free<<" 'BYTES' OF MUSIC"<<endl;
	if(memory_to_free >= total_bytes){
		songs.clear();
		return;
	}
	//if not, we have to manually go through and delete songs:
	int accumulated_bytes = 0;
	while(accumulated_bytes < memory_to_free){
		//delete back of vector
		accumulated_bytes += songs[songs.size()-1].get_size();
		total_bytes-= songs[songs.size()-1].get_size();;
		songs.pop_back(); //deleting starting from the back (least played songs)

	}
	//at this point the library has enough space to accomodate the new song
}

int Library::optimized_add_song(Song s){
	sort(songs.begin(), songs.end(), compare);
	if(s.get_size() > desired_size){ //gaurenteed overflow...
		return 1;
	}
	//appropriate size song to be added
	if((s.get_size()-(desired_size-total_bytes)) > 0){ //assess potential overflow
		remove_songs((s.get_size()-(desired_size-total_bytes))); //if we have an overflow
	}
	//now that we've freed up enough space
	songs.push_back(s); //add the song and update the total_bytes
	total_bytes+= s.get_size();
	return 0;
}

void Library::print_lib(){
	sort(songs.begin(), songs.end(), compare);
	cout<<"--------------------------"<<endl;
	for(int i = 0; i < songs.size(); ++i){
		cout<< songs[i].get_name() << " | p: " << songs[i].get_priority() << " | s: "<< songs[i].get_size() <<endl; 
	}
	cout<<"--------------------------"<<endl;
	cout<<"\n";
}