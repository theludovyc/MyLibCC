BUILD_FOLDER = "../Build"
BIN_FOLDER = "../Bin"
TEST_FOLDER = "../Test"

MKDIR = @mkdir -p $(BIN_FOLDER)

IFLAGS = -I"../"

IGM = -I"../Geom" $(IFLAGS)
IDS = -I"../DataStruct" $(IFLAGS)

BUILD0 = @(cd $(BUILD_FOLDER) && g++ -o $(BIN_FOLDER)/$@.out $(TEST_FOLDER)/$@.cc

BUILD1 = @printf "%s.out compiled\n" $@

all: testRect testAry testDynAry testGListChars

testRect:
	$(MKDIR)
	$(BUILD0) areaR.o vec.o rect.o $(IGM))
	$(BUILD1)

testAry:
	$(MKDIR)
	$(BUILD0) tool.o ary.o $(IDS))
	$(BUILD1)

testDynAry:
	$(MKDIR)
	$(BUILD0) tool.o ary.o dynAry.o $(IDS))
	$(BUILD1)

testGListChars:
	$(MKDIR)
	$(BUILD0) tool.o ary.o dynAry.o dynAryChar.o gList.o gListChars.o $(IDS))
	$(BUILD1)
