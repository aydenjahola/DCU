SCRIPTS := $(wildcard [a-z]*)

DEST_DIR := $(HOME)/local/bin

install: $(addprefix $(DEST_DIR)/, $(SCRIPTS))

$(DEST_DIR)/%: %
	@echo "install -v -m 0755 $< $@"
	@mkdir -p $(DEST_DIR)
	@install -v -m 0755 $< $@

.PHONY: install

default: install

