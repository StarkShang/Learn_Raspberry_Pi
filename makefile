# 定义路径结构
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
LIB_DIR := 

# 源文件列表
SRCS := $(shell find $(SRC_DIR) -name '*.c' -print)
$(warning $(SRCS))

# obj文件列表
OBJS := $(patsubst $(SRC_DIR)%.c,$(BUILD_DIR)%.o, $(SRCS))
$(warning $(OBJS))

# 设置gcc编译配置
CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles

all: clean kernel8.img

$(BUILD_DIR)/start.o: $(SRC_DIR)/os/start.S
	aarch64-elf-gcc $(CFLAGS) -c $^ -o $@

$(OBJS): $(BUILD_DIR)/%.o: $(SRCS)
	$(shell if [ ! -e $(dir $(dir $@)) ];then mkdir -p $(dir $(dir $@)); fi)
	aarch64-elf-gcc $(CFLAGS) -c $(patsubst $(BUILD_DIR)%.o,$(SRC_DIR)%.c, $@) -o $@

kernel8.img: $(BUILD_DIR)/start.o $(OBJS)
	aarch64-elf-ld -nostdlib $(BUILD_DIR)/start.o $(OBJS) -T link.ld -o $(BUILD_DIR)/kernel8.elf
	aarch64-elf-objcopy -O binary $(BUILD_DIR)/kernel8.elf $(BIN_DIR)/kernel8.img

clean:
	@rm $(BIN_DIR)/kernel8.img $(BUILD_DIR)/kernel8.elf $(BUILD_DIR)/*.o >/dev/null 2>/dev/null || true

run:
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -d in_asm