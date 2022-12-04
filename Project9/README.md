# Instructions on how to compile our project9 openGL program

Ensure that you have an instance of a Linux terminal.

Make sure that the our project program is downloaded in the currently directory. You can download the entire project and its file contents by downloading Project9.zip. The main source code file is a glfw file and also utilizes soil, so there are a few files you need to run our scene, hence all vs, frgament, and extra files should be included in your current directory. (this would be our project c++ file, ending in .cpp) You can check this by writing the command "ls", and this can be verified if the file is shown within the current directory.
Run the follwoing command to compile our scene -> 

```bash
g++ Project9.cpp -o <example> -lglfw -lGL -lGLEW -lSOIL -lassimp
````

Next, run the command "./example" to run the scene. A window should pop up with a 3D represenatation of our scene. 
```bash
./<example>
```
Use the function "Ctrl + C" to exit the glut window. 

## Or you can use Makefile
We already implemented a makefile that has the following commands

Just type in the terminal 
```bash
    make 
```
 
and it will run the program for you 
Use the function "Ctrl + C" to exit the glut window. 

