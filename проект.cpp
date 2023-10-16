#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;


struct Song {
    string title;
    string artist;
    int year;
    string lyrics;
};

vector<Song> catalog;

void addSong() {
    setlocale(LC_ALL, "Rus");
    Song newSong;
    cout << "Введите название песни: ";
    getline(cin, newSong.title);
    cout << "Введите автора песни: ";
    getline(cin, newSong.artist);
    cout << "Введите год создания песни: ";
    cin >> newSong.year;
    cin.ignore();
    cout << "Введите текст песни: ";
    getline(cin, newSong.lyrics);
    catalog.push_back(newSong);
    cout << "Песня успешно добавлена!" << endl;
}

void removeSong() {

    setlocale(LC_ALL, "Rus");
    string searchArtist;
    cout << "Введите имя автора для удаления песен: ";
    getline(cin, searchArtist);
    bool found = false;
    for (auto it = catalog.begin(); it != catalog.end(); ) {
        if (it->artist == searchArtist) {
            it = catalog.erase(it);
            found = true;
        }
        else {
            ++it;
        }
    }
    if (found) {
        cout << "Песни успешно удалены!" << endl;
    }
    else {
        cout << "Песни данного автора не найдены!" << endl;
    }
}

void editSong() {

    setlocale(LC_ALL, "Rus");
    string searchArtist;
    string searchTitle;
    cout << "Введите имя автора песни: ";
    getline(cin, searchArtist);
    cout << "Введите название песни: ";
    getline(cin, searchTitle);
    bool found = false;
    for (auto& song : catalog) {
        if (song.artist == searchArtist && song.title == searchTitle) {
            cout << "Введите новый текст песни: ";
            getline(cin, song.lyrics);
            cout << "Песня успешно изменена!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Песня не найдена!" << endl;
    }
}

void displayAllSongs() {

    setlocale(LC_ALL, "Rus");
    if (catalog.empty()) {
        cout << "Каталог песен пуст!" << endl;
    }
    else {
        for (const auto& song : catalog) {
            cout << "Название песни: " << song.title << endl;
            cout << "Автор песни: " << song.artist << endl;
            cout << "Год создания песни: " << song.year << endl;
            cout << "Текст песни: " << song.lyrics << endl;
            cout << endl;
        }
    }
}

void saveToFile() {

    setlocale(LC_ALL, "Rus");
    ofstream file("catalog.txt");
    for (const auto& song : catalog) {
        file << "Название песни: " << song.title << endl;
        file << "Автор песни: " << song.artist << endl;
        file << "Год создания песни: " << song.year << endl;
        file << "Текст песни: " << song.lyrics << endl;
        file << endl;
    }
    file.close();
    cout << "Каталог песен успешно сохранен в файл!" << endl;
}

void searchByArtist() {

    setlocale(LC_ALL, "Rus");
    string searchArtist;
    cout << "Введите имя автора для поиска песен: ";
    getline(cin, searchArtist);
    bool found = false;
    for (const auto& song : catalog) {
        if (song.artist == searchArtist) {
            cout << "Название песни: " << song.title << endl;
            cout << "Автор песни: " << song.artist << endl;
            cout << "Год создания песни: " << song.year << endl;
            cout << "Текст песни: " << song.lyrics << endl;
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Песни данного автора не найдены!" << endl;
    }
}

void searchByWord() {

    setlocale(LC_ALL, "Rus");
    string searchWord;
    cout << "Введите слово для поиска песен: ";
    getline(cin, searchWord);
    bool found = false;
    for (const auto& song : catalog) {
        if (song.lyrics.find(searchWord) != string::npos) {
            cout << "Название песни: " << song.title << endl;
            cout << "Автор песни: " << song.artist << endl;
            cout << "Год создания песни: " << song.year << endl;
            cout << "Текст песни: " << song.lyrics << endl;
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Песни со словом \"" << searchWord << "\" не найдены!" << endl;
    }
}

int main() {

    setlocale(LC_ALL, "Rus");
    int choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Добавление текста песни" << endl;
        cout << "2. Удаление текста песни" << endl;
        cout << "3. Изменение текста песни" << endl;
        cout << "4. Отображение текста песни на экран" << endl;
        cout << "5. Сохранение текста песни в файл" << endl;
        cout << "6. Поиск и отображение всех песен одного автора" << endl;
        cout
            << "7. Поиск и отображение всех песен, содержащих слово" << endl;
        cout << "8. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addSong();
            break;
        case 2:
            removeSong();
            break;
        case 3:
            editSong();
            break;
        case 4:
            displayAllSongs();
            break;
        case 5:
            saveToFile();
            break;
        case 6:
            searchByArtist();
            break;
        case 7:
            searchByWord();
            break;
        case 8:
            cout << "Программа завершена." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }
    } while (choice != 8);

    return 0;
}