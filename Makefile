BUILD_DIR = build
SOURCE_DIR = src
vpath %.c ${SOURCE_DIR}
source = $(notdir $(wildcard ${SOURCE_DIR}/*.c))
objs = $(source:%.c=$(BUILD_DIR)/%.o)

CC = g++

build/out: $(objs)
	@echo ${CC}
	${CC} -o $@ $^
	@echo done

debug: CC += -g -O0 -DDEBUG
debug: build/out

$(objs): $(BUILD_DIR)/%.o : %.c
	@mkdir -p $(BUILD_DIR)
	${CC} -c $< -o $@ -lm 

clean:
	rm -rf ${BUILD_DIR}