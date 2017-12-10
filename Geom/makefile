BUILD_FOLDER = "../Build"
IFLAGS = -I"../"

OBJ = areaR.o vec.o rect.o

BUILD0 = @g++ -o $(BUILD_FOLDER)/$@ -c $< $(IFLAGS)
BUILD1 = @printf "%s compiled\n" $@

all : $(OBJ)

%.o : %.cc
	@mkdir -p $(BUILD_FOLDER)
	$(BUILD0)
	$(BUILD1)
