BUILD_FOLDER = "../Build"
BIN_FOLDER = "../Bin"
TEST_FOLDER = "../Test"

BUILD0 = @(cd $(BUILD_FOLDER) && g++ -o $(BIN_FOLDER)/$@.exe $(TEST_FOLDER)/$@.cc

BUILD1 = @printf "%s.exe compiled\n" $@

all:

testRect:
	@mkdir -p $(BIN_FOLDER)
	$(BUILD0) areaR.o vec.o rect.o -I"../Geom" -I"../")
	$(BUILD1)
