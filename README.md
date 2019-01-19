# Storage Memory Optimizer
Software designed to maintain a set memory capacity for a device's file system by intelligently caching and freeing data as it expands.

# Motivation
Throughout the past few months I have noticed my phone's performance drastically decrease as I download more files and data. As I came to this realization it occured to me that there is a huge portion of my device's memory being occupied by content and files that I havent touched in ages. With this in mind I was driven to create a software solution to allow the everyday user to endlessly download new content onto their devices without having to worry about their memory usage or subsequent performance decay.

# Practicality
To assess the real world functionality of Storage Memory Optimizer, I also developed a simulation (included in the software's main file) that simulates a person using the software for a music library (for *X* virtual days), including listening to and adding new randomly generated songs to their memory-capped library.

# Frameworks
Storage Memory Optimizer is written completely in vanilla C++14, with the following additional imported libraries: <vector>, <algorithm>, <time>.
  
# Running the Software (Linux/Windows/MacOS)
To run the SMO Music Library Simulator 
Compile by entering `g++ optimizer.cpp library.cpp song.cpp -o run` into a command prompt with a C++14 compiler.
Then run the simulation by entering in `run` into the command prompt.
After entering in the desired memory capacity you should see a visual output to `stdout` of the simulation with a daily summary for each of the 20 days it is run for:

![Example Simulation Output](https://github.com/AalokBorkar/Storage-Memory-Optimizer/blob/master/sim.JPG)

# Languages Used
*C++14

© Aalok Borkar
