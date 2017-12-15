BUILD_FOLDER = "Build"
BIN_FOLDER = "Bin"

BUILD0 = @g++ -o $(BUILD_FOLDER)/$@ -c $< $(IFLAGS)
BUILD1 = @printf "%s compiled\n" $@

all: tool.o geom dataStruct test

tool.o: tool.cc tool.h
	@mkdir -p $(BUILD_FOLDER)
	$(BUILD0)
	$(BUILD1)

geom:
	@(cd Geom && $(MAKE))

dataStruct:
	@(cd DataStruct && $(MAKE))

test:
	@(cd Test && $(MAKE))

clean:
	rm -f $(BUILD_FOLDER)/*.o
	rm -f $(BIN_FOLDER)/*.out
