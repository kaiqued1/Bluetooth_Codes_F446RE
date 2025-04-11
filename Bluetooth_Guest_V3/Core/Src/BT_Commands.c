#include "BT_Commands.h"
/*
        Inicie a modifica��o aqui:
*/
#include "main.h"

// Fun��o que enviar� apenas uma letra para a Serial
void SerialSendChar(char str){
		extern UART_HandleTypeDef huart1;
    HAL_UART_Transmit(&huart1, (uint8_t *)&str, 1, 1000);
}

// Fun��o que l� um char da Serial
char SerialRead(){
		extern UART_HandleTypeDef huart1;
		char received_data;
		if (HAL_UART_Receive(&huart1, (uint8_t *)&received_data, 1, 1000) == 0x03U){
			return 0x00;
		}
    return received_data;
}

// Fun��o que ativa ou desativa o pino de Enable conforme a linguagem de programa��o
void SetCommandOrText(int set){
		HAL_GPIO_WritePin(GPIOA, BT_EN_Pin, set);
}

/*
        Fim das modifica��es
*/


// Fun��o que envia um char array letra a letra para a Serial
char SerialSendString(char* str) {
	while (*str) {
		SerialSendChar(*str);
		str++;
	}
	
	return *str;
}

// Fun��o que envia comandos para a Serial
void SerialSendCommand(char* str){
    SetCommandOrText(1);
		HAL_Delay(1000);
    SerialSendString(str);
}

// Fun��o que envia texto para a Serial
void SerialSendText(char* str){
    SetCommandOrText(0);
		HAL_Delay(100);
    SerialSendString(str);
}

// Fun��o que Checa o que foi enviado da Serial
int SerialOK(){
    char response = SerialRead();
    int finalResponse = 0;

    if(response != 0x0A){
        if (response == 'O'){
            response = SerialRead();
            if (response == 'K'){
                finalResponse = 1;
            }
        }
				response = SerialRead();
    }
    return finalResponse;
}

