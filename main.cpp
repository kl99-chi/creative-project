//Keletso Ramothibe, 45541442
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip> // Added for setw

using namespace std;

// Defining a struct named Anime
struct Anime {
    string name;
    int year;
};

// Prototype functions
int readAnimeDataFromFile(string& fileName, Anime* animeArr, int SIZE);
void displayMostViewed(Anime* animeArr, int SIZE);
bool sortAnimeAlphabetically(Anime* animeArr, int SIZE);
void sortAnimeByYear(Anime* animeArr, int SIZE);
void writeToFile(string& fileName, Anime* animeArr, int SIZE);

int main() {
    int SIZE = 100;
    Anime* anime = new Anime[SIZE]; // Use dynamic allocation with pointers
    int animeCount = 0;
    string fileName = "animeList.txt";

    string name;
    cout << "Please enter your Username: ";
    cin >> name;

    cout << "\nWelcome back, " << name << ", to Ani-World\n" << endl;
    animeCount = readAnimeDataFromFile(fileName, anime, SIZE);
    cout << "Data import successful! " << animeCount << " record(s) added..." << endl;

    int password;
    cout << "Please enter your password: ";
    cin >> password;

    int temp = password;
    int sum = 0;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }

    if (sum % 7 == 0) {
        char End;
        int choice;
        do {
            cout << "Menu:\n 1. Display the most viewed Anime list\n 2. Display Anime alphabetically\n 3. Sort Anime by year\n 4. Update an anime from the list\n 5. Read manga\n 6. Logout" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    displayMostViewed(anime, animeCount);
                    break;
                case 2:
                    sortAnimeAlphabetically(anime, animeCount);
                    displayMostViewed(anime, animeCount);
                    break;
                case 3:
                    sortAnimeByYear(anime, animeCount);
                    displayMostViewed(anime, animeCount);
                    break;
                case 4: {
                    displayMostViewed(anime, animeCount);
                    cout << "Enter the index number of the anime you want to update: ";
                    int indexNum;
                    cin >> indexNum;

                    if (indexNum < 1 || indexNum > animeCount) {
                        cout << "Invalid index. Please enter a valid index." << endl;
                        break;
                    }

                    cout << "Enter new anime name for index " << indexNum << ": ";
                    cin.ignore();
                    string animeName;
                    getline(cin, animeName);

                    cout << "Enter the year of release for the anime: ";
                    int year;
                    cin >> year;

                    // Update the selected anime
                    anime[indexNum - 1].name = animeName;
                    anime[indexNum - 1].year = year;

                    displayMostViewed(anime, animeCount);
                } break;
                case 5: {
                    string manga;

                    displayMostViewed(anime, animeCount);

                    cout << "Which manga would you like to read: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, manga);

                    bool found = false;
                    for (int i = 0; i < animeCount; i++) {
                        if (anime[i].name == manga) {
                            found = true;
                            cout << "Great choice! You can read " << manga << "." << endl;
                            break;
                        }
                    }

                    if (!found) {
                        cout << "Sorry, the manga you entered is not in our list. Please select another manga in the list." << endl;
                    }
                } break;
                case 6:
                    cout << "Thank you for Subscribing with us...." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again!" << endl;
                    break;
            }

            cout << "\nDo you want to continue using the app (Y/N): ";
            cin >> End;

            if (End != 'y' && End != 'Y') {
                break;
            }
        } while ((End == 'y' || End == 'Y') && choice != 6);

        // Save changes to the file before exiting
        writeToFile(fileName, anime, animeCount);
    } else {
        cout << "Invalid password. Exiting..." << endl;
    }

    delete[] anime; // Free the allocated memory
    return 0;
}

int readAnimeDataFromFile(string& fileName, Anime* animeArr, int SIZE) {
    ifstream inputFile(fileName);
    int count = 0;

    if (inputFile.fail()) {
        cerr << "Error: Could not open file '" << fileName << "'." << endl;
        return -1; // Return -1 on error
    }

    string line;
    while (getline(inputFile, line)) {
        int pos1 = line.find(',');

        animeArr[count].name = line.substr(0, pos1);
        animeArr[count].year = stoi(line.substr(pos1 + 1));

        count++;

        if (count >= SIZE)
            break;
    }
    inputFile.close();
    return count;
}

void displayMostViewed(Anime* animeArr, int SIZE) {
    cout << "\nTop " << SIZE << " most viewed Anime of all time" << endl;
    cout << "\nName" << setw(20) << "Year" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << ". " << animeArr[i].name << setw(20) << animeArr[i].year << endl;
    }
}

bool sortAnimeAlphabetically(Anime* animeArr, int SIZE) {
    sort(animeArr, animeArr + SIZE, [](const Anime& a, const Anime& b) {
        return a.name < b.name;
    });
    displayMostViewed(animeArr, SIZE);
    return true; // Return true on success
}

void sortAnimeByYear(Anime* animeArr, int SIZE) {
    sort(animeArr, animeArr + SIZE, [](const Anime& a, const Anime& b) {
        return a.year < b.year;
    });
}

void writeToFile(string& fileName, Anime* animeArr, int SIZE) {
    ofstream outputFile(fileName);

    if (!outputFile) {
        cerr << "Error: Could not open file '" << fileName << "' for writing." << endl;
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        outputFile << animeArr[i].name << ", " << animeArr[i].year << endl;
    }

    outputFile.close();
}

