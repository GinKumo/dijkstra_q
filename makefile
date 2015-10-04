CXX        := g++-4.8
CXXFLAGS   += -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f DijkstraQ
	rm -f DijkstraQ.tmp
	rm -f TestDijkstraQ
	rm -f TestDijkstraQ.tmp

config:
	git config -l

scrub:
	make  clean
	rm -f  DijkstraQ.log
	rm -rf collatz-tests
	rm -rf html
	rm -rf latex

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: DijkstraQ.tmp TestDijkstraQ.tmp

DijkstraQ: DijkstraQ.h DijkstraQ.c++ RunDijkstraQ.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) DijkstraQ.c++ RunDijkstraQ.c++ -o DijkstraQ

DijkstraQ.tmp: DijkstraQ
	./DijkstraQ < DijkstraQ.in > DijkstraQ.tmp
	diff DijkstraQ.tmp DijkstraQ.out

TestDijkstraQ: DijkstraQ.h DijkstraQ.c++ TestDijkstraQ.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) DijkstraQ.c++ TestDijkstraQ.c++ -o TestDijkstraQ $(LDFLAGS)

TestDijkstraQ.tmp: TestDijkstraQ
	$(VALGRIND) ./TestDijkstraQ                                       >  TestDijkstraQ.tmp 2>&1
	$(GCOV) -b DijkstraQ.c++     | grep -A 5 "File 'DijkstraQ.c++'"     >> TestDijkstraQ.tmp
	$(GCOV) -b TestDijkstraQ.c++ | grep -A 5 "File 'TestDijkstraQ.c++'" >> TestDijkstraQ.tmp
	cat TestDijkstraQ.tmp
