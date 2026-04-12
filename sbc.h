/**
 * @file sbc.h
 * @author lemadior
 * @brief header file with main options and settings for the project
 * @version 0.1.0
 * @date 2026-06-11
 * * @copyright Copyright (c) 2026
 * 
 * =================================================================
 *
 * The SIMPLETRON CPU command compiler
 *
 * This is a very basic compilator of the fiction CPU.
 *
 * SPEC:
 * -----------------
 *
 * */

#ifndef SBC_H
#define SBC_H

#include "commands.h"
#include "func.h"

#include "INFIX/infix.h"
#include "POSTFIX/postfix.h"

/* extern Commands CMD; */

void getFileName(char *, uint8_t);

/* void listProgram(void); */
void saveProgram(void);
void loadProgram(void);

/* void showSmlHelp(uint8_t); */
/* void showAllHelp(void); */

/* void dumpCommand(short, uint8_t); */

void memoryInit(void);

void input(short *);
void print(short *);

#endif


