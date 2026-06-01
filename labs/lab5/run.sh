#!/bin/bash

echo "Поиск собранных файлов..."
mapfile -t files < <(find . -type f -name "lab*")

if [ ${#files[@]} -eq 0 ]; then
    echo "Исполняемые файлы не найдены."
    exit 1
fi

echo "Выберите программу для запуска:"
PS3="Введите номер (или 'q' для выхода): "

select file in "${files[@]}"; do
    if [ -n "$file" ]; then
        echo "--- Запуск $file ---"

        "$file"
        break
    elif [ "$REPLY" = "q" ]; then
        echo "Выход."
        exit 0
    else
        echo "Некорректный выбор."
    fi
done
