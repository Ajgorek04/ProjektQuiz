# Projekt Quiz - Edytor Pytań do Quizu

## Opis

Projekt jest edytorem pytań do quizu. Umożliwia zarządzanie pytaniami oraz kategoriami pytań w systemie. Pytania są przechowywane w plikach CSV, co ułatwia ich edycję i przechowywanie. Program pozwala na dodawanie, przeglądanie, usuwanie pytań, a także na dodawanie nowych kategorii.

## Funkcje

- **Dodawanie pytań**: Umożliwia dodanie nowego pytania, wraz z odpowiedziami i poprawną odpowiedzią. Można również przypisać pytanie do istniejącej kategorii.
- **Usuwanie pytań**: Umożliwia usunięcie pytania z bazy.
- **Przeglądanie pytań**: Wyświetlanie listy wszystkich pytań w systemie.
- **Zarządzanie kategoriami**: Dodawanie nowych kategorii oraz przeglądanie dostępnych kategorii.
- **Zapis i odczyt danych**: Dane (pytania i kategorie) są zapisywane w plikach CSV, co pozwala na łatwe zarządzanie danymi oraz ich późniejsze wykorzystanie.

## Instalacja

Aby uruchomić projekt na swoim komputerze, wystarczy wykonać poniższe kroki:

1. **Sklonuj repozytorium**:

   ```bash
   git clone https://github.com/TwojeRepozytorium/QuizEditor.git

   ```

2. ** Zbuduj projekt**:

   Jeśli używasz kompilatora C++, skorzystaj z poniższego polecenia:

   ```bash
   g++ -o quiz_editor main.cpp
   ```

3. **Uruchom program**:
   Po zbudowaniu programu uruchom go poleceniem:
   ```bash
   ./quiz_editor
   ```
   Struktura katalogów
   main.cpp - Główny plik programu z logiką edytora pytań.

../questions.csv - Plik, w którym przechowywane są pytania w formacie CSV.

../categories.csv - Plik, w którym przechowywane są kategorie pytań.

**Jak korzystać z programu?**
Po uruchomieniu programu, użytkownik ma do dyspozycji następujące opcje:

1. Przejrzyj aktualną listę pytań: Wyświetlenie wszystkich pytań zapisanych w systemie.

2. Dodaj nowe pytanie: Możliwość dodania nowego pytania do bazy, z odpowiedziami i kategorią.

3. Usuń pytanie: Usunięcie wybranego pytania z bazy.

4. Dodaj nową kategorię: Dodanie nowej kategorii pytań.

5. Przeglądaj kategorie: Wyświetlanie listy dostępnych kategorii.

Program zapisuje wszystkie dane w plikach CSV, dzięki czemu dane mogą być łatwo edytowane w edytorze tekstowym lub importowane do innych aplikacji.

**Przykład działania programu**:

```bash
========== EDYTOR PYTAN DO QUIZU ==========
1. Przejrzyj aktualną listę pytań
2. Dodaj nowe pytanie
3. Usuń pytanie
4. Dodaj nową kategorię
5. Przeglądaj kategorie
6. Zakończ program

Wybierz co chcesz zrobić: 1
Lista pytań:
1. Jakie jest stolica Polski?
A: Warszawa
B: Kraków
C: Poznań
D: Gniezno
Poprawna odpowiedź: A
Kategoria: Geografia
```
