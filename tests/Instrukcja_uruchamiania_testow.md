# Testy jednostkowe - ProjektQuiz

Ten projekt zawiera testy jednostkowe dla klasy `Question`, napisane w oparciu o framework **Qt Test**.

## 🔧 Kompilacja i uruchamianie testów

Poniżej znajdują się kroki, które należy wykonać, aby skompilować i uruchomić testy:

### 1. Przejdź do folderu z testami

```bash
cd ProjektQuiz/tests
```

Usuń folder build, jeśli istnieje

```bash
rm -r build
```

Utwórz nowy folder build

```bash
mkdir build
```

Przejdź do nowo utworzonego folderu

```bash
cd build
```

Wygeneruj pliki Makefile za pomocą CMake

```bash
cmake -G "MinGW Makefiles" ..
```

Skompiluj projekt

```bash
mingw32-make
```

Uruchom testy

```bash
./tests.exe
```
