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

static void string_buffer_initialize(string_buffer_t *sb)
{
  sb->len = 0;
  sb->ptr = NULL; 
}

static void string_buffer_finish(string_buffer_t *sb)
{
  if (sb->ptr)  
  {
    free(sb->ptr);
    sb->len = 0;
    sb->ptr = NULL;
  }
}

static size_t string_buffer_callback(void *buf, size_t size, size_t nmemb, void *data)
{
  string_buffer_t *sb = data;
  size_t new_len = sb->len + size * nmemb;
  char *new_ptr = realloc(sb->ptr, new_len + 1);
  if (new_ptr == NULL)
  {
    fprintf(stderr, "Failed to allocate memory.\n");
    return 0;
  }
  sb->ptr = new_ptr;
  memcpy(sb->ptr + sb->len, buf, size * nmemb);
  sb->ptr[new_len] = '\0';
  sb->len = new_len;
  return size * nmemb;
}

static size_t header_callback(char *buf, size_t size, size_t nmemb, void *data)
{
  return string_buffer_callback(buf, size, nmemb, data);
}

static size_t write_callback(void *buf, size_t size, size_t nmemb, void *data)
{
  return string_buffer_callback(buf, size, nmemb, data);
}

int main(int argc, char *argv[])
{
  CURL *curl;
  CURLcode res;
  string_buffer_t strbuf, strbuf2, strbuf3;
  char *api_telegram_consulta = "https://api.telegram.org/bot6712997080:AAG9SOyMPQGrrQh09liX21LhE85PRXQqW3A/getUpdates"; 
  char *api_nasa_apod = "https://randomfox.ca/floof/"; 
  string_buffer_initialize(&strbuf);
  string_buffer_initialize(&strbuf2);
  string_buffer_initialize(&strbuf3);

  /* Inicializar la sesión de CURL una vez */
  curl = curl_easy_init();
  if (!curl)
  {
    fprintf(stderr, "Fatal: curl_easy_init() error.\n");
    string_buffer_finish(&strbuf);
    string_buffer_finish(&strbuf2);
    string_buffer_finish(&strbuf3);
    return EXIT_FAILURE;
  }
  int ciclo = 1;
  while (ciclo)
  {
    printf("Consultando a la API de Telegram\n");
    /* Especificar la URL para consultar si hay mensajes nuevos */
    curl_easy_setopt(curl, CURLOPT_URL, api_telegram_consulta);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Enviar la información de respuesta a la función */
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    /* Preparar el callback para cuando la API responda */
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &strbuf);

    /* Realizar la solicitud */
    res = curl_easy_perform(curl);

    /* Verificar errores */
    if (res != CURLE_OK)
    {
      fprintf(stderr, "Request failed: curl_easy_perform(): %s\n", curl_easy_strerror(res));
      curl_easy_cleanup(curl);
      string_buffer_finish(&strbuf);
      string_buffer_finish(&strbuf2);
      string_buffer_finish(&strbuf3);
      return EXIT_FAILURE;
    }

    // Parsear la respuesta con la biblioteca cJSON
    cJSON *json = cJSON_Parse(strbuf.ptr);

    cJSON *result_json = NULL;
    cJSON *message_json = NULL;
    cJSON *chat_json = NULL;
    cJSON *chat_text_json = NULL;
    cJSON *chat_id_json = NULL;
    result_json = cJSON_GetObjectItemCaseSensitive(json, "result");

    // Iterar por cada mensaje
    cJSON *result_item_json = NULL;
    cJSON_ArrayForEach(result_item_json, result_json)
    {
      message_json = cJSON_GetObjectItemCaseSensitive(result_item_json, "message");
      chat_json = cJSON_GetObjectItemCaseSensitive(message_json, "chat");
      chat_text_json = cJSON_GetObjectItemCaseSensitive(message_json, "text");
      chat_id_json = cJSON_GetObjectItemCaseSensitive(chat_json, "id");

      if (cJSON_IsNumber(chat_id_json))
      {
        // Si es verdadero, hay un nuevo mensaje
        const long int chat_id = (long int)chat_id_json->valuedouble;
        static long int chat_id_previo = 0;
        printf("El chat id es: %ld\n", chat_id);
        const char *message_text = cJSON_GetStringValue(chat_text_json);
        printf("El mensaje es: %s\n", message_text);
          if(chat_id == chat_id_previo)
          {
            // Buscar la palabra "dato" en el mensaje
            if (strstr(message_text, "Dato") != NULL)
            {
              // Solicitar datos a la API de la NASA
              string_buffer_finish(&strbuf2); // Limpia el búfer antes de la solicitud
              curl_easy_setopt(curl, CURLOPT_WRITEDATA, &strbuf2);
              curl_easy_setopt(curl, CURLOPT_URL, api_nasa_apod);
              res = curl_easy_perform(curl);

              if (res == CURLE_OK)
              {
                
                    // Buscar el campo explanation en la respuesta
                    cJSON *json2 = cJSON_Parse(strbuf2.ptr);
                    cJSON *imagen_json = cJSON_GetObjectItemCaseSensitive(json2, "image");
                    const char *imagen = cJSON_GetStringValue(imagen_json);
                    // Buscar el campo url en la respuesta
                    cJSON *url_json = cJSON_GetObjectItemCaseSensitive(json2, "url");
                    const char *url = cJSON_GetStringValue(url_json);

                    // Enviar la respuesta de la API de la NASA a través de Telegram
                    const char *telegram_api_url = "https://api.telegram.org/bot6712997080:AAG9SOyMPQGrrQh09liX21LhE85PRXQqW3A/sendMessage?";
                    // CURL *curl_telegram = curl_easy_init();
                    if (curl)
                    {
                    char message[2048] = {0};
                    snprintf(message, sizeof(message), "%schat_id=%ld&text=%s", telegram_api_url, chat_id,imagen);
                    char message_clean[2048] = {0};
                    int j = 0;
                    for (int i = 0; message[i]!='\0' ; i++)
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
                fprintf(stderr, "Failed to fetch data from NASA API: %s\n", curl_easy_strerror(res));
              }
            }
          }
          chat_id_previo = chat_id;
      }
    }

    /* Limpiar el buffer de respuesta */
    cJSON_Delete(json);
    string_buffer_finish(&strbuf);
    string_buffer_finish(&strbuf2);
    string_buffer_finish(&strbuf3);
    ciclo = 0;
  }

  /* Limpia el buffer y libera recursos de cURL */
  curl_easy_cleanup(curl);
  printf("Termino con exito\n");
  return EXIT_SUCCESS;
}
