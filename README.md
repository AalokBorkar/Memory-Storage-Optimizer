# Memory Storage Optimizer
Software designed to maintain a set memory capacity for a device's file system by intelligently caching and freeing data as it expands.

# Motivation
Throughout the past few months I have noticed my phone's performance drastically decrease as I download more files and data. As I came to this realization it occured to me that there is a huge portion of my device's memory being occupied by content and files that I havent touched in ages. With this in mind I was driven to create a software solution to allow the everyday user to endlessly download new content onto their devices without having to worry about their memory usage or subsequent performance decay.

# Practicality
To assess the real world functionality of Memory Storage Optimizer, I also developed a simulation (included in the software's main file) that simulates a person using the software for a music library (for *X* virtual days), including listening to and adding new randomly generated songs to their memory-capped library.

# Languages && Frameworks
Memory Storage Optimizer is written completely in vanilla *C++14*, with the following additional imported libraries: `<vector>`, `<algorithm>`, and `<time>`.
  
# Running the Software (Linux/Windows/MacOS)
To run the SMO Music Library Simulator: <br> 
1. Compile by entering `g++ optimizer.cpp library.cpp song.cpp -o run` into a command prompt with a C++14 compiler. <br>
2. Run the simulation by entering in `run` into the command prompt. <br>
3. After entering in the desired memory capacity you should see a visual output to `stdout` of the simulation with a daily summary for each of the 20 days it is run for.
<br>

*Part of an example output*:
<br>

![Example Simulation Output](https://github.com/AalokBorkar/Memory-Storage-Optimizer/blob/master/sim.JPG)
<br>
Note: The leftmost text is the name of the simulation-generated song, `p` denotes the priority value of keeping the song (increases to reflect time without interaction | lower => better), while `s`denotes the size (in virtual bytes) of the song file.

© Aalok Borkar
