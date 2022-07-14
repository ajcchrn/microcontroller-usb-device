.PHONY: all src lib
all: src lib

src: lib
	$(MAKE) -C src

lib:
	$(MAKE) -C lib

.PHONY: clean
clean:
	$(MAKE) -C src clean
	$(MAKE) -C lib clean
