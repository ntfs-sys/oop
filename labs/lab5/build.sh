echo ""
echo "=== Генерация файла проекта ==="
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug

if [ $? -ne 0 ]; then
    echo "Ошибка CMake: не удалось сгенерировать файл проекта"
    exit 1
fi

echo "Файл проекта сгенерирован"

echo ""
echo "=== Сборка проекта ==="
make -j$(nproc)

if [ $? -ne 0 ]; then
    echo "Ошибка сборки"
    exit 1
fi

cd ..
echo "=== Сборка завершена ==="
