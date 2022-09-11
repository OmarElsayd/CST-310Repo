This project has 3 parts, every part is a separate program.

First program is a test of OpenGL library. That file called testOpenGl.cpp

to run that test follow the steps below:
    - Make sure you are running Linux on either a virtual machine or a local server
      with remote desktop connection 
    - Make sure that you have GCC installed on your Linux machine. 
      (Run gcc --version or g++ --version)
    - Make sure to install OpenGL on your machine:
        - sudo apt-get update
        - sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
    
    Now you can start running the OpenGl program:
        - g++ TestOpenGl.cpp -o TestOpenGl -lglut -lGLU -lGL
        - ./TestOpenGl
    
After successful run for the test program, we are now ready to test 2D program

### For explanation regarding design, implementation, algoratims and approtch,
 please check out the documationtion file###

To run the 2D test, please follow these:
    - Make sure that you have done the testOpenGl steps till installing OpenGl on 
      you Linux machine
    - Then run these two commonds:
        - g++ main2D.cpp -o 2DTest -lglut -lGLU -lGL
        - ./2DTest

To run the 3D test, please follow these:
    - Make sure that you have done the testOpenGl steps till installing OpenGl on 
      you Linux machine
    - Then run these two commonds:
        - g++ main3D.cpp -o 3DTest -lglut -lGLU -lGL
        - ./3DTest

    
    

    
