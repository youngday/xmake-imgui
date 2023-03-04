# xmake-example

## local dependent packages
wei get from github and cmake or xmake ,and installed.
* cpplinuxserial
* coost
we add coost as local lib ,libso.a and "include/co" header files.which is compiled by coost xmake project.
* cpr
* matplotplusplus
like matplotlib of python,data analyzer . 
* rapidcsv
read datas from csv file,and plot them out. 
* imgui glfw opengl3
⚠️ need add 
```cpp
#undef GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h> // Will drag system OpenGL headers
```
example_glfw_opengl3

reference:https://github.com/xmake-examples/imgui-scaffold

* imgui sdl2 vulkan

need install vulkan

```sh
sudo apt install vulkan-utils
```

## example

lock-free concurrentqueue, udp ,tcp ,cppzmq,loguru matplot,csv
🐞
