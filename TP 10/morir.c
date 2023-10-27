#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
    char *ptr;
    size_t len;
} string_buffer_t;

static size_t write_callback(void *ptr, size_t size, size_t nmemb, string_buffer_t *data) {
    size_t new_len = data->len + size * nmemb;
    data->ptr = realloc(data->ptr, new_len + 1);
    if (data->ptr == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return 0;
    }
    memcpy(data->ptr + data->len, ptr, size * nmemb);
    data->ptr[new_len] = '\0';
    data->len = new_len;
    return size * nmemb;
}

int main() {
    // URL de la NASA
    const char *nasa_url = "https://api.nasa.gov/mars-photos/api/v1/rovers/curiosity/photos?sol=1000&camera=fhaz&api_key=galEbCY2LUiHOaWbt9Mkwqy1JBhZc4sQvxkVDM1S";
    string_buffer_t nasa_response;
    nasa_response.ptr = NULL;
    nasa_response.len = 0;

    // Inicializar libcurl
    CURL *curl = curl_easy_init();
    if (curl) {
        // Configurar la URL de la NASA
        curl_easy_setopt(curl, CURLOPT_URL, nasa_url);

        // Configurar la función de escritura para capturar la respuesta
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &nasa_response);

        // Realizar la solicitud
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // La respuesta de la NASA se encuentra en nasa_response.ptr
            printf("NASA Response:\n%s\n", nasa_response.ptr);

            // URL de Telegram Bot
            const char *telegram_url = "https://api.telegram.org/botYOUR_BOT_TOKEN/getUpdates";
            CURL *curl_telegram = curl_easy_init();
            if (curl_telegram) {
                // Realizar la solicitud a Telegram para obtener las actualizaciones
                curl_easy_setopt(curl_telegram, CURLOPT_URL, telegram_url);

                string_buffer_t telegram_response;
                telegram_response.ptr = NULL;
                telegram_response.len = 0;

                // Configurar la función de escritura para capturar la respuesta de Telegram
                curl_easy_setopt(curl_telegram, CURLOPT_WRITEFUNCTION, write_callback);
                curl_easy_setopt(curl_telegram, CURLOPT_WRITEDATA, &telegram_response);

                // Realizar la solicitud a Telegram
                res = curl_easy_perform(curl_telegram);
                if (res == CURLE_OK) {
                    // Verificar si la respuesta de Telegram contiene la palabra "hola"
                    if (strstr(telegram_response.ptr, "hola") != NULL) {
                        // Enviar el mensaje de la API de la NASA a Telegram
                        const char *telegram_send_url = "https://api.telegram.org/bot6866775472:AAEdyyIPrr43qHaiNzolzWlU_SJgSgjGwA8/sendMessage";
                        CURL *curl_telegram_send = curl_easy_init();
                        if (curl_telegram_send) {
                            // Construir el mensaje para Telegram
                            char message[1000] = {0};
                            snprintf(message, sizeof(message), "chat_id=5032349360&text=%s", nasa_response.ptr);
                            curl_easy_setopt(curl_telegram_send, CURLOPT_POSTFIELDS, message);

                            // Configurar la URL de Telegram para enviar el mensaje
                            curl_easy_setopt(curl_telegram_send, CURLOPT_URL, telegram_send_url);

                            // Realizar la solicitud para enviar el mensaje a Telegram
                            res = curl_easy_perform(curl_telegram_send);
                            if (res != CURLE_OK) {
                                fprintf(stderr, "curl_easy_perform() failed for Telegram send: %s\n", curl_easy_strerror(res));
                            }

                            // Liberar recursos de la solicitud de Telegram para enviar el mensaje
                            curl_easy_cleanup(curl_telegram_send);
                        } else {
                            fprintf(stderr, "Failed to initialize libcurl for Telegram send.\n");
                        }
                    }
                } else {
                    fprintf(stderr, "curl_easy_perform() failed for Telegram: %s\n", curl_easy_strerror(res));
                }

                // Liberar recursos de la solicitud de Telegram
                curl_easy_cleanup(curl_telegram);

                // Liberar la memoria utilizada por la respuesta de Telegram
                if (telegram_response.ptr) {
                    free(telegram_response.ptr);
                }
            } else {
                fprintf(stderr, "Failed to initialize libcurl for Telegram.\n");
            }

            // Liberar la memoria utilizada por la respuesta de la NASA
            if (nasa_response.ptr) {
                free(nasa_response.ptr);
            }
        }

        // Liberar recursos
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize libcurl.\n");
    }

    return 0;
}
