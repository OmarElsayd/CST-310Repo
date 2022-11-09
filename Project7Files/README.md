# Instructions on how to compile our project7 openGL program

Ensure that you have an instance of a Linux terminal.
Make sure that the our project program is downloaded in the currently directory. It is a glut file, so there is only one file necessary to run our scene. (this would be our project c++ file, ending in .cpp) You can check this by writing the command "ls", and this can be verified if the file is shown within the current directory.
Run the follwoing command to compile our scene -> 

For Triangles:
```bash
g++ CheckeredTriangles.cpp -o <example> -lglut -lGL -lGLU
````

For Cubes:
```bash
g++ ColorCubeFlyby.cpp -o <example> -lglut -lGL -lGLU
````

Next, run the command "./example" to run the scene. A window should pop up with a 3D represenatation of our scene. 
```bash
./<example>
```
Use the function "Ctrl + C" to exit the glut window. 

## Or you can use Makefile
We already implemented a makefile that has the following commands

Just type in the terminal 
Triangle :
```bash
    make Triangle
```

Cubes :
```bash
    make Cube
```
### If you recive a message says file is up to date, please use the make clean to clean the files
To clean:
```bash
    make clean
```
 
and it will run the program for you 
Use the function "Ctrl + C" to exit the glut window. 
