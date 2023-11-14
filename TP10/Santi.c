#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include "cJSON.h"

typedef struct string_buffer_s
{
	char *ptr;
	size_t len;
} string_buffer_t;

// Funciones y estructuras restantes sin cambios

int main(int argc, char *argv[])
{
	CURL *curl;
	CURLcode res;
	string_buffer_t strbuf2, strbuf3;
	const char *api_telegram_consulta = "https://api.telegram.org/bot6866775472:AAEdyyIPrr43qHaiNzolzWlU_SJgSgjGwA8/getUpdates";
	const char *api_number = "http://numbersapi.com/random/trivia";
	string_buffer_initialize(&strbuf2);
	string_buffer_initialize(&strbuf3);
	
	curl = curl_easy_init();
	if (!curl)
	{
		fprintf(stderr, "Fatal: curl_easy_init() error.\n");
		string_buffer_finish(&strbuf2);
		string_buffer_finish(&strbuf3);
		return EXIT_FAILURE;
	}
	
	int ciclo = 1;
	while (ciclo)
	{
		printf("Consultando a la API de Telegram\n");
		curl_easy_setopt(curl, CURLOPT_URL, api_telegram_consulta);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		
		res = curl_easy_perform(curl);
		
		if (res != CURLE_OK)
		{
			fprintf(stderr, "Request failed: curl_easy_perform(): %s\n", curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			
			string_buffer_finish(&strbuf2);
			string_buffer_finish(&strbuf3);
			return EXIT_FAILURE;
		}
		
		cJSON *json = cJSON_Parse(strbuf.ptr);
		cJSON *result_json = NULL;
		cJSON *message_json = NULL;
		cJSON *chat_json = NULL;
		cJSON *chat_text_json = NULL;
		cJSON *chat_id_json = NULL;
		result_json = cJSON_GetObjectItemCaseSensitive(json, "result");
		
		cJSON *result_item_json = NULL;
		cJSON_ArrayForEach(result_item_json, result_json)
		{
			message_json = cJSON_GetObjectItemCaseSensitive(result_item_json, "message");
			chat_json = cJSON_GetObjectItemCaseSensitive(message_json, "chat");
			chat_text_json = cJSON_GetObjectItemCaseSensitive(message_json, "text");
			chat_id_json = cJSON_GetObjectItemCaseSensitive(chat_json, "id");
			
			if (cJSON_IsNumber(chat_id_json))
			{
				const long int chat_id = (long int)chat_id_json->valuedouble;
				static long int chat_id_previo = 0;
				printf("El chat id es: %ld\n", chat_id);
				const char *message_text = cJSON_GetStringValue(chat_text_json);
				printf("El mensaje es: %s\n", message_text);
				if (chat_id == chat_id_previo)
				{
					if (strstr(message_text, "Dato") != NULL)
					{
						string_buffer_finish(&strbuf2);
						curl_easy_setopt(curl, CURLOPT_WRITEDATA, &strbuf2);
						curl_easy_setopt(curl, CURLOPT_URL, api_number);
						res = curl_easy_perform(curl);
						
						if (res == CURLE_OK)
						{
							cJSON *json2 = cJSON_Parse(strbuf2.ptr);
							cJSON *number_json = cJSON_GetObjectItemCaseSensitive(json2, "number");
							const char *number = cJSON_GetStringValue(number_json);
							cJSON *url_json = cJSON_GetObjectItemCaseSensitive(json2, "url");
							const char *url = cJSON_GetStringValue(url_json);
							
							const char *telegram_api_url = "https://api.telegram.org/bot6866775472:AAEdyyIPrr43qHaiNzolzWlU_SJgSgjGwA8/sendMessage?";
							if (curl)
							{
								char message[2048] = {0};
								printf("%s\n", number);
								snprintf(message, sizeof(message), "%schat_id=%ld&text=%s%s %s", telegram_api_url, chat_id, "ESTA ES LA FRASE DEL DIA \n\n", number, url);
								char message_clean[2048] = {0};
								int j = 0;
								for (int i = 0; message[i] != '\0'; i++)
								{
									if (message[i] == ' ')
									{
										message_clean[j++] = '%';
										message_clean[j++] = '2';
										message_clean[j++] = '0';
									}
									else if (message[i] < 0 || message[i] > 127)
									{
										message_clean[j++] = '_';
									}
									else if (message[i] == ',' || message[i] == '\\')
									{
										message_clean[j++] = '%';
										message_clean[j++] = '2';
										message_clean[j++] = 'C';
										i++;
									}
									else
									{
										message_clean[j++] = message[i];
									}
								}
								printf("El mensaje a enviar es: %s\n", message_clean);
								curl_easy_setopt(curl, CURLOPT_URL, message_clean);
								curl_easy_setopt(curl, CURLOPT_WRITEDATA, &strbuf3);
								res = curl_easy_perform(curl);
							}
							if (res != CURLE_OK)
							{
								fprintf(stderr, "Failed to send message to Telegram: %s\n", curl_easy_strerror(res));
							}
						}
						else
						{
							fprintf(stderr, "Failed to fetch data from Number API: %s\n", curl_easy_strerror(res));
						}
					}
				}
				chat_id_previo = chat_id;
			}
		}
		
		cJSON_Delete(json);
		string_buffer_finish(&strbuf);
		string_buffer_finish(&strbuf2);
		string_buffer_finish(&strbuf3);
		ciclo = 0;
	}
	
	curl_easy_cleanup(curl);
	return EXIT_SUCCESS;
}
