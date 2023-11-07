JAVA_FILES := $(wildcard *.java)

CLASS_FILES := $(JAVA_FILES:.java=.class)

all: $(CLASS_FILES)

%.class: %.java
	javac $<

clean:
	@rm -f $(CLASS_FILES)

.PHONY: all clean

