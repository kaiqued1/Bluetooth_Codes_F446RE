/*
        Inicie a modifica��o aqui:
*/



/*
        Fim das modifica��es
*/

// Fun��o que enviar� apenas uma letra
void SerialSendChar(char str);

// Fun��o que l� um char da Serial
char SerialRead();

// Fun��o que ativa ou desativa o pino de Enable conforme a linguagem de programa��o
void SetCommandOrText(int set);


// Fun��o que envia um char array letra a letra para a Serial
char SerialSendString(char* str);

// Fun��o que envia comandos para a Serial
void SerialSendCommand(char* str);

// Fun��o que envia texto para a Serial
void SerialSendText(char* str);

// Fun��o que Checa o que foi enviado da Serial
int SerialOK();

