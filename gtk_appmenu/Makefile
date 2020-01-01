CXX      = g++
TARGET   = menubar
CXXFLAGS =-Wall -O2
INCLUDES = -I./include
SRCDIR   = ./src
SOURCES  = $(wildcard $(SRCDIR)/*.cpp)
OBJDIR   = ./bin
OBJECTS  = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.cpp=.o)))
OBJS :=$(SRCS:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ `pkg-config gtkmm-3.0 glibmm-2.4 --cflags --libs`

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	-mkdir -p $(OBJDIR)
	$(CXX) -std=gnu++11 $(CFLAGS) $(INCLUDES) -o $@ -c $< `pkg-config gtkmm-3.0 glibmm-2.4 --cflags --libs`

clean:
	rm -f $(OBJECTS)
