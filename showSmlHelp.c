/**
 * @file shortSmlHelp.c
 * @author lemadior (https://github.com/lemadior/simpletron)
 * @brief Short help for available SML machine instrcutions
 * @details the help can be called both from system promt and from 
 * the program insertion mode directly. The last mode shows more
 * information about each comamnd than in the system mode.
 * @version 0.1
 * @date 2026-03-16
 * * @copyright Copyright (c) 2026
 * */

#include "sml.h"

static void showIntro(void);
static void showNopShort(void);
static void showNopFull(void);
static void showReadShort(void);
static void showReadFull(void);
static void showWriteShort(void);
static void showWriteFull(void);
static void showLoadShort(void);
static void showLoadFull(void);
static void showStoreShort(void);
static void showStoreFull(void);
static void showAddShort(void);
static void showAddFull(void);
static void showSubShort(void);
static void showSubFull(void);
static void showDivShort(void);
static void showDivFull(void);
static void showMulShort(void);
static void showMulFull(void);
static void showJumpShort(void);
static void showJumpFull(void);
static void showJumpNegShort(void);
static void showJumpNegFull(void);
static void showJumpZeroShort(void);
static void showJumpZeroFull(void);
static void showHaltShort(void);
static void showHaltFull(void);

void showSmlHelp(uint8_t command)
{
	NEWLINE;

	switch(command) {
		case 0:
			showNopShort();
			showNopFull();
			break;
		case 10:
			showReadShort();
			showReadFull();
			break;
		case 11:
			showWriteShort();
			showWriteFull();
			break;
		case 20:
			showLoadShort();
			showLoadFull();
			break;
		case 21:
			showStoreShort();
			showStoreFull();
			break;
		case 30:
			showAddShort();
			showAddFull();
			break;
		case 31:
			showSubShort();
			showSubFull();
			break;
		case 32:
			showDivShort();
			showDivFull();
			break;
		case 33:
			showMulShort();
			showMulFull();
			break;
		case 40:
			showJumpShort();
			showJumpFull();
			break;
		case 41:
			showJumpNegShort();
			showJumpNegFull();
			break;
		case 42:
			showJumpZeroShort();
			showJumpZeroFull();
			break;
		case 43:
			showHaltShort();
			showHaltFull();
			break;
		default:
			printf(" No help for this command!\n");
	}

	NEWLINE;
}

void showAllHelp(void)
{
	showIntro();
	showNopShort();
	showReadShort();
	showWriteShort();
	showLoadShort();
	showStoreShort();
	showAddShort();
	showSubShort();
	showDivShort();
	showMulShort();
	showJumpShort();
	showJumpNegShort();
	showJumpZeroShort();
	showHaltShort();
}

static void showIntro(void)
{
	printf(" SML commands short HELP:\n");
	printf(" ------------------------\n");
	printf(" SML operates with 'words' (a four digit number)\n");
	printf(" The 'word' is a numeric value from -9999 to 9999\n");
	printf(" First two digit of the 'word' is a command number\n");
	printf(" LAST two digit of the 'word' is a operand (memory address)\n");
	printf(" Also SML used the accumulator - a special register in CPU\n");
	printf(" Note: almost each command has an operand - usually memory address");
	printf("\n Commands:\n");
}

static void showNopShort(void)
{
	printf(" Command 'NOP' - No operation\n");
	printf(" Code: [00]\n");
}

static void showNopFull(void)
{
	printf(" Do nothing. SML just skip it and go to the next command\n");
}

static void showReadShort(void)
{
	printf(" Comamnd 'READ' - read a word from terminal\n");
	printf(" Code: [10]\n");
}

static void showReadFull(void)
{
	printf(" Get value from terminal and store it in the memory cell\n");
	printf(" Memory cell is a second 2 digit part of the opcode\n");
	printf(" Example: 1007. Store value in memory cell at the 07 address\n");
}

static void showWriteShort(void)
{
	printf(" Command 'WRITE' - print a word to terminal\n");
	printf(" Code: [11]\n");
}

static void showWriteFull(void)
{
	printf(" Print a value, stored in specified memory cell to the terminal.\n");
	printf(" Example: 1107. Print value from cell stored at the  address 07\n");
}

static void showLoadShort(void)
{
	printf(" Command 'LOAD' - Put word from specified address into accumulator\n");
	printf(" Code: [20]\n");
}

static void showLoadFull(void)
{
	printf(" Example: 2005. Save the value from memory cell 05 to the accumulator\n");
}

static void showStoreShort(void)
{
	printf(" Command 'STORE' - Save the value from accumulator to specified address\n");
	printf(" Code: [21]\n");
}

static void showStoreFull(void)
{
	printf(" Example: 2105. Save the value from accumulator to memory by address 05\n");
}

static void showAddShort(void)
{
	printf(" Command 'ADD' - Add accumulator's value and value in specified address\n");
	printf(" Code: [30]\n");
}

static void showAddFull(void)
{
	printf(" Note: the result will store in accumulator back!\n");
}

static void showSubShort(void)
{
	printf(" Command 'SUB' - Subtract value in specified address from accumulator's value\n");
	printf(" Code: [31]\n");
}

static void showSubFull(void)
{
	printf(" Note: the result will store in accumulator back!\n");
}

static void showDivShort(void)
{
	printf(" Command 'DIV' - Divide accumulator's value by value in specified address\n");
	printf(" Code: [32]\n");
}

static void showDivFull(void)
{
	printf(" Note: the result will store in accumulator back!\n");
}

static void showMulShort(void)
{
	printf(" Command 'MUL' - Nultiple accumulator's value by value in specified address\n");
	printf(" Code: [33]\n");
}

static void showMulFull(void)
{
	printf(" Note: the result will store in accumulator back!\n");
}

static void showJumpShort(void)
{
	printf(" Command 'JUMP' - Jump to specified address\n");
	printf(" Code: [40]\n");
}

static void showJumpFull(void)
{
	printf(" Example: 4005. Go to address 05 and start execute command store in it\n");
}


static void showJumpNegShort(void)
{
	printf(" Command 'JNEG' - Jump to specified address if accumulator's value < 0\n");
	printf(" Code: [41]\n");
}

static void showJumpNegFull(void)
{
	printf(" Example: 4105. Go to address 05 if accumulator contains value less than 0\n");
}

static void showJumpZeroShort(void)
{
	printf(" Command 'JZERO' - Jump to specified address if accumulator's value = 0\n");
	printf(" Code: [42]\n");
}

static void showJumpZeroFull(void)
{
	printf(" Example: 4205. Go to address 05 if accumulator contains value equiv zero\n");
}

static void showHaltShort(void)
{
	printf(" Command 'HALT' - Stop execution the program\n");
	printf(" Code: [43]\n");
}

static void showHaltFull(void)
{
	printf(" Note: this command is mandatory for SML program!\n"); 
	printf(" Otherwise it will start execute 'garbae' commands.\n");
}

