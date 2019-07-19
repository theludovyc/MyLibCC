OK_COLOR = \033[0;32m
CR_COLOR = \033[0m

BUILD_FOLDER = "../Build"
IFLAGS = -I"../"

OBJ = areaR.o areaS.o vec.o rect.o

BUILD0 = @g++ -o $(BUILD_FOLDER)/$@ -c $< $(IFLAGS)
BUILD1 = @printf "$(OK_COLOR)%s compiled\n$(CR_COLOR)" $@

all : $(OBJ)

%.o : %.cc
	@mkdir -p $(BUILD_FOLDER)
	$(BUILD0)
	$(BUILD1)
