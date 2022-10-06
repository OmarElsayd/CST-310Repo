# Instructions on how to compile our glut program

1. Ensure that you have an instance of a Linux terminal.
2. Make sure that the our project program is downloaded in the currently directory. It is a glut file, so there is only one file necessary to run our scene. (this would be our project c++ file, ending in .cpp) You can check this by writing the command "ls", and this can be verified if the file is shown within the current directory.
3. Run the follwoing command to compile our scene -> 
``` bash
g++ Project4.cpp -o <example> -lGL -lGLU -lglut
````
4. Next, run the command "./example" to run the scene. A window should pop up with a 3D represenatation of our scene. 
5. Use the function "Ctrl + C" to exit the glut window. 
