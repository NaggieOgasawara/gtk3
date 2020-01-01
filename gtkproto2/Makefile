
buildtype := release
ifeq ($(buildtype),release)
	CXXFLAGS += -O3
else
		CXXFLAGS += -O0 -g
endif

CC      = g++
# CFLAGS  = -g -MMD -MP `pkg-config gtkmm-3.0 --cflags --libs`
CFLAGS  = `pkg-config gtkmm-3.0 --cflags --libs`
LDFLAGS =
LIBS    =
INCLUDE = -I src
# -I /usr/include/cairomm-1.0 -I /usr/include/sigc++-2.0 -I /usr/lib/x86_64-linux-gnu/sigc++-2.0/include -I /usr/include/cairo -I /usr/include/freetype2 -I /usr/include/glibmm-2.4 -I /usr/lib/x86_64-linux-gnu/glibmm-2.4/include -I /usr/include/glib-2.0 -I /usr/lib/x86_64-linux-gnu/glib-2.0/include -I /usr/include/gtkmm-3.0 -I /usr/lib/x86_64-linux-gnu/gtkmm-3.0/include -I /usr/lib/x86_64-linux-gnu/gdkmm-3.0/include -I /usr/lib/x86_64-linux-gnu/pangomm-1.4/include -I /usr/include/pangomm-1.4 -I /usr/include/pango-1.0 -I /usr/include/atkmm-1.6
SRC_DIR = src
OBJ_DIR = build
SOURCES = $(shell ls $(SRC_DIR)/*.cpp)
OBJS    = $(subst $(SRC_DIR),$(OBJ_DIR), $(SOURCES:.cpp=.o))
TARGET  = $(notdir $(shell pwd))
DEPENDS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS) `pkg-config gtkmm-3.0 --cflags --libs`

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if [ ! -d $(OBJ_DIR) ]; \
		then echo "mkdir -p $(OBJ_DIR)"; mkdir -p $(OBJ_DIR); \
		fi
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	$(RM) $(OBJS) $(TARGET) $(DEPENDS)

-include $(DEPENDS)

.PHONY: all clean
