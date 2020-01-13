CPPC = g++
OBJS = main.o bitmap.o Position.o
EXEC = step1
DEBUG_FLAG = # now empty, assign -g for debug
COMP_FLAG = -std=c++11 -Wall

$(EXEC) : $(OBJS)
	$(CPPC) $(DEBUG_FLAG) $(OBJS) -o $@
	rm -f $(OBJS)
main.o :
	$(CPPC) -c $(DEBUG_FLAG) $(COMP_FLAG) main.cpp
bitmap.o: bitmap.cpp bitmap.h
	$(CPPC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
Position.o: Position.cpp Position.h
	$(CPPC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
clean:
	rm -f $(OBJS) $(EXEC)
