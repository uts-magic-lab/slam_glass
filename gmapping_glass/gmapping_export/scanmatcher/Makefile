OBJS= smmap.o scanmatcher.o scanmatcherprocessor.o eig3.o
APPS= scanmatch_test icptest

#LDFLAGS+= $(GSL_LIB) -lutils -lsensor_range -llog
LDFLAGS+= -lsensor_range -lsensor_base -lsensor_odometry -llog -lsensor_odometry -lutils
#CPPFLAGS+=-I../sensor $(GSL_INCLUDE)
CPPFLAGS+=-I../sensor

-include ../global.mk
-include ../build_tools/Makefile.generic-shared-object

