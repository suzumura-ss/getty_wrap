TARGET = getty_wrap
SRC = getty_wrap.cpp
CXXFLAGS = -O2 -Wall

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

.PHONY: all clean install
all: $(TARGET)

clean:
	@$(RM) $(TARGET)

install: $(TARGET)
	install $(TARGET) /usr/local/sbin
