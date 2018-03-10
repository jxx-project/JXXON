.PHONY: all build test install clean

all: build test

build:
	$(MAKE) -C build all

test:
	$(MAKE) -C build test

install:
	$(MAKE) -C build install

clean:
	rm -rf build
