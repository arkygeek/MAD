Project Authors:

Jason Jorgenson



Build Notes (QMAKE):
-----------------------------------------------
export QTDIR=path/to/your/Qt/directory (ie /usr/local/Qt/Qt-4.2.2/ )
export PATH=$QTDIR/bin/:$PATH
qmake
make


To Run:

macsur-adapter-release/bin/macsur-adapter-release

Build Notes (CMAKE)
-----------------------------------------------
mkdir build
cd build
cmake -D CMAKE_INSTALL_PREFIX=/home/yourusername/apps/ ..
make
make install


Making a kdevelop (Version 3)  project with cmake:
-----------------------------------------------
mkdir build
cmake -G KDevelop3 -D CMAKE_INSTALL_PREFIX=/home/yourusername/apps/..

Then open the generated project using kdevelop
