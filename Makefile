CXX ?= g++

CXXFLAGS += -c -Wall $(shell pkg-config --cflags opencv)
LDFLAGS += $(shell pkg-config --libs --static opencv)

all: generateEllipseCandidatescpp

generateEllipseCandidatescpp: generateEllipseCandidatescpp.o; $(CXX) $< -o $@ $(LDFLAGS)

%.o: %.cpp; $(CXX) $< -o $@ $(CXXFLAGS)

clean: ; rm -f generateEllipseCandidatescpp.o generateEllipseCandidatescpp
