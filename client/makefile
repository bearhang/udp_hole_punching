GXX = g++
CCFLAGS = -g -std=c++11 -I../protobuf 
CCLINKS = -lprotobuf -lpthread

TARGET = client
OBJS = client.o
OBJS += ../protobuf/message.pb.o

default: $(TARGET)

$(TARGET): $(OBJS)
	$(GXX) -o $@ $^ $(CCFLAGS) $(CCLINKS)

%.o: %.cc
	$(CXX) $(CCFLAGS) -c -o $@ $<

%.o: %.cpp
	$(CXX) $(CCFLAGS) -c -o $@ $<

clean:
	@rm $(TARGET) $(OBJS)
