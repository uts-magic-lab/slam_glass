### You should not need to change anything below.
LINUX=1
MACOSX=0

# Compilers
CC=gcc
CXX=g++

# Paths
MAPPING_ROOT=/home/jack/ros_ws/slam_glass/gmapping_glass/gmapping_export
LIBDIR=/home/jack/ros_ws/slam_glass/gmapping_glass/gmapping_export/lib
BINDIR=/home/jack/ros_ws/slam_glass/gmapping_glass/gmapping_export/bin

# Build tools
PRETTY=/home/jack/ros_ws/slam_glass/gmapping_glass/gmapping_export/build_tools/pretty_compiler
MESSAGE=/home/jack/ros_ws/slam_glass/gmapping_glass/gmapping_export/build_tools/message
TESTLIB=/home/jack/ros_ws/slam_glass/gmapping_glass/gmapping_export/build_tools/testlib

# QT support
MOC=moc-qt3
QT_LIB=-lqt-mt
QT_INCLUDE=-I/usr/include/qt3

# ARIA support
ARIA_LIB=
ARIA_INCLUDE=


# # KDE support
# KDE_LIB=
# KDE_INCLUDE=
# UIC=

# Generic makefiles
MAKEFILE_GENERIC=/home/jack/ros_ws/slam_glass/gmapping_glass/gmapping_export/build_tools/Makefile.generic-shared-object
MAKEFILE_APP=/home/jack/ros_ws/slam_glass/gmapping_glass/gmapping_export/build_tools/Makefile.app
MAKEFILE_SUBDIRS=/home/jack/ros_ws/slam_glass/gmapping_glass/gmapping_export/build_tools/Makefile.subdirs


# Flags
CPPFLAGS+=-DLINUX -I/home/jack/ros_ws/slam_glass/gmapping_glass/gmapping_export 
CXXFLAGS+=
LDFLAGS+= -Xlinker -rpath /home/jack/ros_ws/slam_glass/gmapping_glass/gmapping_export/lib
CARMENSUPPORT=0
ARIASUPPORT=0



include /home/jack/ros_ws/slam_glass/gmapping_glass/gmapping_export/manual.mk

