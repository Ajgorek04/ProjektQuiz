# Gra Quizowa dla wielu graczy

## Opis

Gra quizowa, która umożliwia wielu graczom odpowiadanie na pytania z różnych kategorii. Gra jest oparta na plikach tekstowych, które mogą być łatwo rozszerzane przez użytkownika.

Szczegółowy plan funkcjonalności gry, w tym tryby gry, struktura pytań, interfejs użytkownika oraz sposób rozbudowy bazy pytań, znajduje się w [planie funkcjonalności](https://github.com/Ajgorek04/ProjektQuiz/blob/main/docs/plan_funkcjonalnosci.md).

## Tryby gry

- **Tryb solo**: Graj sam i sprawdź, jak dobrze znasz różne tematy.
- **Tryb wieloosobowy**: Graj z innymi graczami i porównaj swoje odpowiedzi.

## Instalacja

1. **Zainstaluj `g++`** (kompilator C++). Możesz zainstalować go na różne sposoby, w zależności od systemu:

   - Na **Windowsie**: Zainstaluj **MinGW** (zawiera `g++`) lub użyj **MSYS2**.
   - Na **Linuxie** i **macOS**: Zainstaluj `g++` za pomocą menedżera pakietów:
     - Dla Ubuntu: `sudo apt install g++`
     - Dla macOS: `brew install gcc`

2. **Sklonuj repozytorium**: Jeśli masz zainstalowanego Git, sklonuj repozytorium na swoim komputerze. Użyj polecenia:  
   `git clone https://github.com/Ajgorek04/ProjektQuiz.git`

3. **Wejdź do katalogu z projektem**: Po sklonowaniu repozytorium, przejdź do katalogu projektu, używając następującego polecenia:  
   `cd ProjektQuiz`

4. **Zbuduj projekt**: W katalogu `src`, uruchom poniższe polecenie, aby skompilować plik wykonywalny:

   - Na **Windowsie**:  
     `g++ -o quiz src/main.cpp src/gui.cpp src/editor.cpp src/logic.cpp`
   - Na **Linuxie/macOS**:  
     `g++ -o quiz src/main.cpp src/gui.cpp src/editor.cpp src/logic.cpp`

   To polecenie skompiluje plik wykonywalny o nazwie `quiz.exe` (na systemie Windows) lub `quiz` (na systemach Linux/macOS).

5. **Uruchom grę**: Po skompilowaniu programu, uruchom go za pomocą odpowiedniego polecenia:

   - Na **Windowsie**:  
     `.\quiz.exe`
   - Na **Linuxie/macOS**:  
     `./quiz`

6. **Rozpocznij grę**: Po uruchomieniu gry, wybierz:
   - **Tryb gry** (solo lub wieloosobowy),
   - **Kategoria pytań**,
   - **Odpowiedzi na pytania**,
   - **Na koniec uzyskasz wynik**.
