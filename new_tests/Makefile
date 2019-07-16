CC=gcc
BIN=./binaries/

all: stack_smash unbounded_byte_write_stack unbounded_byte_write_global fmt_str_attack

stack_smash: stack_smash.c
	$(CC) -g $< -fno-stack-protector -no-pie -z execstack -o $(BIN)/$@_exec_stack
	$(CC) -g $< -fno-stack-protector -no-pie -o $(BIN)/$@_no_exec_stack

unbounded_byte_write_stack: unbounded_byte_write_stack.c
	$(CC) -g $< -no-pie -z execstack -o $(BIN)/$@_exec_stack
	$(CC) -g $< -no-pie -o $(BIN)/$@_no_exec_stack

unbounded_byte_write_global: unbounded_byte_write_global.c
	$(CC) -g $< -no-pie -z execstack -o $(BIN)/$@_exec_stack
	$(CC) -g $< -no-pie -o $(BIN)/$@_no_exec_stack

heap_smash: heap_smash.c
	$(CC) $< -no-pie -o $(BIN)/$@

fmt_str_attack: fmt_str_attack.c
	$(CC) $< -O1 -no-pie -o $(BIN)/$@_FORTIFY_0 -D_FORTIFY_SOURCE=0
	$(CC) $< -O1 -no-pie -o $(BIN)/$@_FORTIFY_1 -D_FORTIFY_SOURCE=1
	$(CC) $< -O1 -no-pie -o $(BIN)/$@_FORTIFY_2 -D_FORTIFY_SOURCE=2
