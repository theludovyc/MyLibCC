BUILD_FOLDER = "Build"

BUILD0 = @g++ -o $(BUILD_FOLDER)/$@ -c $< $(IFLAGS)
BUILD1 = @printf "%s compiled\n" $@

all: tool.o geom

tool.o: tool.cc tool.h
	@mkdir -p $(BUILD_FOLDER)
	$(BUILD0)
	$(BUILD1)

geom:
	@(cd Geom && $(MAKE))

clean:
	rm -f $(BUILD_FOLDER)/*.o
