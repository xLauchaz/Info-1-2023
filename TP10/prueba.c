#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include "cJSON.h"

typedef struct string_buffer_s
{
  char * ptr;
  size_t len;
} string_buffer_t;

static void string_buffer_initialize(string_buffer_t *sb)
{
  sb->len = 0;
  sb->ptr = malloc(sb->len + 1);
  sb->ptr[0] = '\0';
}

static void string_buffer_finish(string_buffer_t *sb)
{
  free(sb->ptr);
  sb->len = 0;
  sb->ptr = NULL;
}

static size_t string_buffer_callback(void *buf, size_t size, size_t nmemb, void *data)
{
  string_buffer_t *sb = data;
  size_t new_len = sb->len + size * nmemb;
  sb->ptr = realloc(sb->ptr, new_len + 1);
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
  string_buffer_t strbuf;
#ifndef BOT_TOKEN
  char *api_telegram_consulta = "https://api.telegram.org/bot6866775472:AAEdyyIPrr43qHaiNzolzWlU_SJgSgjGwA8/getUpdates";
#endif
  char *api_nasa_apod = "https://api.nasa.gov/planetary/apod?api_key=galEbCY2LUiHOaWbt9Mkwqy1JBhZc4sQvxkVDM1S";
  string_buffer_initialize(&strbuf);

  /* Inicializar la sesión de curl */
  curl = curl_easy_init();
  if (!curl)
  {
    fprintf(stderr, "Fatal: curl_easy_init() error.\n");
    string_buffer_finish(&strbuf);
    return EXIT_FAILURE;
  }

  while (1)
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
        int chat_id = chat_id_json->valueint;
        printf("El chat id es: %d\n", chat_id);
        const char *message_text = cJSON_GetStringValue(chat_text_json);
        printf("El mensaje es: %s\n", message_text);

        // Buscar la palabra "dato" en el mensaje
        if (strstr(message_text, "dato") != NULL)
        {
          // Solicitar datos a la API de la NASA
          
          curl_easy_setopt(curl, CURLOPT_URL, api_nasa_apod);
          string_buffer_finish(&strbuf);
          curl_easy_setopt(curl, CURLOPT_WRITEDATA, &strbuf);
          res = curl_easy_perform(curl);

          if (res == CURLE_OK)
          {
            // Enviar la respuesta de la API de la NASA a través de Telegram
            char telegram_api_url[1024];
            snprintf(telegram_api_url, sizeof(telegram_api_url), "https://api.telegram.org/bot6866775472:AAEdyyIPrr43qHaiNzolzWlU_SJgSgjGwA8/sendMessage?chat_id=%d&text=%s", chat_id, strbuf.ptr);
            curl_easy_setopt(curl, CURLOPT_URL, telegram_api_url);
            res = curl_easy_perform(curl);

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
    }

    /* Limpiar el buffer de respuesta */
    string_buffer_finish(&strbuf);
  }

  /* Limpia el buffer */
  curl_easy_cleanup(curl);
  string_buffer_finish(&strbuf);
  return EXIT_SUCCESS;
}
