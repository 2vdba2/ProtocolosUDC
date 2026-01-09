#ifndef PRINTMESSAGE_H
#define PRINTMESSAGE_H

// Estrutura para organizar os dados extraídos da mensagem
typedef struct {
		char keyword[20];
		int seq;
		int value;
		int has_error; // 0 se ok, 1 se formato inválido
} Command;

Command parse_message(char *buffer);
void printCommand(Command cmd);
void printMessage(char *message); 

#endif


