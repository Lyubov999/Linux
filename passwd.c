#include <stdio.h>
#include <string.h>

int main() {
    char login[50];
    printf("Введите логин пользователя: ");
    scanf("%s", login);

    FILE *fp = fopen("/etc/passwd", "r");
    if (fp == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, ":");
        if (token != NULL && strcmp(token, login) == 0) {
            token = strtok(NULL, ":");  // пароль
            token = strtok(NULL, ":");  // UID
            token = strtok(NULL, ":");  // GID
            token = strtok(NULL, ":");  // имя
            printf("Пользователь с логином %s имеет имя: %s\n", login, token);
            fclose(fp);
            return 0;
        }
    }

    printf("Пользователь с логином %s не найден\n", login);
    fclose(fp);
    return 0;
}
