MAIN_SOURCES = $(wildcard src/*.c)
TEST_SOURCES = $(wildcard test/*.c)
MAIN_OBJECTS = $(patsubst src/%.c, src/%.o, $(MAIN_SOURCES))
TEST_OBJECTS = $(patsubst test/%.c, test/%.o, $(TEST_SOURCES))
LD_FLAGS = -lcheck -lm -lrt -pthread


all: test

testrunner: $(MAIN_OBJECTS) $(TEST_OBJECTS)
	@mkdir -p bin
	$(CC) -o bin/$@ $^ $(LD_FLAGS)

test: testrunner
	bin/$^

clean:
	rm -Rf bin src/*.o test/*.o
