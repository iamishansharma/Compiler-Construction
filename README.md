# Compiler-Construction

This was my semester long project for Compiler Construction (CS F363) course at BITS Pilani, Spring 2020.

## ERPLAG

ERPLAG is a toy language made for the course. Details of which can be looked at inside [Language Details]() folder.

## Pre-requisites

The dependencies on using the ERPLAG compiler are -

- `gcc`
- `nasm`

## Testcases

All the testcases are present inside [Testcases]() folder.

- c1 - c6 and v1 - v11 pertain to Code Gen testcases specifically
- All other testcases can be used to check different translational phases of the compiler

## Execution Instructions

- Download this repo and change directory to [Code]() folder.
- Run `make {insert_executable_name_here}` eg. `make compiler`
<br \>
- Run `./{insert_executable_name_here} {path_to_testcase/*.txt} {parseTree_file_name.txt}`
- Eg. Run `./compiler ./Test`
OR
- Run `./{insert_executable_name_here} {path_to_testcase/*.txt} {Assembly_file_name.asm}`

## Execution Instructions for Code Gen Assembly File

### For Linux

	- `nasm -f elf64 -o code.o {Assembly_file_name}.asm`
	- `gcc -no-pie code.o -o code`
	- `./code`
