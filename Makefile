MAIN_SOURCES = $(wildcard src/*.c)
TEST_SOURCES = $(wildcard test/*.c)
MAIN_OBJECTS = $(patsubst src/%.c, src/%.o, $(MAIN_SOURCES))
TEST_OBJECTS = $(patsubst test/%.c, test/%.o, $(TEST_SOURCES))
CFLAGS = -std=c99 -I src
LD_FLAGS = -lcheck -lm -lrt -pthread


all: test libromanmath.a

testrunner: $(MAIN_OBJECTS) $(TEST_OBJECTS)
	@mkdir -p bin
	$(CC) -o bin/$@ $^ $(LD_FLAGS)

test: testrunner
	@echo "For test details: make testverbose"
	bin/$^

testverbose: testrunner
	bin/$^ verbose

libromanmath.a: $(MAIN_OBJECTS)
	@mkdir -p bin
	ar rcs bin/$@ $^

clean:
	rm -Rf bin src/*.o test/*.o
