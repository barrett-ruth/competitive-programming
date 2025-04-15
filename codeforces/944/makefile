.PHONY: run debug clean setup init

CXX = g++
# lefticus.gitbooks.io/cpp-best-practice
CXXFLAGS := -O2 -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 \
	-Wfloat-equal -Wlogical-op -Wshift-overflow=2 -Wnon-virtual-dtor \
	-Wold-style-cast -Wcast-equal -Wuseless-cast -Wno-sign-promotion \
	-Wcast-align -Wunused -Woverloaded-virtual -Wconversion \
	-Wsign-conversion -Wmisleading-indentation -Wduplicated-cond \
	-Wduplicated-branches -Wlogical-op -Wnull-dereference -Wformat=2 \
	-Wformat-overflow -Wformat-truncation -Wdouble-promotion -Wundef \
	-DLOCAL -std=c++20

# https://interrupt.memfault.com/blog/best-and-worst-gcc-clang-compiler-flags
DEBUG_CXX_FLAGS := -g3 -fsanitize=address,undefined \
	-fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow \
	-fno-sanitize-recover=all -fstack-protector-all -fstack-usage \
	-fno-omit-frame-pointer -fno-inline -ffunction-sections

DEBUG_CXXFLAGS += -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC

SRC = $(word 2,$(MAKECMDGOALS))
BASE = $(basename $(SRC))
INPUT = $(BASE).in
OUTPUT = $(BASE).out
RUN_BIN = $(BASE).run
DBG_BIN = $(BASE).debug

TEMPLATE_DIR = ~/.config/cp-template

.SILENT:

run: $(RUN_BIN)
	$(call execute_binary,$(RUN_BIN))

debug: $(DBG_BIN)
	$(call execute_binary,$(DBG_BIN))

$(RUN_BIN): $(SRC)
	test -f $@ && rm $@ || true
	$(CXX) @compile_flags.txt $(SRC) -o $@ 2>$(OUTPUT); \
	CODE=$$?; \
	if [ $${CODE} -gt 0 ]; then \
		printf '\n[code]: %s' $${CODE} >>$(OUTPUT); \
		exit $${CODE}; \
	else \
		echo '' >$(OUTPUT); \
	fi

$(DBG_BIN): $(SRC)
	test -f $@ && rm $@ || true
	$(CXX) @compile_flags.txt $(DEBUG_CXX_FLAGS) $(SRC) -o $@ 2>$(OUTPUT); \
	CODE=$$?; \
	if [ $${CODE} -gt 0 ]; then \
		printf '\n[code]: %s' $${CODE} >>$(OUTPUT); \
		exit $${CODE}; \
	else \
		echo '' >$(OUTPUT); \
	fi

define execute_binary
	timeout 2s ./$1 < $(INPUT) >$(OUTPUT) 2>&1; \
	CODE=$$?; \
	truncate -s $$(head -n 1000 $(OUTPUT) | wc -c) $(OUTPUT); \
	if [ $${CODE} -ge 124 ]; then \
		MSG=''; \
		case $${CODE} in \
			124) MSG='TIMEOUT';; \
			128) MSG='SIGILL';; \
			130) MSG='SIGABRT';; \
			131) MSG='SIGBUS';; \
			136) MSG='SIGFPE';; \
			135) MSG='SIGSEGV';; \
			137) MSG='SIGPIPE';; \
			139) MSG='SIGTERM';; \
		esac; \
		[ -n "$${MSG}" ] && printf '\n[code]: %s (%s)' "$${CODE}" "$${MSG}" >>$(OUTPUT); \
	else \
		printf '\n[code]: %s' $${CODE} >>$(OUTPUT); \
	fi
endef

clean:
	find . -type f -name "*.run" -o -name "*.debug" -o -name "*.su" | xargs rm -f

setup:
	test -f compile_flags.txt || cp $(TEMPLATE_DIR)/compile_flags.txt .
	test -f .clangd || cp $(TEMPLATE_DIR)/.clangd .
	test -f .clang-format || cp $(TEMPLATE_DIR)/.clang-format .

init:
	make setup

%:
	@:
