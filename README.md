There are several methods to compile and run this code: 
1)Opening the executable located in "Homework_Algorithm_Design\cmake-build-debug\Homework_Assignment_Alogithm_Design.exe" by simply navigating to it in File Explorer or by using the Command Prompt.
2)Compiling the code using MinGW compiler(or any other) which has to be installed locally(https://www.mingw-w64.org/downloads/);
  After it is installed, you need to set a System Variable Path to the "bin" folder of MinGW.
  To test whether the installation worked or not open Cmd and type "gcc --version".
  If it worked, navigate to the root folder("Homework_Algorithm_Design") and type "gcc -o main.c lobsters.c datagenerator.c".
3)Using CMake(https://cmake.org/download/)
4)You can create a blank project in any compatible IDE and import the files: main.c, lobsters.c,datagenerator.c,lobsters.h,datagenerator.h

Note: For a better visualization, you can minimize the range of the randomly generated values in datagenerator.c file.
  
  
