#include <iostream>
#include <string>
#include <map>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cctype>

using namespace std;


void slowPrint(const string& text, int delay = 30) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

string getToasterName() {
    vector<string> names = {
        "Crumbsworth the Third", "Toastifer", "Sir Sizzle",
        "Burnadette", "Crustina", "The Bread Baron",
        "Toasty McToastface"
    };
    srand(time(0));
    return names[rand() % names.size()];
}

void showHelp() {
    cout << "Welcome to CrumbChronicles!\n";
    cout << "You are being interviewed by a sentient toaster.\n";
    cout << "Answer questions wisely and trigger Easter eggs for bonus points!\n";
    cout << "Type 'butter', 'bagel', 'jam', or 'crust' to unlock special endings.\n";
    cout << "Good luck, Crumb Aspirant!\n";
}


void showToastArt() {
    cout << R"(
     ________
    /        \
   /  TOAST!  \
   \  ~~~~~~  /
    \________/
    ( )    ( )
     ||    ||
     ||    ||
     ^^    ^^
    )" << endl;
}

void showAvocadoArt() {
    cout << R"(
    _________
   /         \
  /  AVOCADO  \
  \   AWAITS   /
   \__________/
       |||
     __|||__
    (_______)
   )" << endl;
}

void showBagelArt() {
    cout << R"(
     .-"""-.
    /       \
   |         |
   |  BAGEL  |
   |         |
    \       /
     '-...-'
       |||
     __|||__
    (_______)
   )" << endl;
}

void showPancakeArt() {
    cout << R"(
      _______
     /       \
    /  PANCAKE  \
   |  FLUFFY!   |
   \___________/
       ||
      __||
     (____)
    )" << endl;
}

void showButterRealmArt() {
    cout << R"(
    _______________
   |               |
   |   BUTTER      |
   |   REALM       |
   |_______________|
        |||
      __|||__
     (_______)
   )" << endl;
}

void showGoldenToastArt() {
    cout << R"(
       _________
      /         \
     /  GOLDEN   \
    |   TOAST!   |
    |   PERFECT  |
     \___________/
        |||
      __|||__
     (_______)
   )" << endl;
}

void showCrustArt() {
    cout << R"(
      ________
     /        \
    /  CRUST!  \
    \  KINGDOM /
     \________/
        |||
      __|||__
     (_______)
   )" << endl;
}





void saveToLeaderboard(const string& playerName, const string& outcome) {
    ofstream file("CrumbLeaderboard.txt", ios::app); // Ensure reliable file saving
    if (file.is_open()) {
        file << playerName << " - " << outcome << endl;
        file.close();
    }
}

void checkAchievements(int score) {
    if (score == 3) {
        slowPrint("Achievement Unlocked: Golden Toast! 🏆");
    }
    else if (score == 0) {
        slowPrint("Achievement Unlocked: Crust King! 👑");
    }
}


string checkEasterEgg(const string& input, bool& triggered) {
    if (input == "butter") {
        triggered = true;
        return "butter";
    } else if (input == "bagel") {
        triggered = true;
        return "bagel";
    } else if (input == "jam") {
        triggered = true;
        return "jam";
    } else if (input == "crust") {
        triggered = true;
        return "crust";
    } else if (input == "avocado") {
        triggered = true;
        return "avocado";
    } else if (input == "marmalade") {
        triggered = true;
        return "marmalade";
    } else if (input == "pancake") {
        triggered = true;
        return "pancake";
    }
    return "";
}

int askQuestion(const string& question, const map<char, string>& options, bool& specialTrigger, string& specialType) {
    slowPrint("\n" + question);
    for (const auto& pair : options) { // C++11-friendly loop
        char key = pair.first;
        string text = pair.second;
        cout << "  [" << key << "] " << text << endl;
    }

    string input;
    while (true) {
        cout << "> ";
        cin >> input;

        string egg = checkEasterEgg(input, specialTrigger);
        if (!egg.empty()) {
            specialType = egg;
            return -1;
        }

        if (input.length() == 1) {
            char choice = tolower(input[0]);
            if (options.find(choice) != options.end()) {
                return choice;
            }
        }
        cout << "Toaster: Invalid input. Try again, crispyhead." << endl;
    }
}

int main() {
    slowPrint("✨ Welcome to the Interview With A Sentient Toaster™ ✨");
    cout << "Type 'help' for game instructions or press Enter to continue.\n";

    string command;
    getline(cin, command);

    if (command == "help") {
        showHelp();
        cout << "Press Enter to start the game.\n";
        getline(cin, command);  // ✅ This safely waits for Enter
    }

    cout << "Enter your name, Crumb Aspirant: ";
    string playerName;
    getline(cin, playerName);

    string toasterName = getToasterName();
    slowPrint("You enter a room. There's a toaster on a throne made of breadsticks.");
    slowPrint("Toaster: Greetings, I am " + toasterName + ". Let’s see if you're worthy of the Crumb Kingdom.");

    int score = 0;
    bool specialTrigger = false;
    string specialType;

    // Declare variables upfront to avoid goto skipping initialization
    int q1 = 0, q2 = 0, q3 = 0;

    q1 = askQuestion("What is your greatest strength?",
        {{'a', "I never burn under pressure."},
         {'b', "I'm great at loafing around."},
         {'c', "I talk to appliances daily."}}, specialTrigger, specialType);
    if (specialTrigger) goto ending;
    score += (q1 == 'a') ? 1 : 0;

    q2 = askQuestion("What do you do when someone steals your toast?",
        {{'a', "Toast them back."},
         {'b', "Offer jam and befriend them."},
         {'c', "Cry in a toaster slot."}}, specialTrigger, specialType);
    if (specialTrigger) goto ending;
    score += (q2 == 'b') ? 1 : 0;

    q3 = askQuestion("Final question: Why do you want this job?",
        {{'a', "I knead the dough."},
         {'b', "To rise to the occasion."},
         {'c', "You’re the only one who gets me."}}, specialTrigger, specialType);
    if (specialTrigger) goto ending;
    score += (q3 == 'c') ? 1 : 0;

ending:
    slowPrint("\n" + toasterName + " is calculating your results...");
    this_thread::sleep_for(chrono::seconds(2));
    string outcome;

    if (specialTrigger) {
        if (specialType == "butter") {
            slowPrint(toasterName + ": You said the sacred word... 'butter'.");
            slowPrint("A portal opens. You are whisked away to the secret Butter Realm. 🍯");
            outcome = "Supreme Spreadmaster (Butter Ending)";
            showButterRealmArt();
        } else if (specialType == "bagel") {
            slowPrint(toasterName + ": You've opened the Bagelverse! All is round now.");
            outcome = "Bagel King/Queen";
            showBagelArt();
        } else if (specialType == "jam") {
            slowPrint(toasterName + ": You are now the Ambassador of Jam. 🍓");
            outcome = "Jam Diplomat";
        } else if (specialType == "crust") {
            slowPrint(toasterName + ": Crust Council welcomes you, wise one.");
            outcome = "Crust Council Member";
            showCrustArt();
        }
    }
    else if (score == 3) {
        slowPrint(toasterName + ": Impeccable. You’re golden-brown perfection.");
        outcome = "Senior Crumb Strategist";
        showGoldenToastArt();
    }
    else if (score == 2) {
        slowPrint(toasterName + ": Not bad, a bit underdone, but acceptable.");
        outcome = "Junior Crumb Collector";
        showToastArt();
    }
    else if (score == 1) {
        slowPrint(toasterName + ": Mediocre. You are now on butter-duty. Forever.");
        outcome = "Butter Duty";
        showButterRealmArt();
    }
    else {
        slowPrint(toasterName + ": Burnt beyond recognition. Into the Crumb Chasm you go.");
        outcome = "Crisped and Banished";
        showCrustArt();
    }

    // Save score
    saveToLeaderboard(playerName, outcome);

    checkAchievements(score);

    // Toast Art
    showToastArt();

    slowPrint("\nThanks for playing, " + playerName + "! 🍽️");

    return 0;
}
