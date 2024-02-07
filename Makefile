CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++20 -fPIC
CPPFLAGS = -Isrc/

SLIB = librubik.a

ARFLAGS ?= rcs

OBJ = src/librubik/cube.o               \
      src/librubik/move.o               \
      src/librubik/piece.o              \
      src/librubik/solver/f2l.o         \
      src/librubik/solver/oll.o         \
      src/librubik/solver/pll.o         \
      src/librubik/solver/parse-csv.o

CLI_OBJ = src/main.o $(OBJ) $(SLIB)
CLI_BIN = cli

TESTS_OBJ = tests/test_main.o $(OBJ) $(SLIB)
TESTS_BIN = unit_tests

all: $(SLIB) $(CLI_BIN)

library: $(SLIB)

$(SLIB): $(OBJ)

%.a:
	$(AR) $(ARFLAGS) $@ $^

$(CLI_BIN): $(CLI_OBJ)
	$(LINK.cc) $^ $(LDLIBS) -o $@

$(TESTS_BIN): LDLIBS += -lgtest
$(TESTS_BIN): $(TESTS_OBJ)
	$(LINK.cc) $^ $(LDLIBS) -o $@

check: $(TESTS_BIN)
	./$(TESTS_BIN)

clean:
	$(RM) $(SLIB) $(OBJ) $(CLI_OBJ) $(CLI_BIN) $(TESTS_BIN) $(TESTS_OBJ)

.PHONY: all check clean
