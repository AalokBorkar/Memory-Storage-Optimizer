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