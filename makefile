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

INCPARAMS=$(foreach d, $(INCLUDES), -I$d)
CFLAGS = -g -Wall $(INCPARAMS)
LFLAGS = -Wall
RUNARGS = 

HDRS = include/SinePcm.h
SRCS = src/main.cpp src/SinePcm.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

.PHONY: default all clean

default: $(TARGET)
all: default


%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	@mkdir -p $(OUTDIR)
	$(CC) $(OBJS) $(LFLAGS) $(LIBS) -o $(OUTDIR)/$@

clean:
	@rm -f $(OBJS)
	@rm -f $(OUTDIR)/$(TARGET)
	
run: all
	$(OUTDIR)/$(TARGET) $(RUNARGS)
