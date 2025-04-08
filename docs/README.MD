# Gra Quizowa dla wielu graczy

## Spis Treści

1. [Opis Projektu](#opis-projektu)
2. [Tryby gry](#tryby-gry)
3. [Instalacja](#instalacja)
4. [Jak korzystać z programu?](#jak-korzystać-z-programu)
5. [Technologie](#technologie)
6. [Plik `databaseeditor`](#plik-databaseeditor)

## Opis Projektu

Gra quizowa, która umożliwia wielu graczom odpowiadanie na pytania z różnych kategorii. Gra jest oparta na plikach tekstowych, które mogą być łatwo rozszerzane przez użytkownika. Szczegółowy plan funkcjonalności gry, w tym tryby gry, struktura pytań, interfejs użytkownika oraz sposób rozbudowy bazy pytań, znajduje się w planie funkcjonalności.

## Tryby gry

- **Tryb solo**: Graj sam i sprawdź, jak dobrze znasz różne tematy.
- **Tryb wieloosobowy**: Graj z innymi graczami i porównaj swoje odpowiedzi.

## Instalacja

### Wymagania:

- Kompilator C++ (np. g++).
- Git do sklonowania repozytorium.

### Kroki Instalacyjne:

1. **Zainstaluj g++ (kompilator C++)**:

   - Na Windowsie:
     - Zainstaluj MinGW (zawiera g++) lub użyj MSYS2.
   - Na Linuxie i macOS:
     - Dla Ubuntu:
       ```bash
       sudo apt install g++
       ```
     - Dla macOS:
       ```bash
       brew install gcc
       ```

2. **Sklonuj repozytorium**:

   Jeśli masz zainstalowanego Git, sklonuj repozytorium na swoim komputerze:

   ```bash
   git clone https://github.com/Ajgorek04/ProjektQuiz.git
   ```

3. **Wejdź do katalogu z projektem**:

   Po sklonowaniu repozytorium, przejdź do katalogu projektu:

   ```bash
   cd ProjektQuiz
   ```

4. **Zbuduj projekt**:

   W katalogu `src`, uruchom poniższe polecenie, aby skompilować plik wykonywalny:

   - Na Windowsie:
     ```bash
     g++ -o quiz src/main.cpp src/gui.cpp src/editor.cpp src/logic.cpp
     ```
   - Na Linuxie/macOS:
     ```bash
     g++ -o quiz src/main.cpp src/gui.cpp src/editor.cpp src/logic.cpp
     ```

   To polecenie skompiluje plik wykonywalny o nazwie `quiz.exe` (na systemie Windows) lub `quiz` (na systemach Linux/macOS).

5. **Uruchom grę**:

   Po skompilowaniu programu, uruchom go za pomocą odpowiedniego polecenia:

   - Na Windowsie:
     ```bash
     .\quiz.exe
     ```
   - Na Linuxie/macOS:
     ```bash
     ./quiz
     ```

6. **Plik `databaseeditor`**:

   Aby edytować pytania i kategorie pytań w grze, możesz skorzystać z pliku `databaseeditor`, który znajduje się w folderze projektu. Ten plik umożliwia edytowanie danych quizu i jest kluczowy do modyfikacji pytań oraz kategorii.

## Jak korzystać z programu?

Po uruchomieniu gry użytkownik może:

- Wybrać tryb gry (solo lub wieloosobowy).
- Wybierać kategorię pytań.
- Odpowiadać na pytania.
- Na koniec uzyskać wynik.

## Technologie

- **C++**: Język programowania użyty do stworzenia gry.
- **CSV**: Format plików wykorzystywany do przechowywania danych pytań.

## Plik `databaseeditor`

Aby edytować pytania i kategorie pytań w grze, należy skorzystać z pliku `databaseeditor`, który znajduje się w folderze głównym projektu. Umożliwia on modyfikację bazy pytań i kategorii quizu.
