# Instructions on how to compile our project6 openGL program

1. Ensure that you have an instance of a Linux terminal.
2. Make sure that the our project program is downloaded in the currently directory. It is a glut file, so there is only one file necessary to run our scene. (this would be our project c++ file, ending in .cpp) You can check this by writing the command "ls", and this can be verified if the file is shown within the current directory.
3. Run the follwoing command to compile our scene -> 

For Triangles:
``` bash
g++ CheckeredTriangles.cpp -o <example> -lglut -lGL -lGLU
````

For Cubes:
``` bash
g++ ColorCubeFlyBy.cpp -o <example> -lglut -lGL -lGLU
````

4. Next, run the command "./example" to run the scene. A window should pop up with a 3D represenatation of our scene. 
```bash
./<example>
```
5. Use the function "Ctrl + C" to exit the glut window. 

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
 
and it will run the program for you 
Use the function "Ctrl + C" to exit the glut window. 


