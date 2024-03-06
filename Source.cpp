#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void createNote(const string& fname)
{
    ofstream file(fname, ios::app);
    if (!file.is_open())
    {
        cerr << "Can't open file!\n";
        return;
    }

    string note;
    cout << "Enter new note: ";
    getline(cin, note);

    file << note << endl;
    file.close();
    cout << "Note successfully added!\n";
}
//h
void showNotes(const string& fname)
{
    ifstream file(fname);
    if (!file.is_open())
    {
        cerr << "Can't open file!\n";
        return;
    }

    string line;
    cout << "Notes in " << fname << " :\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

void deleteNoteByIndex(const string& fname, int index)
{
    ifstream file(fname);
    if (!file.is_open())
    {
        cerr << "Can't open file!\n";
        return;
    }

    vector<string> notes;
    string line;

    while (getline(file, line))
    {
        notes.push_back(line);
    }
    file.close();

    if (index < 0 || index >= notes.size())
    {
        cerr << "Invalid index!\n";
        return;
    }
    //comment
    notes.erase(notes.begin() + index);

    ofstream file2(fname);
    if (!file2.is_open())
    {
        cerr << "Can't open file!\n";
        return;
    }

    for (const string& note : notes)
    {
        file2 << note << endl;
    }
    file2.close();
    cout << "Note successfully deleted!\n";
}

int main()
{
    int choice;
    string fname, noteDel;
    int index;

    do
    {
        cout << "Choose an action:\n";
        cout << "1.Add note\n";
        cout << "2.Show notes\n";
        cout << "3.Delete note by index\n";
        cout << "4.Exit\n";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout << "Enter file name: ";
            getline(cin, fname);
            createNote(fname);
            break;

        case 2:
            cout << "Enter file name: ";
            getline(cin, fname);
            showNotes(fname);
            break;

        case 3:
            cout << "Enter file name: ";
            getline(cin, fname);
            cout << "Enter index of the note you want to delete: ";
            cin >> index;
            deleteNoteByIndex(fname, index);
            break;

        case 4:
            cout << "bye-bye\n";
            break;

        default:
            cout << "Invalid choice, try again :(\n";
        }

    } while (choice != 4);

    return 0;
}
