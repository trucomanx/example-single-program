# README

Project template of a program in C++ and CMAKE.

## I) INSTALL STEPS

### Step 1: Create a working directory

	mkdir build
	cd build

### Step 2: Configure de project
Without define the install path, by default the install path is  '/usr/local'

	cmake ..

Or configure defining the install path in '/my/installing/path'

	cmake -DCMAKE_INSTALL_PREFIX=/my/installing/path  ..

If necessary, to add a specific path to the headers and libraries

	cmake .. -DADD_INCLUDE_DIRECTORY="/some/directory/include" -DADD_LIB_DIRECTORY="-L/some/directory/lib"

### Step 3: Compile the library and install
	
#### In GNU/Linux

	make
	make install

#### In WINDOWS

	cmake --build . --config Release
	cmake --build . --config Release --target INSTALL


## II) DEBIAN PACKAGE BUILDING
Before made any of these steps made the steps 1 and 2, 

### Step X: Creating a source *.tar.gz package
Generate a PACKAGE-VERSION.tar.gz file

	make package_source

If necessary you can generate a detached GPG binary signature for the file PACKAGE-VERSION.tar.gz
	
	gpg -b --use-agent PACKAGE-VERSION.tar.gz
	
To verify it:

	gpg --verify PACKAGE-VERSION.tar.gz.sig
### Step Y: Creating a binary *.deb package
Generate a *.deb file, but require that -DCMAKE_INSTALL_PREFIX=/usr (Step 2)

	make package
	
	
### Step Z: Creating a binary windows *.exe package

Build release version from the command line

	cmake --build . --config Release


Build setup package from the command line

	
	cmake --build . --config Release --target INSTALL

