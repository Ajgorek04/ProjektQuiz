#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include <limits>
#include <algorithm> // Dla std::transform

using namespace std;

class Question {
public:
    string question;
    string answerA;
    string answerB;
    string answerC;
    string answerD;
    char correctAnswer;
    string category;

    // Konstruktor
    Question(string q, string a, string b, string c, string d, char correct, string cat)
        : question(q), answerA(a), answerB(b), answerC(c), answerD(d), correctAnswer(correct), category(cat) {}

    // Funkcja do zapisywania pytania w formacie CSV
    string toCSV() const {
        stringstream ss;
        ss << question << ";" << answerA << ";" << answerB << ";" << answerC << ";" << answerD << ";" << correctAnswer << ";" << category;
        return ss.str();
    }

    // Funkcja do wczytywania pytania z pliku CSV
    static Question fromCSV(const string& line) {
        stringstream ss(line);
        string q, a, b, c, d, cat;
        char correct;
        
        getline(ss, q, ';');
        getline(ss, a, ';');
        getline(ss, b, ';');
        getline(ss, c, ';');
        getline(ss, d, ';');
        ss >> correct;
        ss.ignore(1);  // Ignorujemy średnik po poprawnej odpowiedzi
        getline(ss, cat);
        
        return Question(q, a, b, c, d, correct, cat);
    }
};

// Funkcja do konwersji kategorii na małe litery
string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void showQuestions(const vector<Question>& questions);
void saveQuestions(const vector<Question>& questions);
void addQuestions(vector<Question>& questions, set<string>& categories);
bool isValidAnswer(char answer);
void loadQuestions(vector<Question>& questions);
void loadCategories(set<string>& categories);
bool isValidCategory(const string& category, const set<string>& categories);
void showCategories(const set<string>& categories);
void addCategory(set<string>& categories);
void saveCategories(const set<string>& categories);
void removeQuestion(vector<Question>& questions);

int main() {
    vector<Question> questions; // Lista pytań
    set<string> categories;  // Początkowe kategorie

    // Wczytywanie pytań i kategorii z plików
    loadQuestions(questions);
    loadCategories(categories);

    string option;

    do {
        // Menu
        cout << "\n========== EDYTOR PYTAN DO QUIZU ==========\n\n";
        cout << "1. Przejrzyj aktualna liste pytan \n";
        cout << "2. Dodaj nowe pytanie \n";
        cout << "3. Usun pytanie \n";
        cout << "4. Dodaj nowa kategorie \n";
        cout << "5. Przegladaj kategorie \n"; // Opcja przeglądania kategorii
        cout << "6. Zakoncz program \n\n";

        // Wczytywanie wyboru
        cout << "Wybierz co chcesz zrobic: ";
        cin >> option;
        cout << '\n';

        // Sprawdzenie, czy wprowadzona opcja jest poprawna
        if (option == "1") {
            cout << "Lista pytan:\n";
            showQuestions(questions);
        } else if (option == "2") {
            cout << "Wybrano opcje 2 - Dodawanie pytania\n";
            addQuestions(questions, categories);
        } else if (option == "3") {
            cout << "Wybrano opcje 3 - Usuwanie pytania\n";
            removeQuestion(questions);
        } else if (option == "4") {
            cout << "Wybrano opcje 4 - Dodawanie nowej kategorii\n";
            addCategory(categories);
        } else if (option == "5") {
            cout << "Wybrano opcje 5 - Przegladanie kategorii\n";
            showCategories(categories); // Wywołanie funkcji do przeglądania kategorii
        } else if (option == "6") {
            cout << "Zakonczenie programu\n";
            saveQuestions(questions);  // Zapis pytań
            saveCategories(categories); // Zapis kategorii
            return 0;
        } else {
            cout <<"\n";
            cout <<"Niepoprawna opcja. Sprobuj ponownie\n\n";
        }
    } while (option != "6"); // Petla będzie trwala, dopoki uzytkownik nie wybierze opcji "6"
}

