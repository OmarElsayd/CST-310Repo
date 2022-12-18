# Instructions on how to compile our project 10 openGL program

**NOTE to Professor Citro: We were unsuccessful in being able to use the cube and cylinder shader, but were successful in the sphere shader. We spent countless hours attempting to utilize the cubemap for the cube, and even using the already provided textures as examples. We were able to modify the checkerboard to red, move the shapes to their original position, and still be able to move around the scene with the necessary functions. We were able to load one texture in but found constant problems when trying to bind the texture to the shape. In our github, you’ll see two separate files, one is the ordinary scenes with the shapes with no textures applied and the other is the scene but only with the sphere texture. We hope that we don’t receive a horrible grade but we understand if we miss points due to not being able to implement the shaders. We feel we weren’t given enough resources for this project. We hope in light of the season and holidays that you are considerate and understanding when grading our project. We still included all of the necessary documentation as well. Thank you for teaching us this semester.


Ensure that you have an instance of a Linux terminal.

Make sure that the our project program is downloaded in the currently directory. To run Project 10 without shaders, download the folder project 10. To run the contents of the program with the attempted shader, download the contents of folder Project10_attempt The main source code file is a glfw file and also utilizes soil, so there are a few files you need to run our scene, hence all vs, frgament, and extra files should be included in your current directory. (this would be our project c++ file, ending in .cpp) You can check this by writing the command "ls", and this can be verified if the file is shown within the current directory.
Run the follwoing command to compile our scene -> 

Project 10 without shaders:
```bash
g++ Project10.cpp -o <example> -lglfw -lGL -lGLEW -lSOIL -lassimp
````
Project 10 with attempted shaders:

```bash
g++ Project10_attempt.cpp -o <example> -lglfw -lGL -lGLEW -lSOIL -lassimp
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
