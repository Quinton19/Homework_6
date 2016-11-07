CXX = g++
CXXOPTS = -std=c++11

all: executable
rebuild: clean all

debug: CXXFLAGS += -g
debug: executable

executable: robot_part.o head.o arm.o locomotor.o torso.o battery.o main.o helper_functions.o robot_model.o shop.o controller.o
		$(CXX) $(CXXOPTS) -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/freetype2 -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -g -O2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT -std=c++11 -o 'rrsm' 'main.o' 'Robot_Part.o' 'Head.o' 'Arm.o' 'Locomotor.o' 'Torso.o' 'Battery.o' 'helper_functions.o' 'Robot_Model.o' 'Shop.o' 'Controller.o' -Wl,-Bsymbolic-functions -lfltk -lX11

# main: robot_part.o controller.o view.o head.o arm.o locomotor.o torso.o battery.o main.o helper_functions.o robot_model.o shop.o
#	g++ robot_part.o controller.o view.o head.o arm.o locomotor.o torso.o battery.o main.o helper_functions.o robot_model.o shop.o

test: robot_part.o head.o arm.o locomotor.o torso.o battery.o helper_functions.o test.o robot_model.o shop.o
	g++ robot_part.o head.o arm.o locomotor.o torso.o battery.o helper_functions.o test.o robot_model.o shop.o

main.o: main.cpp Controller.h
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) main.cpp
test.o: test.cpp
	g++ -std=c++11 -c test.cpp
view.o: View.cpp Robot_Part.h View.h
	g++ -std=c++11 -c View.cpp
controller.o: Controller.cpp Controller.h Head.h Locomotor.h Torso.h Battery.h Arm.h View.h
	g++ $(fltk-config --cxxflags) -std=c++11 -c Controller.cpp
robot_part.o: Robot_Part.cpp Robot_Part.h  helper_functions.h
	g++ -std=c++11 -c Robot_Part.cpp
head.o: Head.cpp Head.h Robot_Part.h helper_functions.h
	g++ -std=c++11 -c Head.cpp
arm.o: Arm.cpp Arm.h Robot_Part.h helper_functions.h
	g++ -std=c++11 -c Arm.cpp
locomotor.o: Locomotor.cpp Locomotor.h Robot_Part.h helper_functions.h
	g++ -std=c++11 -c Locomotor.cpp
torso.o: Torso.cpp Torso.h Robot_Part.h helper_functions.h
	g++ -std=c++11 -c Torso.cpp
battery.o: Battery.cpp Battery.h Robot_Part.h helper_functions.h
	g++ -std=c++11 -c Battery.cpp
helper_functions.o: helper_functions.cpp helper_functions.h
	g++ -std=c++11 -c helper_functions.cpp
robot_model.o: Robot_Model.cpp Robot_Model.h Robot_Part.h Arm.h Torso.h Locomotor.h Head.h Battery.h helper_functions.h
	g++ -std=c++11 -c Robot_Model.cpp
shop.o: Shop.cpp Shop.h Robot_Model.h Robot_Part.h Arm.h Torso.h Locomotor.h Head.h Battery.h helper_functions.h
	g++ -std=c++11 -c Shop.cpp


clean:
	rm -f *.o rrsm
