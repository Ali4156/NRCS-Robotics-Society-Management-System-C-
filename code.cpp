#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Member {
public:
    string name;
    string position;

    Member(string n, string p) {
        name = n;
        position = p;
    }

    void display() const {
        cout << "Name: " << name << " | Position: " << position << endl;
    }
};

class Department {
private:
    string deptName;
    string headName;
    string headDuties;
    vector<Member> members;

public:
    Department(string name, string head, string duties) {
        deptName = name;
        headName = head;
        headDuties = duties;
    }

    void addMember(string name) {
        members.push_back(Member(name, "Member"));
    }

    void displayDepartment() const {
        cout << "\n========== " << deptName << " Department ==========\n";
        cout << "Head: " << headName << endl;
        cout << "Duties: " << headDuties << endl;

        cout << "\nMembers:\n";
        for (const auto& m : members) {
            m.display();
        }
    }
};

class Event {
public:
    string eventName;
    string eventDate;
    string eventType;

    Event(string name, string date, string type) {
        eventName = name;
        eventDate = date;
        eventType = type;
    }

    void display() const {
        cout << "Event: " << eventName
            << " | Date: " << eventDate
            << " | Type: " << eventType << endl;
    }
};

class Society {
private:
    string societyName;
    string managementHead;
    string managementDuties;
    vector<Member> coreTeam;
    vector<Department> departments;
    vector<Event> events;

public:
    Society(string name, string head, string duties) {
        societyName = name;
        managementHead = head;
        managementDuties = duties;
    }

    void addCoreMember(string name) {
        coreTeam.push_back(Member(name, "Core Member"));
    }

    void addDepartment(Department dept) {
        departments.push_back(dept);
    }

    void addEvent(string name, string date, string type) {
        events.push_back(Event(name, date, type));
    }

    void displaySociety() const {
        cout << "\n=========================================\n";
        cout << "        " << societyName << endl;
        cout << "=========================================\n";

        cout << "\nManagement Head: " << managementHead << endl;
        cout << "Duties: " << managementDuties << endl;

        cout << "\n------ Core Team Members ------\n";
        for (const auto& m : coreTeam) {
            m.display();
        }

        for (const auto& d : departments) {
            d.displayDepartment();
        }

        cout << "\n========== Organized Events ==========\n";
        for (const auto& e : events) {
            e.display();
        }
    }
};

int main() {

    Society nrcs(
        "NRCS - Robotics Society (Riphah International University)",
        "Ali - Management Head",
        "Oversees overall society operations, strategic planning, "
        "inter-department coordination, and event supervision."
    );

    // Core Team (7 Members)
    nrcs.addCoreMember("Ahmed");
    nrcs.addCoreMember("Bilal");
    nrcs.addCoreMember("Hassan");
    nrcs.addCoreMember("Usman");
    nrcs.addCoreMember("Hamza");
    nrcs.addCoreMember("Zain");
    nrcs.addCoreMember("Saad");

    // Tech Department
    Department tech(
        "Tech",
        "Omar - Tech Head",
        "Responsible for robotics development, programming, "
        "technical workshops, and competition preparation."
    );

    tech.addMember("Ali Raza");
    tech.addMember("Mubashir");
    tech.addMember("Taha");

    // Media Department
    Department media(
        "Media",
        "Haris - Media Head",
        "Handles social media management, event promotions, "
        "graphic design, and photography."
    );

    media.addMember("Ayesha");
    media.addMember("Fatima");

    // Documentation Department
    Department documentation(
        "Documentation",
        "Sufyan - Documentation Head",
        "Manages reports, event documentation, sponsorship proposals, "
        "and official record keeping."
    );

    documentation.addMember("Hammad");
    documentation.addMember("Ibrahim");

    // Add Departments
    nrcs.addDepartment(tech);
    nrcs.addDepartment(media);
    nrcs.addDepartment(documentation);

    // Events
    nrcs.addEvent("Robotics Seminar 2026", "15 March 2026", "Seminar");
    nrcs.addEvent("AI & Automation Workshop", "20 April 2026", "Workshop");
    nrcs.addEvent("National Robotics Competition", "10 June 2026", "Competition");

    nrcs.displaySociety();

    return 0;
}