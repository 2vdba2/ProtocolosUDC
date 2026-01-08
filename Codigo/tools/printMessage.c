#include "printMessage.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Command parse_message(char *buffer) {	
		Command cmd;
		cmd.has_error = 0;
		cmd.seq = -1;   // Valores padrão para comandos sem seq/value
		cmd.value = -1;

		// 1. Verificação básica do terminador "!" conforme o PDF
		int len = strlen(buffer);
		if (len == 0 || buffer[len - 1] != '!') {
				cmd.has_error = 1;
				return cmd;
		}

		// Criamos uma cópia para não estragar o buffer original com o strtok
		char msg[255];
		strncpy(msg, buffer, len - 1); // Remove o '!' para facilitar o parsing
		msg[len - 1] = '\0';

		// 2. Extração da Keyword 
		char *token = strtok(msg, "#");
		if (token != NULL) {
				strcpy(cmd.keyword, token);
		} else {
				cmd.has_error = 1;
				return cmd;
		}

		// 3. Tenta extrair o (seq) 
		token = strtok(NULL, "#");
		if (token != NULL) {
				cmd.seq = atoi(token);
				
				// 4. Tenta extrair o (value) 
				token = strtok(NULL, ")"); // O value termina com ')' antes do '!' 
				if (token != NULL) {
						cmd.value = atoi(token);
				}
		}

		return cmd;
}

void printMessage(Command cmd) {
	printf("\n--- Comando Recebido ---\n");
	
	if (cmd.has_error) {
		printf("Status: [ERRO DE FORMATO]\n"); 
	} else {
		printf("Status:  [OK]\n");
		printf("Keyword: %s\n", cmd.keyword); 
		
		// Só imprime Seq se ele for válido (maior ou igual a 0)
		if (cmd.seq != -1) {
			printf("Seq:	 %d\n", cmd.seq); 
		} else {
			printf("Seq:	 (Nao utilizado)\n");
		}
		
		// Só imprime Value se ele for válido (0 a 100 conforme o PDF)
		if (cmd.value != -1) {
			printf("Value:   %d%%\n", cmd.value); 
		} else {
			printf("Value:   (Nao utilizado)\n");
		}
	}
	printf("------------------------\n");
}
