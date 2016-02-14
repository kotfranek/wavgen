# Sound Test
#

ifdef TCLAP_HOME
    $(info TCLAP location is '$(TCLAP_HOME)')
else
    $(warning TCLAP_HOME environment variable undefined)
    TCLAP_HOME=../tclap
endif

TARGET = sndtest
OUTDIR = bin
LIBS = -lm
CC = g++
INCLUDES = include $(TCLAP_HOME)/include
LIBDIRS = 

INCPARAMS=$(foreach d, $(INCLUDES),-I$d)
LIBDIRPARAMS=$(foreach d, $(LIBDIRS),-L$d)

#OPTFLAGS = -s -O3
CFLAGS = -g -Wall -std=c++11 $(INCPARAMS) $(OPTFLAGS)
LFLAGS = -Wall $(LIBDIRPARAMS)
RUNARGS = 

SRCS = src/main.cpp src/audio/SinePcm.cpp

OBJS = $(subst .cpp,.o,$(SRCS))

.PHONY: default all clean

default: all
all: $(TARGET)

.PRECIOUS: $(TARGET) $(OBJS)

DEPS := $(OBJS:.o=.d)

-include $(DEPS)

%.o: %.cpp
	@$(CC) $(CFLAGS) -MM -MT $@ -MF $(patsubst %.o,%.d,$@) $<
	$(CC) $(CFLAGS) -c $< -o $@


$(TARGET): $(OBJS)
	@mkdir -p $(OUTDIR)
	$(CC) $(OBJS) $(LFLAGS) $(LIBS) -o $(OUTDIR)/$@ -pthread $(OPTFLAGS)

clean:
	@rm -f $(OBJS)
	@rm -f $(DEPS)	
	@rm -f $(OUTDIR)/$(TARGET).a
