/*
        Inicie a modificação aqui:
*/



/*
        Fim das modificações
*/

// Função que enviará apenas uma letra
void SerialSendChar(char str);

// Função que lê um char da Serial
char SerialRead();

// Função que ativa ou desativa o pino de Enable conforme a linguagem de programação
void SetCommandOrText(int set);


// Função que envia um char array letra a letra para a Serial
char SerialSendString(char* str);

// Função que envia comandos para a Serial
void SerialSendCommand(char* str);

// Função que envia texto para a Serial
void SerialSendText(char* str);

// Função que Checa o que foi enviado da Serial
int SerialOK();

