VPATH = src
OBJFILES := Port.o USART.o

all: $(OBJFILES)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	-rm *.o *.hex *.map *.elf
