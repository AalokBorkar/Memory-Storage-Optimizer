#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>     
#include <time.h>      
#include <ctime>
#include <string>

using namespace std;

#define TEST_DATA_SIZE	7
#define DAYS			20

struct info{
	string name;
	int priority;
	int song_size;
};

class Song {
private:
	string name;
	int priority;
	int size;
	
public:
	Song(string name, int priority, int size){
		this->name = name; //just havin fun with it, carvin'
		this->priority = priority;
		this->size = size;
	}

	string get_name() const{
		return name;
	}
	void set_name(string n){
		name = n;
	}
	int get_priority () const{
		return priority;
	}
	void inc_priority(int p){
		priority -= p;
	}
	void dec_priority(int p){
		priority += p;
	}
	int get_size () const{
		return size;
	}
	void set_size(int ss){
		size = ss;
	}
};

	bool compare(const Song &l, const Song &r){ //Ascendingorder (easier for pop_back)
		return !(l.get_priority() > r.get_priority());	
	}
class Library {
private:
	vector<Song> songs;
	int total_bytes;
	int desired_size;
public:
	Library(){
		desired_size = 15000; //Recommended size cap
		total_bytes = 0;
	}

	Library(int ds){ //constructor to init desired_size
		desired_size = ds;
		total_bytes = 0;
	}

	void initialize_optimizer(){
		if((total_bytes-desired_size) > 0){
			sort(songs.begin(), songs.end(), compare);
			remove_songs(total_bytes-desired_size);
		}
	}

	int get_total_bytes(){
		return total_bytes;
	}

	void set_total_bytes(int tb){
		total_bytes = tb;
	}

	int get_desired_size(){
		return desired_size;
	}

	vector<Song>& get_songs(){
		return songs;
	}

	void remove_songs(int memory_to_free){ //expects a safe amount of memory to delete (must go through optimized_add_songs first)
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

	int optimized_add_song(Song s){
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

	void print_lib(){
		sort(songs.begin(), songs.end(), compare);
		cout<<"--------------------------"<<endl;
		for(int i = 0; i < songs.size(); ++i){
			cout<< songs[i].get_name() << " | p: " << songs[i].get_priority() << " | s: "<< songs[i].get_size() <<endl; 
		}
		cout<<"--------------------------"<<endl;
		cout<<"\n";
	}
};

string generate_random_song_name(){
	int length = (rand() % 9) + 2;

    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',  
                          'o', 'p', 'q', 'r', 's', 't', 'u', 
                          'v', 'w', 'x', 'y', 'z' }; 
  
    string res = ""; 
    for (int i = 0; i < length; i++)  
        res = res + alphabet[rand() % 26]; 
      
    return res; 
} 

void decrease_library_priority(Library &l){
	for(int i =0; i<l.get_songs().size(); ++i){
		l.get_songs()[(rand() % l.get_songs().size())].dec_priority(10);
	}
}

int main(){
	//init randomness
	srand (time(NULL));
	unsigned cap;
	cout<<"Enter desired memory capacity: ";
	cin>>cap;
	//actual songs
	Library l(cap); //desired cap of 10,000
	//init with data: will change to file IO later

	l.initialize_optimizer();
	//////////////////////////////////////////////////////////////////////////////////
	//test songs is initialized...
	//////////////////////////////////////////////////////////////////////////////////

	//Simulation Test:

	int adding, num_songs_to_add, number_of_listens, song_index;
	for(int i =0; i< DAYS; ++i){ //simulate DAYS days
		//--visuals
		cout<<"  --- DAY "<<i+1<<" ---"<<endl;

		//---ADDING NEW SONGS---
		//are we adding songs today?
		adding = rand() % 4; // 0-3 ~ 25%

		if(!adding){ //if its 0 - we are adding songs today:
			//how many are we adding?:
			num_songs_to_add = (rand() % 9) +1; // 1-9
			for(int i =0; i< num_songs_to_add; ++i){
				//add a song with randomly generated characteristics
				if(!(l.optimized_add_song(Song(generate_random_song_name(),
					0, //highest possible priority, decays over time (DAYS)
					((rand() % 300) + 80) // memory size: random, but at least 20...
				))))
				{//add success
					cout<<"ADDED SONG: "<<l.get_songs()[l.get_songs().size()-1].get_name()<<endl; //latest puish_back's name
				}
				else{//returned a 1, couldnt add song
					cout<<"FAILED TO ADD SONG"<<endl;
				}
				
			} //added all of the songs
		}
		//---LISTENING TO SONGS---
		//how many songs are we gonna listen to?
		if(l.get_songs().size()){ //if we actually have songs (cant % by 0)
			number_of_listens = (rand() % 5) +2;
			for(int i =0; i<number_of_listens; ++i){
				//now which song are we listening to?
				song_index = (rand() % l.get_songs().size());

				cout<<"LISTENING TO: "<<l.get_songs()[song_index].get_name()<<endl;

				if(!(l.get_songs()[song_index].get_priority())){ //if the songs priority is 0 (special case) 
					//only increment by 10 so that it stays at 0 when the widespread decreasing takes place
					l.get_songs()[song_index].inc_priority(10);
				} 
				else{ //increment this songs priority by 20
					l.get_songs()[song_index].inc_priority(20);
				}
			}

			//decrease_library_priority(l); //need to decrement all the rest by 10 because
										  //0 is highest, and if we dont, every song
										  //will eventually reach 0...
		}

		cout<<"LIBRARY AT THE END OF TODAY"<<endl;
		//---DAY SUMMARY---
		l.print_lib();

		cout<<"CURRENT BYTES USED: "<<l.get_total_bytes()<<"/"<<l.get_desired_size()<<endl;
		cout<<"\n";
	}

}