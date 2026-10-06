# `make` builds, `make test` runs the tests, `make run` runs the program, `make clean` cleans.
UNAME_S := $(shell uname -s 2>/dev/null)
UNAME_M := $(shell uname -m 2>/dev/null)
HOST_OS := $(if $(filter Darwin,$(UNAME_S)),darwin,$(if $(filter Linux,$(UNAME_S)),linux,unknown))
HOST_ARCH := $(if $(filter arm64 aarch64,$(UNAME_M)),arm64,$(if $(filter x86_64 amd64,$(UNAME_M)),amd64,unknown))
HELPER := $(wildcard .coursetools/bin/coursetools-$(HOST_OS)-$(HOST_ARCH))
REPORT_BUILD := $(if $(HELPER),$(HELPER) build --,)
REPORT_TEST  := $(if $(HELPER),$(HELPER) test --,)
REPORT_RUN   := $(if $(HELPER),$(HELPER) run --,)

.PHONY: all build test run clean _build _test _run

all: build

build: _build

test: _test

run: _run

_build:
	$(REPORT_BUILD) sh -c 'cmake --preset default >/dev/null && cmake --build build'

# Builds and runs each *_gtests target on its own, so an unfinished main program (an empty
# placeholder file does not link) never stops the tests from running.
_test:
	@cmake --preset default >/dev/null 2>&1 || cmake --preset default
	@for t in $$(cmake --build build --target help 2>/dev/null | grep -oE '[A-Za-z0-9_]+_gtests' | sort -u); do \
	  echo "== $$t"; cmake --build build --target $$t && $(REPORT_TEST) ./build/$$t; done; true

_run: _build
	@echo 'run your program from ./build'

clean:
	rm -rf build build_valgrind