// Funkcja do wyświetlania pytań
void showQuestions(const vector<Question>& questions) {
    int questionNumber = 1;

    if (questions.empty()) {
        cout << "Brak pytan.\n";
        return;
    }

    for (const auto& question : questions) {
        cout << questionNumber << ". " << question.question << '\n';
        cout << "A: " << question.answerA << '\n';
        cout << "B: " << question.answerB << '\n';
        cout << "C: " << question.answerC << '\n';
        cout << "D: " << question.answerD << '\n';
        cout << "Poprawna odpowiedz: " << question.correctAnswer << '\n';
        cout << "Kategoria: " << question.category << '\n';
        cout << endl;
        questionNumber++;
    }
}
// Funkcja do zapisywania pytań do pliku CSV
void saveQuestions(const vector<Question>& questions) {
    ofstream questionsFile("../questions.csv");

    if (questionsFile.is_open()) {
        for (const auto& q : questions) {
            questionsFile << q.toCSV() << '\n'; // Zapisujemy pytanie w formacie CSV
        }
        questionsFile.close();  // Zamykanie pliku po zapisaniu wszystkich pytań
    } else {
        cout << "Nie moge otworzyc pliku.\n";
    }
}
// Funkcja do zapisywania kategorii do pliku
void saveCategories(const set<string>& categories) {
    ofstream categoriesFile("../categories.csv");

    if (categoriesFile.is_open()) {
        for (const auto& cat : categories) {
            categoriesFile << cat << '\n'; // Zapisujemy kategorię
        }
        categoriesFile.close();  // Zamykanie pliku po zapisaniu wszystkich kategorii
    } else {
        cout << "Nie moge otworzyc pliku kategorii.\n";
    }
}
// Funkcja do wczytywania pytań z pliku
void loadQuestions(vector<Question>& questions) {
    ifstream questionsFile("../Qt/QuizGame/questions.csv");
    string line;

    if (questionsFile.is_open()) {
        while (getline(questionsFile, line)) {
            questions.push_back(Question::fromCSV(line));  // Wczytujemy każde pytanie
        }
        questionsFile.close();
    } else {
        cout << "Nie moge otworzyc pliku. Rozpoczynamy nowa baze danych pytan.\n";
    }
}
// Funkcja do wczytywania kategorii z pliku
void loadCategories(set<string>& categories) {
    ifstream categoriesFile("../Qt/QuizGame/categories.csv");
    string line;

    if (categoriesFile.is_open()) {
        while (getline(categoriesFile, line)) {
            categories.insert(line);  // Wczytujemy kategorię
        }
        categoriesFile.close();
    } else {
        cout << "Nie moge otworzyc pliku kategorii. Rozpoczynamy z domyslnymi kategoriami.\n";
        categories = {"Historia", "Geografia", "Nauka", "Sport", "Kultura"};  // Domyślne kategorie
    }
}
// Funkcja walidująca poprawną odpowiedź
bool isValidAnswer(char answer) {
    answer = toupper(answer);
    return (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D');
}
// Funkcja wyświetlająca dostępne kategorie
void showCategories(const set<string>& categories) {
    int index = 1;
    for (const auto& category : categories) {
        cout << index++ << ". " << category << '\n';
    }
}
// Funkcja walidująca poprawność kategorii
bool isValidCategory(const string& category, const set<string>& categories) {
    string lowerCategory = toLowerCase(category);  // Konwertujemy kategorię na małe litery
    for (const auto& cat : categories) {
        if (toLowerCase(cat) == lowerCategory) {  // Sprawdzamy, czy kategoria istnieje, ignorując wielkość liter
            return true;
        }
    }
    return false;
}
void addQuestions(vector<Question>& questions, set<string>& categories) {
    cin.ignore();
    string q, a, b, c, d;
    char correct;

    cout << "\nWybierz kategorie dla nowego pytania:\n";

    vector<string> categoryList(categories.begin(), categories.end());  // Konwersja zbioru na wektor (żeby móc wybrać po numerze)

    for (size_t i = 0; i < categoryList.size(); ++i) {
        cout << i + 1 << ". " << categoryList[i] << '\n';
    }

    int categoryChoice;
    do {
        cout << "Wpisz numer kategorii (1-" << categoryList.size() << "): ";
        cin >> categoryChoice;
        if (cin.fail() || categoryChoice < 1 || categoryChoice > (int)categoryList.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Niepoprawny numer. Sprobuj ponownie.\n";
            categoryChoice = -1;
        }
    } while (categoryChoice == -1);

    string selectedCategory = categoryList[categoryChoice - 1];

    cin.ignore(); // czyszczenie bufora po wpisaniu numeru

    cout << "Podaj tresc pytania: ";
    getline(cin, q);

    cout << "Podaj odpowiedz A: ";
    getline(cin, a);
    cout << "Podaj odpowiedz B: ";
    getline(cin, b);
    cout << "Podaj odpowiedz C: ";
    getline(cin, c);
    cout << "Podaj odpowiedz D: ";
    getline(cin, d);

    do {
        cout << "Podaj poprawna odpowiedz (A, B, C, D): ";
        cin >> correct;
        correct = toupper(correct);
    } while (!isValidAnswer(correct));

    Question newQuestion(q, a, b, c, d, correct, selectedCategory);
    questions.push_back(newQuestion);

    cout << "Pytanie dodane!\n";
}

// Funkcja do dodawania nowej kategorii
void addCategory(set<string>& categories) {
    string newCategory;
    cin.ignore();
    cout << "Podaj nowa kategorie: ";
    getline(cin, newCategory);

    string lowerCategory = toLowerCase(newCategory);  // Konwertujemy na małe litery

    // Dodajemy kategorię tylko jeśli jeszcze jej nie ma
    bool categoryExists = false;
    for (const auto& cat : categories) {
        if (toLowerCase(cat) == lowerCategory) {
            categoryExists = true;
            break;
        }
    }

    if (!categoryExists) {
        categories.insert(newCategory);  // Dodajemy oryginalną kategorię
        cout << "Kategoria dodana!\n";
        saveCategories(categories);  // Zapisujemy zmienione kategorie
    } else {
        cout << "Taka kategoria juz istnieje.\n";
    }
}

void removeQuestion(vector<Question>& questions) {
    if (questions.empty()) {
        cout << "Brak pytan do usuniecia.\n";
        return;
    }

    cout << "Aktualna lista pytan:\n";
    for (size_t i = 0; i < questions.size(); ++i) {
        cout << i + 1 << ". " << questions[i].question << '\n';
    }

    cout << "\nPodaj numer pytania do usuniecia (1 - " << questions.size() << "): ";
    size_t index;
    cin >> index;

    if (cin.fail() || index < 1 || index > questions.size()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Niepoprawny numer pytania.\n";
        return;
    }

    string deleted = questions[index - 1].question;
    questions.erase(questions.begin() + index - 1);
    cout << "Usunieto pytanie: \"" << deleted << "\"\n";

    saveQuestions(questions);
}