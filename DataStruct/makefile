BUILD_FOLDER = "../Build"
IFLAGS = -I"../"
WFLAGS = -w

OBJ = ary.o aary.o aryInt.o dynAry.o dynAryChar.o gList.o gListChars.o

BUILD0 = @g++ -o $(BUILD_FOLDER)/$@ -c $< $(IFLAGS) $(WFLAGS)
BUILD1 = @printf "%s compiled\n" $@

all : $(OBJ)

%.o : %.cc
	@mkdir -p $(BUILD_FOLDER)
	$(BUILD0)
	$(BUILD1)
