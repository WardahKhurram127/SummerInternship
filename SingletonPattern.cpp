#include <iostream>
#include <string>
using namespace std;

class Logger {
private:
    static Logger* instance; // static instance pointer
    string logLevel;

    // Private constructor to prevent external instantiation; only itself can create objects.
    Logger() {
        logLevel = "INFO";
    }

public:
    // Delete copy constructor and assignment operator
    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;

    // Static method to get the instance
    static Logger* getInstance() {
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    void setLogLevel(const string& level) {
        logLevel = level;
    }

    void log(const string& message) {
        cout << "[" << logLevel << "] " << message << endl;
    }
};

// Initialize the static member
Logger* Logger::instance = nullptr;

int main() {
    Logger* logger1 = Logger::getInstance();
    logger1->log("App started.");

    Logger* logger2 = Logger::getInstance();
    logger2->setLogLevel("DEBUG");
    logger2->log("Debugging application.");

    // Both logger1 and logger2 point to the same instance
    if (logger1 == logger2) {
        cout << "Same logger instance reused!" << endl;
    }
    else {
        cout << "Different logger instances. (This should NOT happen)" << endl;
    }

    return 0;
}


//Explanation:
//You ask for a logger using getInstance(). First time — it creates one.
//You use it to log a message.
//You call getInstance() again — but this time, it reuses the same object.
//You change the log level to "DEBUG".
//You log another message — it shows[DEBUG] now, because it's the same object.
//You compare the two pointers and print a message — and they point to the same object.