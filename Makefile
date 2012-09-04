# To compile, run 'make' in the same directory as this file

############################
# Settings for the library #
############################

# Needed at least for math.ut.ee server
CXX = g++

# Compiler flags (-Wall shows all warnings when compiling, always use this!)
# -Idir specifies, that there are includes in the 'dir' directory
LIB_CPPFLAGS = -Wall -Iinclude

# List of objects for the library
LIBOBJS = obj/functions.o obj/vector2.o

# Name of the library
LIBRARY = lib/libneljas.a

################################
# Settings for the testing app #
################################

# Compiler flags for the pp
APP_CPPFLAGS = -Wall -Iinclude

# Linker flags (order the compiler to link with our library)
LFLAGS = -Llib -lneljas

# The object for the testing app
TESTOBJS = obj/neljastest.o

# The name of the testing app
TESTAPP = bin/neljastest

# This is the first target. It will be built when you run 'make' or 'make all'
all: $(LIBRARY)

# Create the library by using 'ar'
$(LIBRARY) : $(LIBOBJS)
	ar cr $(LIBRARY) $(LIBOBJS)

# Compile each source file of the librar
obj/functions.o: src/Functions.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/Functions.cpp -o obj/functions.o

obj/vector2.o: src/Vector2.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/Vector2.cpp -o obj/vector2.o

# Rule for linking the test app with our library
$(TESTAPP): $(TESTOBJS)
	$(CXX) $(TESTOBJS) -o $(TESTAPP) $(LFLAGS) 

# Compile each source file of the library
obj/neljastest.o: tests/neljastest.cpp
	$(CXX) $(APP_CPPFLAGS) -c tests/neljastest.cpp -o obj/neljastest.o 

test: all $(TESTAPP)

doc:
	doxygen

clean:
	rm -f $(LIBOBJS)
	rm -f $(TESTOBJS)
	rm -f $(LIBRARY)
	rm -f $(TESTAPP)
	rm -rf docs/html
