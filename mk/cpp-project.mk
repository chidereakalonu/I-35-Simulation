CXX		:= g++
TARGET	= $(PROJNAME)$(EXT)
TSTAPP := testapp

HDRS	:= $(shell python mk/pyfind.py include .h)

USRCS	:= $(wildcard src/*.cpp)
TSRCS	:= $(wildcard tests/*.cpp)
LSRCS	:= $(shell python mk/pyfind.py lib .cpp)
ALLSRCS := $(USRCS) $(LSRCS) $(TSRCS)

UOBJS   := $(USRCS:.cpp=.o)
LOBJS   := $(LSRCS:.cpp=.o)
TOBJS	:= $(TSRCS:.cpp=.o)
ALLOBJS := $(UOBJS) $(LOBJS) $(TOBJS)

ifeq ($(PLATFORM), Windows)
	DOBJS := $(subst /,\,$(UOBJS)) $(subst /.\,$(LOBJS))
else
	DOBJS := $(UOBJS) $(LOBJS) $(TOBJS)
endif

CFLAGS	= -I /usr/local/include -I include -std=c++11
CFLAGS += -Wno-deprecated-declarations


.PHONY: all
all: $(TARGET) ## build application (default)

$(TARGET):	$(UOBJS) $(LOBJS)
	g++ -o $@ $^ $(LFLAGS)

$(TSTAPP):	$(TOBJS) $(LOBJS)
	g++ -o $@ $^ $(LFLAGS)



%.o:	%.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

.PHONY:	run
run:	$(TARGET)	## launch primary build application
	$(PREFIX)$(TARGET)

.PHONY: clean
clean:	## remove all build artifacts
	$(RM) $(TARGET) $(DOBJS)

.PHONY: test
test:	$(TSTAPP)
	./$(TSTAPP)
