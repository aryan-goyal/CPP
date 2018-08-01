CPPFLAGS =	-std=c++11 -g -D_DEBUG -I../../inc -c

run:	dice cards
	./dice
	./cards
	make clean;

dice.o: dice.cpp
	$(CXX) $(CPPFLAGS) -o $@ $^

dice: dice.o
	$(CXX) $(LDFLAGS) -o $@ $^

cards.o: cards.cpp
		$(CXX) $(CPPFLAGS) -o $@ $^

cards: cards.o
		$(CXX) $(LDFLAGS) -o $@ $^

%.o:	%.cpp %.h $(OTHERSRCS)
	$(CXX) -c -o $@ $(CPPFLAGS) $<

clean:
	rm -f core *~ *~%~ *.o

realclean:
	make clean ; rm -f test_set;
