GXX = g++
CCFLAGS = -g -I../protobuf 
CCLINKS = -lprotobuf

TARGET = server
OBJS = server.o

default: $(TARGET)

$(TARGET): $(OBJS)
	GXX -o $@ $^ $(CCFLAGS) $(CCLINKS)

%.o: %.cpp
	$(CXX) $(CCFLAGS) -c -o $@ $<

clean:
	@rm $(TARGET) $(OBJS)
