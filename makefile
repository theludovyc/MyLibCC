OK_COLOR = \033[0;32m
CR_COLOR = \033[0m

BUILD_FOLDER = "Build"
BIN_FOLDER = "Bin"

BUILD0 = @g++ -o $(BUILD_FOLDER)/$@ -c $< $(IFLAGS)
BUILD1 = @printf "$(OK_COLOR)%s compiled\n$(CR_COLOR)" $@

all: lib

lib: tool.o geom dataStruct test
	@ar -r $(BUILD_FOLDER)/libMyLibCC.a $(BUILD_FOLDER)/*.o
	@printf "$(OK_COLOR)Create lib MyLibCC success\n$(CR_COLOR)"

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
