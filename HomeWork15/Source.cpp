#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Worker {
public:
    string name;
    string surname;
    int birth_year;

    Worker(string name, string surname, int birth_year) :
        name(name), surname(surname), birth_year(birth_year) {}
};

class Group {
public:
    string name;
    vector<Worker> workers;

    Group(string name) : name(name) {}

    bool WorkersBornAfter1974() {
        for (auto& worker : workers) {
            if (worker.birth_year <= 1974) {
                return false;
            }
        }
        return true;
    }
};

void main() {
    int num_groups;
    cout << "Enter numder groups: ";
    cin >> num_groups;
    cout << endl;

    vector<Group> groups;
    for (int i = 0; i < num_groups; i++) {
        string group_name;
        int num_workers;
        cout << "Enter name group and number workers: ";
        cin >> group_name >> num_workers;
        cout << endl;
        Group group(group_name);
        for (int j = 0; j < num_workers; j++) {
           string name, surname;
            int birth_year;
            cout << "Enter name worker, surnsme and birth year: ";
            cin >> name >> surname >> birth_year;
            cout << endl;

            group.workers.emplace_back(name, surname, birth_year);
        }

        groups.push_back(group);
    }

    bool found = false;
    for (auto& group : groups) {
        if (group.WorkersBornAfter1974()) {
            cout << group.name << std::endl;
            found = true;
        }
    }

    if (!found) {
       cout << "Not found!" << std::endl;
    }


}